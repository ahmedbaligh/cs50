import csv
from sys import argv, exit
from cs50 import SQL


# Ensure correct usage
if len(argv) != 2:
    exit('Usage: python roster.py house_name')

# Open database
db = SQL("sqlite:///students.db")

# Query students of the provided house name
students = db.execute('''
                        SELECT first, middle, last, birth
                        FROM students
                        WHERE house = ?
                        ORDER BY last, first''',
                        argv[1]
                    )

# Print a roster of students from specified house
for student in students:
    # Check for the existence of a middle name
    if student['middle'] is None:
        print(f"{student['first']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
