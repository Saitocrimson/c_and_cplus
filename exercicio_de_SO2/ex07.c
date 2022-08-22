#include <stdio.h>
#include <math.h>


int min(int a)
{
    return 60*a;
   
}

int seg(int x){
    
    return 60*x;
}
int hora(int a)
{
    seg(min(a));
}


void conta(int a, int b, int c)
{
    int solucao;
    min(a);
    solucao=seg(b)+hora(a)+c;
    printf("%d", solucao);
}

void ler (int *a, int *b, int *c)
{
  printf ("Digite a hora\n");
  scanf ("%d", &(*a));
  printf ("Digite o minuto\n");
  scanf ("%d", &(*b));
  printf ("Digite o segundo\n");
  scanf ("%d", &(*c));



}


void executa (int x,int y,int z)
{
  ler(&x, &y, &z);
  conta(x,y,z);
 
}


int main ()
{
  int a, b, c;
  executa (a,b,c);
  return 0;
}
