#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <sys/shm.h> 



int main() { 
  int x=1;
  char *teste[10]; 
  int shmid = shmget(IPC_PRIVATE, 100, 0600); 
  teste[0]= (char *)shmat(shmid, (void *)0, 0); 
  printf("Pai pede pra  dizer algo\n");
  x = fork(); 
  if(x == 0){ 
printf("Filho disse: ");

scanf("%s", *teste); 
}  
    

wait(NULL);
if(x!=0) printf("E o pai repetiu:%s ???\n",*teste); 
shmdt(teste); 
  
  //printf("Meu id=%d\n", getpid());
shmctl(shmid, IPC_RMID, 0);
 return 0; }
