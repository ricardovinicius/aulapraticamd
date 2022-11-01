#include <stdio.h>
#include <math.h>

int main(void)
{
    int number, prime;
    number = 36;
    prime = 2;
    while(number >= prime * prime)
    {
        if(number % prime == 0)
        {
            printf("%d * ", prime);
            number /= prime;
        }
        else
        {
            prime++;
        }
    }
    printf("%d\n", number);
}