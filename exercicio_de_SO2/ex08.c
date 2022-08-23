#include <stdio.h>
#include <math.h>
#define pi 3.14


void esfera(double a, double *b)
{
    double v;
    v=(4* pi *(pow(a,3)))/3;
 //   (*b)=(*b)+12; teste para ponteiro
   
    printf("O reultADO eh: %lf\n", v);
}


void le(double *x)
{
  printf ("Digite o raio\n");
  scanf ("%lf", &(*x));

    
}

int main ()
{
  double r=0;
   le(&r);
   esfera(r,&r);
  
  // printf("%lf\n", r);//esse teste serve apenas para relembrar ponteiro 
   return 0;
}
