#include <stdio.h>
#include <math.h>

#define pi 3.14
/*Escrever um programa que permita ao usuário escolher dentre as figuras
geométricas círculo, retângulo e triângulo para calcular a área da figura escolhida. Crie
funções para o cálculo de área de cada figura e para um menu de escolha.*/

void circulo(){
    double r, h;
    printf ("Digite o raio\n");
     scanf ("%lf", &r);
      printf ("A area do circulo eh: %.2lf\n", pi*pow(r,2));
}
void triangulo(){
  double b, h;
  printf ("Digite o valor da base\n");
  scanf ("%lf", &b);
  printf ("Digite o valor da altura\n");
  scanf ("%lf", &h);
  printf ("A area do triangulo eh: %.2lf\n", (b * h) / 2);

}

void retangulo()
{
    double b, h;
  printf ("Digite o valor da base\n");
  scanf ("%lf", &b);
  printf ("Digite o valor da altura\n");
  scanf ("%lf", &h);
  printf ("A area do retangulo eh: %.2lf\n", (b * h));
}


void quadrado ()
{
  double a, b, c, d;
  printf ("Digite o valor do lado do quadrado\n");
  scanf ("%lf", &a);
  printf ("A area do quadrado eh: %.2lf\n ", pow (a, 2));
}

void menu ()
{
  int x;
  do
    {
      printf ("Areas geometricas\n1-quadrado\n2-triangulo\n3-circulo\n4-retangulo\n5-sair\n");
      printf ("Digite a opcao abaixo;\n");
      scanf ("%d", &x);

    switch (x){
    	case 1:
    	  quadrado ();
    	  break;
    	case 2:
    	    triangulo();
    	case 3:
    	    circulo();
    	case 4:
    	    retangulo();
    	default:
    	  break;
    	}
    }
  while (x != 5);
}


int main ()
{
  menu ();
  return 0;
}
