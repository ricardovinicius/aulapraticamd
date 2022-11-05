#include <stdio.h>

int euclides(int num1, int num2);

int main(void)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    if(num1 > num2)
    {
        printf("%d\n", euclides(num1, num2));
    }
    else
    {
        printf("%d\n", euclides(num2, num1));
    }
}

int euclides(int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return num2;
    }
    else
    {
        return euclides(num2, num1 % num2);
    }
}