#include <stdio.h>
#include <math.h>



void delta(int a,int b,int c){
  int result;
  result=pow(b,2)-(4*a*c);
if(result<0)printf("nao existe\n");
else printf("o delta eh : %d",result);
}



void ler(int *a, int *b, int *c){
printf("Digite o number 1\n");
  scanf("%d", &(*a));
printf("Digite o number 2\n");
scanf("%d", &(*b));
printf("Digite o number 3\n");
scanf("%d", &(*c));


}


void executa(int a, int b, int c){
  ler(&a,&b,&c);
  delta(a,b,c);

}



int main() {
  int a,b,c;
  executa(a,b,c);
    
    return 0;
}
  
