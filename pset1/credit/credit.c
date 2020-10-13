#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Prototypes
int otherDigit(int oDigit);
void checkType(int digitsNum, long cardNum);

int main(void)
{
    // Prompt for card number
    long cardNum = get_long("Number: ");
    // Initialize a new card number for calculations
    long newCardNum = cardNum;
    
    // Store each digit
    int digit;
    // Initialize the number of digits, the sum in Luhn’s algorithm
    int digitsNum = 0;
    int sum = 0;
    
    for (int i = 1; newCardNum > 0; i++)
    {
        // Get each digit in the card number
        if (newCardNum % 10 == 0)
        {
            digit = 0;
        }
        else
        {
            digit = newCardNum % 10;
        }
        
        // Sum the digits based on their location
        if (i % 2 == 0)
        {
            sum += otherDigit(digit);
        }
        else
        {
            sum += digit;
        }
        
        // New card number after removing the extracted digit
        newCardNum = (newCardNum - digit) / 10;
        
        digitsNum++;
    }
    
    // Check if the first digit in the sum is zero
    if (sum % 10 == 0)
    {
        // If number follows Luhn’s algorithm, check card type
        checkType(digitsNum, cardNum);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Do Luhn’s process on every other digit
int otherDigit(int oDigit)
{
    int multipled = oDigit * 2;
    int firstDigit = multipled % 10;
    int secondDigit = (multipled - firstDigit) / 10;
    
    return firstDigit + secondDigit;
}

// Check card type based on its number of digits and starting digit(s)
void checkType(int digitsNum, long cardNum)
{
    int firstDigit;
    int firstTwoDigits;
    
    if (digitsNum == 15)
    {
        firstTwoDigits = cardNum / pow(10, 13);
        if (firstTwoDigits == 34 || firstTwoDigits == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    else if (digitsNum == 16)
    {
        firstDigit = cardNum / pow(10, 15);
        firstTwoDigits = cardNum / pow(10, 14);
        
        if (firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digitsNum == 13)
    {
        firstDigit = cardNum / pow(10, 12);
        if (firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}