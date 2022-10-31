#include <stdio.h>
#include <math.h>

int isprime(int number, int divisor);

int main(void)
{
    int number;
    scanf("%d", &number);
    printf("Is prime? %c\n", isprime(number, 2) ? 'Y' : 'N');
}

int isprime(int number, int divisor)
{
    // this function calculates recursively if a number have a integer divisor 
    // between 2 and the sqrt of the number
    
    if(number == 0 || number == 1)
    {
        return 0;
    }

    if(number == 2)
    {
        return 1;
    }

    // if number is divided by another than 1 and itself, inst prime
    if(number % divisor == 0)
    {
        return 0;
    }

    // tests recursively until the the divisor be bigger than sqrt of the number
    if(divisor <= sqrt(number))
    {
        isprime(number, divisor + 1);
    }
    else    // if doesnt find a divisor, is prime
    {
        return 1;
    }
}