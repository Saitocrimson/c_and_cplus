#include <stdio.h>

int positivo(double x){
     if(x>=0)return 0;
     else return 1;
  }
 

int main() {
    double a;
    scanf("%lf", &a);
    if(positivo(a)==0) printf("Numero eh positivo\n");
    else printf("Numero eh negativo\n");
    return 0;
}
  
