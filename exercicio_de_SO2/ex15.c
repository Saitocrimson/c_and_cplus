#include <stdlib.h>
#include <stdio.h>

double soma(double *v)
{
    double t=0;
    for(int i=0;i<20;i++){
        t=t+v[i];
    }
    return t;
}


void ler(double *v)
{
    for(int i=0;i<20;i++){
        printf("Digite um numero:\n");
        scanf("%lf", &v[i]);
    }
}



int main()
{
    double v[20];
    ler(v);
    printf("a soma do vetor eh %.2lf\n", soma(v));
   
    return 0;
}
