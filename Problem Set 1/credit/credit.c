#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool luhn_check(long number);
int get_length(long number);

int main(void) {
    long number = get_long("Number: ");

    if (!luhn_check(number)) {
        printf("INVALID\n");
        return 0;
    }

    int len = get_length(number);

    long start_digits = number;
    while (start_digits >= 100) {
        start_digits /= 10;
    }

    if (len == 15 && (start_digits == 34 || start_digits == 37)) {
        printf("AMEX\n");
    } else if (len == 16 && (start_digits >= 51 && start_digits <= 55)) {
        printf("MASTERCARD\n");
    } else if ((len == 13 || len == 16) && (start_digits / 10 == 4)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}

bool luhn_check(long number) {
    int total = 0;
    int pos = 0;

    while (number > 0) {
        int digit = number % 10;

        if (pos % 2 == 1) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        total += digit;
        number /= 10;
        pos++;
    }

    return (total % 10 == 0);
}

int get_length(long number) {
    int length = 0;
    while (number > 0) {
        number /= 10;
        length++;
    }
    return length;
}
