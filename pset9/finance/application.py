import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session['user_id']
    # Get all the stocks the user owns
    stocks = db.execute('''SELECT stock_symbol, shares_number
                           FROM shares
                           WHERE user_id = ? AND shares_number != 0;''', user_id
                       )

    # Make a list with all needed info. about each stock
    user_stocks = []
    stocks_total = 0
    for stock in stocks:

        stock_data = lookup(stock['stock_symbol'])
        stock_total = stock['shares_number'] * stock_data['price']

        user_stocks.append({
            'symbol': stock_data['symbol'],
            'name': stock_data['name'],
            'price': usd(stock_data['price']),
            'shares': stock['shares_number'],
            'total': usd(stock_total)
        })

        # Calculate the total current worth for all owned stocks
        stocks_total += stock_total

    # Query database for user's current cash amount
    cash = db.execute('''SELECT cash
                         FROM users
                         WHERE id = ?;''', user_id
                     )[0]['cash']

    return render_template('index.html', stocks=user_stocks, cash=usd(cash), total=usd(stocks_total + cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == 'POST':
        # Ensure a stock's symbol was submitted
        symbol = request.form.get('symbol')
        if not symbol:
            return apology('must provide stock\'s symbol', 403)

        stock_data = lookup(symbol)
        # Ensure the stock's symbol exists
        if not stock_data:
            return apology('stock\'s symbol does not exist', 403)

        # Ensure the number of shares was submitted
        shares = request.form.get('shares')
        if not shares:
            return apology('must provide number of shares', 403)

        # Ensure the number of shares is a positive integer
        try:
            shares = int(shares)
            if shares <= 0:
                return apology('must provide a positive number of shares', 403)
        except:
            return apology('number of shares must be an integer', 403)

        user_id = session['user_id']
        cash = db.execute('''SELECT cash
                             FROM users
                             WHERE id = ?;''', user_id
                         )[0]['cash']

        # Ensure the user can afford the number of shares
        share_price = stock_data['price']
        total_price = shares * share_price
        if cash < total_price:
            return apology('you cannot afford this number of shares at the current price', 403)

        # Add the buy transaction to database
        db.execute('''INSERT INTO transactions(user_id, is_bought, stock_symbol, shares_number, share_price, timestamp)
                      VALUES(?, ?, ?, ?, ?, ?);''', user_id, 1, symbol, shares, share_price, datetime.now()
                  )

        # Check if the user has shares of this stock
        existing_shares = db.execute('''SELECT shares_number
                                        FROM shares
                                        WHERE user_id = ? AND stock_symbol = ?;''', user_id, symbol
                                    )

        if len(existing_shares) == 0:
            db.execute('''INSERT INTO shares(user_id, stock_symbol, shares_number)
                          VALUES(?, ?, ?);''', user_id, symbol, shares
                      )
        else:
            db.execute('''UPDATE shares
                          SET shares_number = shares_number + ?
                          WHERE user_id = ? AND stock_symbol = ?;''', shares, user_id, symbol
                      )

        # Update the user's cash value
        db.execute('''UPDATE users
                      SET cash = cash - ?
                      WHERE id = ?;''', total_price, user_id
                  )

        return redirect('/')

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template('buy.html')


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == 'POST':
        # Ensure a stock's symbol was submitted
        symbol = request.form.get('symbol')
        if not symbol:
            return apology('must provide stock\'s symbol', 403)

        stock_data = lookup(symbol)
        return render_template('quoted.html', stock=stock_data)

    return render_template('quote.html')


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    
    # User reached route via POST (as by submitting a form via POST)
    if request.method == 'POST':
        # Ensure username was submitted
        if not request.form.get('username'):
            return apology('must provide username', 403)

        # Ensure username does not already exist
        if len(db.execute('SELECT * FROM users WHERE username = ?', request.form.get('username'))) != 0:
            return apology('username already exists', 403)

        # Ensure password was submitted
        elif not request.form.get('password'):
            return apology('must provide password', 403)

        # Ensure password  and confirmation password are the same
        elif request.form.get('password') != request.form.get('confirmation'):
            return apology('passwords don\'t match', 403)

        # If all is good, register the new user
        else:
            db.execute('''INSERT INTO users(username, hash)
                          VALUES(?, ?)''', request.form.get('username'), generate_password_hash(request.form.get('password')))

            return redirect('/login')

    return render_template('register.html')


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Query the database for the number of shares the user have each stock they own
    user_id = session['user_id']
    stocks = db.execute('''SELECT stock_symbol, shares_number
                            FROM shares
                            WHERE user_id = ? AND shares_number != 0;''', user_id
                       )

    # Make a dict with each of the user's stock symbols and their number of shares
    user_stocks = {}
    for stock in stocks:
        user_stocks[stock['stock_symbol']] = stock['shares_number']

    # User reached route via POST (as by submitting a form via POST)
    if request.method == 'POST':
        # Ensure a stock's symbol was submitted
        symbol = request.form.get('symbol')
        if not symbol:
            return apology('must provide stock\'s symbol', 403)

        # Ensure the stock's symbol exists in user's stocks
        if symbol not in user_stocks:
            return apology('stock\'s symbol does not exist in your stocks', 403)

        # Ensure the number of shares was submitted
        shares = request.form.get('shares')
        if not shares:
            return apology('must provide number of shares', 403)

        # Ensure the number of shares is a positive integer
        try:
            shares = int(shares)
            if shares <= 0:
                return apology('must provide a positive number of shares', 403)
        except:
            return apology('number of shares must be an integer', 403)

        # Ensure user has the requested number of shares
        if user_stocks[symbol] < shares:
            return apology('you do not own the requested number of shares', 403)

        # Get the share price
        share_price = lookup(symbol)['price']

        # Add the sell transaction to database
        db.execute('''INSERT INTO transactions(user_id, is_bought, stock_symbol, shares_number, share_price, timestamp)
                      VALUES(?, ?, ?, ?, ?, ?);''', user_id, 0, symbol, shares, share_price, datetime.now()
                  )

        db.execute('''UPDATE shares
                      SET shares_number = shares_number - ?
                      WHERE user_id = ? AND stock_symbol = ?;''', shares, user_id, symbol
                  )

        # Update the user's cash value
        db.execute('''UPDATE users
                      SET cash = cash + ?
                      WHERE id = ?;''', shares * share_price, user_id
                  )

        return redirect('/')

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template('sell.html', symbols=user_stocks.keys())


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
