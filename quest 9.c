#include <stdio.h>

int euclides(int a, int b){


    if ( a == 0) {
        return b;
    }
    else  { 
        return euclides( b % a, a);
    }
}
int possibilidade(int a[], int b){
    for (int x = 0; x < b; x++)
    {
        for (int y = x + 1; y < b ; y++)
        {
            if (euclides(a[x], a[y]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

int inverso(int a, int b){
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int teoremaprincipal(int *n, int *a, int len)
{
	int p, i, prod = 1, sum = 0;

	for (i = 0; i < len; i++) prod *= n[i];

	for (i = 0; i < len; i++) {
		p = prod / n[i];
		sum += a[i] * inverso(p, n[i]) * p;
	}

	return sum % prod;
}

int main()
{
    int mod[3], resto[3];
    int i=0;
    
    printf("insira primeiro os valores de mod e depois os valores de resto");
    scanf("%d%d%d", &mod[i],&mod[i+1], &mod[i+2]);
    scanf("%d%d%d", &resto[i],&resto[i+1], &resto[i+2]);
    
	
    if (!possibilidade(resto, 3)) {
        printf("x = %d\n", teoremaprincipal(mod, resto, sizeof(resto)/sizeof(resto[0])));
    }
    else {
        printf("O sistema dado nao tem solucoes\n");
    }
	return 0;
}