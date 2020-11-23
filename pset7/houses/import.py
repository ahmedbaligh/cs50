import csv
from sys import argv, exit
from cs50 import SQL


# Ensure correct usage
if len(argv) != 2:
    exit('Usage: python import.py data.csv')

# Open database
db = SQL("sqlite:///students.db")

# Read csv file of students data into students database
with open(argv[1], 'r') as file:
    reader = csv.DictReader(file)

    for row in reader:
        # Split names into first, middle, and last names
        name = row['name'].split(' ')

        if len(name) == 3:
            middle_name = name[1]
            last_name = name[2]
        # Leave middle name as Null, if student does not have one
        else:
            middle_name = None
            last_name = name[1]

        # Insert each student's data into the database
        db.execute('''
            INSERT INTO 
            students (first, middle, last, house, birth)
            VALUES(?, ?, ?, ?, ?)''',
            name[0], middle_name, last_name, row['house'], int(row['birth'])
        )
        