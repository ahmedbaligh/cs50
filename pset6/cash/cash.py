from cs50 import get_float


def main():
    # Get the amount owed in positive rounded integers
    owed = get_positive_rounded()

    # Define avaliable coins and keep track of their total used number
    coins = [25, 10, 5, 1]
    counter = 0
    
    # Find the type of used coins
    while owed > 0:
        # Subtract the value of the largest coin type until 'owed' is zero
        for coin in coins:
            if int(owed / coin) >= 1:
                owed -= coin
                break

        # One coin was used
        counter += 1
    
    print(counter)


def get_positive_rounded():
    while True:
        # Reprompt the user until they enter a positive decimal
        money = get_float('Change owed: ')
        if money > 0:
            break
    
    return round(money * 100)


if __name__ == '__main__':
    main()