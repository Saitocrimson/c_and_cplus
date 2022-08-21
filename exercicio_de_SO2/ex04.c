#include <stdio.h>
#include <stdlib.h>





int positivo(int x, int y){
      if(x%y==0)return 0;
      else return 1;
  }
  






int main() {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    if(positivo(a,b)==0) printf("Numero %d eh divisivel por %d\n", a,b);
    else printf("Numero %2d nao eh divisivel por %d\n", a,b);



    return 0;
}
  
