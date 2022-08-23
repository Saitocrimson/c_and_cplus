#include <stdlib.h>
#include <stdio.h>

int pares(int *v)
{
    int t;
    for(int i=0;i<15;i++){
        if(v[i]%2==0)t++;
    }
    return t;
}


void ler(int *v)
{
    for(int i=0;i<15;i++){
        printf("Digite um  umero inteiro:\n");
        scanf("%d", &v[i]);
    }
}



int main()
{
    int v[15];
    ler(v);
    printf("o vetor possui %d pares\n", pares(v));
    return 0;
}
