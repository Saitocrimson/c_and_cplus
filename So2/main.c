#include <stdio.h>
#include <unistd.h>

// Paralelismo com processos
int main(){
  int pai,filho1,filho2,filho3,teste;
  filho1=fork();
  filho2=fork();
  filho3=fork();

  if(filho1==0)
  {
    printf("F1 %d\n",getpid());
  }
  if(filho2==0)
  {
    printf("F2 %d\n", getpid());
  }
  if(filho3==0)
  {
    printf("F3 %d\n", getpid());
  }
  else {
    
    printf("Pai %d\n", getpid());
  
  }
    while(1);
}
