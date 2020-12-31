# Finance

Full-Stack web application via which users can “buy” and “sell” stocks, query the name and price of a stock's symbol, see their current shares' numbers and prices, along with their remaining cash amount, and also see their full transaction history.

![C$50 Finance](https://cs50.harvard.edu/college/2020/fall/psets/9/finance/finance.png)


## Implementation Details

* User transactions and shares information are recorded into a `SQLite` database and all stocks' information come live from [IEX](https://iexcloud.io/)'s API.

* Users are required to sign in to be able to use any of the website's services.

    * All passwords are hashed, before getting stored in the database.

* New users may sign up for an account in the Register page.

    * If their inputed username already exsits, they are informed and the operation fails.

* In the index page, users can find a summary about the number of shares for each stock they own, along with their current price and total worth.

    * The user's remaining cash amount is also shown here, which is $10,000 by default.

* In Quote page, users can look up a stock's symbol to find its stock's name and current price.

* In Buy page, users can buy a number of shares for a given stock, if they can afford it.

    * The number of shares must be a positive integer, otherwise the the transaction cannot be made and the user is informed.

* In Sell page, users can sell a number of shares for one of the stocks they own.

    * The transaction fails, if the user tries to sell a stock they do not own any shares of.

    * The number of shares must be a positive integer, otherwise the the transaction cannot be made and the user is informed.

* After each transaction, the user's cash and shares records for this stock are updated accordingly.

* In History page, all of the user's transactions are listed in descending order.

    * The number of shares is negative, if this was a sell transaction.

    * The price shown is the stock's price at the time of buy/sell.

* In Change Password page, users are required to submit their current password, along with their newly created password and its confirmation.

    * The entered current password is checked against the user's hashed password in the database; if it is not a match, operation fails.

* In both Register and Change Password pages, if the password does not match its confirmation, the operation fails.

* All input fields are checked before proceeding, if a field is missing, the user is informed with an error message indicating the respective field.


## Getting Started

### IEX API

This project uses [IEX](https://iexcloud.io/)'s API data to query stocks' prices.

[IEX](https://iexcloud.io/) requires users to register to be able to use their API, which you may do by visiting [here](iexcloud.io/cloud-login#/register/). Once you’ve confirmed your account via a confirmation email, visit [here](https://iexcloud.io/console/tokens) and copy the key that appears under the Token column (it should begin with `pk_`).

In the terminal, replacing `value` with your API key, execute:

```bash
export API_KEY=value
```

### Installing Dependencies

Make sure to have `Python3` and `SQLite` installed in your machine. To install all of the project's dependencies, make sure to be in the `finance` directory, then execute: 

```bash
pip3 install -r requirements.txt
```

### Running the Server

To run the server, make sure to be in the `finance` directory, then execute: 

```bash
export FLASK_APP=application.py
flask run
```

This will run the server on [http://127.0.0.1:5000/](http://127.0.0.1:5000/) in production mode.
