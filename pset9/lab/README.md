# Lab 9: Birthdays

Simple web application to keep track of friends’ birthdays by viewing all of their birthdays and adding new ones to them.

![Birthdays](https://cs50.harvard.edu/college/2020/fall/labs/9/birthdays.png)


## Implementation Details

* All displayed records come dynamically from a `SQLite` database.

* To add a new record, all input fields (Name, Month, Day) are required.

    * Inputs in Month and Day fields must be numbers and within the ranges 1:12 and 1:31, respectively.

* New records are added to the database, causing a page re-render to incorporate them.


## Getting Started

Make sure to have `Python3` and `SQLite` installed in your machine. Also, if you do not have `Flask` installed, run:

```bash
pip3 install flask
```

### Running the Server

To run the server, make sure to be in the `lab` directory, then execute: 

```bash
export FLASK_APP=application.py
export FLASK_ENV=development
flask run
```

This will run the server on [http://127.0.0.1:5000/](http://127.0.0.1:5000/) in development mode.
