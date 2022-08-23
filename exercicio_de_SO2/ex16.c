#include <stdio.h>

void primo(){

   int p,i,e;
   e=120;
   printf("os números primos sao\n");
   for(int i=100;i<e;i++){
      if(i%2>0 && i%3>0 && i%5>0 && i%7>0){
         printf("%d\n",i);
         p++;
    }
      else if(p==20)break;
      else if(p<20)e=e+10;
    
  }

    
}
int main() {
    primo();
    return 0;
}
  
