#include <stdio.h>

int find_t(int arrayofquoc[], int quocCounter);
int find_s(int arrayofquoc[], int quocCounter);
int euclideangcd(int numA, int numB);


int main(void)
{
    printf("input two values a and b, a mod b\n");
    int a, b;
    int inverse;
    scanf("%d %d", &a, &b);
    if(a > b)
    {
        inverse = euclideangcd(a, b);
    }
    else
    {
        inverse = euclideangcd(b, a);
    }

    while(inverse < 0)
    {
        inverse += b;
    }
    printf("inv of %d mod %d = %d\n", a, b, inverse);
}

int euclideangcd(int numA, int numB)
{
    int temp;
    int quoc[100];
    int counter;

    while(numB != 0)
    {
        temp = numB;
        quoc[counter] = numA / numB;
        counter++;
        numB = numA % numB;
        numA = temp;
    }
    //printf("%d\n", numA);
    
    int i;

    while(quoc[i] != numA)
    {
        // printf("%d\n", quoc[i]);
        i++;
    }

    //printf("s = %d\n", find_s(quoc, counter - 1));
   return find_t(quoc, counter - 1);
}

int find_s(int arrayofquoc[], int quocCounter)
{
    int i = 0;
    int temp = 0;
    int s = 1;
    int new;
    while(i < quocCounter - 1)
    {
        new = (arrayofquoc[i] * s) + temp;
        temp = s;
        s = new;
        //printf("%d\n", s);
        i++;
    }

    if(quocCounter % 2 == 0)
    {
        return s * (-1);
    }
    else
    {
        return s;
    }
}

int find_t(int arrayofquoc[], int quocCounter)
{
    int i = 0;
    int temp = 0;
    int t = 1;
    int new;
    while(i < quocCounter)
    {
        new = (arrayofquoc[i] * t) + temp;
        temp = t;
        t = new;
        //printf("%d\n", t);
        i++;
    }

    if(quocCounter % 2 == 0)
    {
        return t;
    }
    else
    {
        return t * (-1);
    }
}