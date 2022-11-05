#include <stdio.h>
#include <time.h>
#include <math.h>

long int contadorPrimos;
long int primosArray[100000000];

void func(float delayInSeconds);
void primos(long int numero, long int acumulador);

int main(void)
{

    primosArray[contadorPrimos] = 2;
    printf("%ld\n", primosArray[contadorPrimos]);

    contadorPrimos++;
    primosArray[contadorPrimos] = 3;
    printf("%ld\n", primosArray[contadorPrimos]);

    func(60);
}

void primos(long int numero, long int acumulador)
{
    long int raizdonumero = sqrt(numero);
    do
    {
        if(numero % primosArray[acumulador] == 0)
        {
            return;
        }
        else
        {
            acumulador++;
        }
    }
    while(primosArray[acumulador] < raizdonumero);

    contadorPrimos++;
    primosArray[contadorPrimos] = numero;
    printf("%ld\n", primosArray[contadorPrimos]);
    return;
    
}

void func(float delayInSeconds) 
{
    time_t startTime;
    time_t now;
    float elapsedTime;
    float setTime = delayInSeconds;
    long int numero = 5;

    time(&startTime);
    while (elapsedTime < setTime) {
        //do something...
        primos(numero, 0);
        numero += 2;
        now = time(NULL);
        elapsedTime = difftime(now, startTime);
    }
    printf("Quantidade primos encontrados: %ld\n", contadorPrimos);
}
