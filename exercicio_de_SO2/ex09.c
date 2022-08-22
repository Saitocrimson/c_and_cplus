#include <stdio.h>
#include <math.h>
#define pi 3.14
#define pesoH 72.7
#define pesoM 62.1

double calculo_m(double x)
{
    double peso;
    peso=pesoM *x - 44.7;
    return peso;
}

double calculo_h(double x)
{
    double peso;
    peso=pesoH * x - 58;
     return peso;
}

void le(double *x, char *g)
{
    int l;
    printf ("Digite o altura\n");
     scanf ("%lf", &(*x));
    do{
       printf ("Digite H para homem e M para mulher\n");
       scanf ("%s", (g));
       if(*g=='H' || *g=='h' || *g=='M' || *g=='m')l=1;
    }while(l!=1);
}

void executa(double alt, char *g,double cal)
{
    
    if((*g)=='H' || (*g)=='h') cal=calculo_h(alt);
    if((*g)=='M' || (*g)=='m') cal=calculo_m(alt);
    printf("O peso ideal eh %.2lf", cal);
}

    


int main ()
{
  double alt=0,cal;
  char g[2];
  le(&alt,g);
  executa(alt,g,cal);
}
