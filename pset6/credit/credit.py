from cs50 import get_int


def main():
    # Prompt for card number, then convert to a string
    card_number = str(get_int('Number: '))

    digits = []
    # Make each digit in the card number an element in a list of integers
    for digit in card_number:
        digits.append(int(digit))
    
    # Reverse the order of the digits to handle its numbers from the right
    digits.reverse()

    sum = 0
    # Sum the digits based on their location
    for i, digit in enumerate(digits):
        # Apply Luhn’s process on every other digit
        if i % 2 == 1:
            digit = other_digits(digit)
        
        sum += digit

    # Initialize the card's type to 'INVALID'
    card_type = 'INVALID'

    # If the card fulfills Luhn’s Algorithm, check its type
    if sum % 10 == 0:
        card_type = check_type(card_number)

    print(card_type)  


def other_digits(digit):
    digit *= 2

    # Extract the first and second digits of the multiplied original
    first_digit = digit % 10
    second_digit = (digit - first_digit) / 10
    
    # Return the sum of the individual two digits
    return first_digit + second_digit


def check_type(card_number):
    # Get the length of and first two digits of the card's number
    length = len(card_number)
    first_digit = int(card_number[0])
    first_two_digits = int(card_number[:2])

    # Return a string of the card's type based on each type's conditions
    if (length == 15) and (first_two_digits in [34, 37]):
        return 'AMEX'
    elif (length in [13, 16]) and (first_digit == 4):
        return 'VISA'
    elif (length == 16) and (first_two_digits in [51, 52, 53, 54, 55]):
        return 'MASTERCARD'
    
    # If the card is not in the avaliable cards, return 'INVALID'
    return 'INVALID'


if __name__ == '__main__':
    main()
