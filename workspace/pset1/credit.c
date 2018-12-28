#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    // 1. INPUT VERIFICATION
    long long cc;
    long long verification;
    int digitCount;

    do {
        cc = get_long_long("Enter your Credit Card Number: ");

        verification = cc;
        digitCount = 0;

        while(verification != 0){
            verification = verification / 10;
            digitCount++;
        }
    }
    while (digitCount < 13 || digitCount > 16);


    // 2. CREDITCARD VALIDATION
    long long check = cc;
    int sum_forelast = 0;
    int sum_last = 0;

    // loop through cc number in pairs at the time (beginning in the end)
    while(check > 0){

        int forelastDigit = 2 * ((check % 100) / 10);   // getting last two digits, eliminating last one
        int lastDigit = ((check % 100) % 10);           // getting last two digits, eliminating first one

        if(forelastDigit > 9){
            sum_forelast = sum_forelast + 1 + forelastDigit % 10; // adding numbers one by one
        } else {
            sum_forelast = sum_forelast + forelastDigit; // sum together
        }

        sum_last = sum_last + lastDigit;    //sum together

        check = check / 100;    // remove last two digits
    }

    int checksum = (sum_forelast + sum_last) % 10;
    if(checksum != 0) {
        printf("Credit card is invalid\n");
    }


    // 3. IDENTIFY COMPANY
    long long identifier = cc;
    bool valid_company = false;

    // Get the first two digits of cc number
    while (identifier > 99 ){
        identifier = identifier / 10;
    }

    // Check for Amex
    if(digitCount == 15){
       if(identifier == 34 || identifier == 37){
            printf("Your Credit Card Company is: Amex\n");
            valid_company = true;
        }
    }

    // Check for Visa
    if(digitCount == 13 || digitCount == 16){
       if((identifier / 10) == 4){
            printf("Your Credit Card Company is: Visa\n");
            valid_company = true;
        }
    }

    //Check for Mastercard
    if(digitCount == 16){
       if(identifier >= 51 && identifier <= 55){
            printf("Your Credit Card Company is: Mastercard\n");
            valid_company = true;
        }
    }

    if(!valid_company) {
        printf("Unknown Credit Card Company\n");
    }


}