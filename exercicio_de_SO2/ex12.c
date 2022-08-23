#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double calcula(int x, int a)
{
    double p=1;
    for(int i=1;i<=a;i++)
    {
        p=p*x;
    }
    return p;
}



void ler(int *x, int *a)
{
    printf("Digite o valor de x: ");
    scanf("%d", &(*x));
    printf("Digite o valor da potencia: ");
    scanf("%d", &(*a));
    
}



int main()
{
   int x,a;
   ler(&x,&a);
   printf("O resultado de %d elevado a %d eh %.2lf\n",x,a,calcula(x,a));
   return 0;
}
