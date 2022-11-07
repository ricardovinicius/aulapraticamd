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

    int n;
    printf("insira o numero de equacoes\n");
    scanf("%d", &n);
    int mod[n], resto[n];
    
    printf("\ninsira\n");
	
    for (int i = 0; i < n; i++) {
        scanf("%d%d\n", &resto[i], &mod[i]);
    }

    if (!possibilidade(resto, 3)) {
        printf("x = %d\n", teoremaprincipal(mod, resto, sizeof(resto)/sizeof(resto[0])));
    }
    else {
        printf("O sistema dado nao tem solucoes\n");
    }
	return 0;
}