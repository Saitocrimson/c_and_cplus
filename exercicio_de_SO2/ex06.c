
#include <stdio.h>
#include <math.h>



void soma(int a){
  int result=0;
for(int i=1;i<=a;i++)
{
result=result+i;
}
printf("a soma de %d eh %d\n", a,result); 

}



void ler(int *a){
printf("Digite o number 1\n");
  scanf("%d", &(*a));



}


void executa(int a){
  ler(&a);
  soma(a); 

}



int main() {
  int a;
  executa(a);
  return 0;
}
