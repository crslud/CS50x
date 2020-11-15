#include <stdio.h>
#include <cs50.h>
#include <math.h>

long find_digit(long num, int pos);
int num_length(long num);
long sum_seq(long num, int len);

int main(void)
{
    long num = get_long("Enter your card number: ");

    /* Variables for easy access */
    long first_dig = find_digit(num, num_length(num) - 1);
    long sec_dig = find_digit(num, num_length(num) - 2);

    /* Check for AMEX */
    if ((num_length(num) == 15) && (first_dig = 3) && ((sec_dig == 7) || (sec_dig == 4)))
    {
        if (sum_seq(num, num_length(num)) == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    /* Check for VISA */
    else if (((num_length(num) == 13) || (num_length(num) == 16)) && (first_dig == 4))
    {
        if (sum_seq(num, num_length(num)) == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    /* Check for MasterCard */
    else if (num_length(num) == 16 && (first_dig == 5) && (sec_dig > 0) && (sec_dig < 6))
    {
        if (sum_seq(num, num_length(num)) == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    /* Default to invalid */
    else
    {
        printf("INVALID\n");
    }
    return 0;
}


long find_digit(long num, int pos)
/* Finds the digit at a particular position */
{
    num = num / pow(10, pos);
    num = num % 10;
    return num;
}


int num_length(long num)
/* Finds the length of the number */
{
    int count = 1;
    for (long i = num; i > 9; i = i / 10)
    {
        count++;
    }
    return count;
}

long sum_seq(long num, int len)
/* Returns the sum arithmetic sequence */
{
    long total = 0;
    /* First loop for digits */
    for (int i = 1; i < len; i = i + 2)
    {
        long twice = (find_digit(num, i) * 2);
        if (twice < 10)
        {
            total = total + twice;
        }
        else
        {
            total = total + find_digit(twice, 0) + find_digit(twice, 1);
        }
    }
    /* Second loop for other digits */
    for (int i = 0; i < len; i = i + 2)
    {
        total = total + find_digit(num, i);
    }
    return (total % 10);
}

