

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <sys/shm.h> 
#include <string.h>




int main() { 
   int x=1;
   char *teste[100], *pudim[10];
   int shmid = shmget(IPC_PRIVATE, 100, 0600); 
   teste[0]= (char *)shmat(shmid, (void *)0, 0); 
   strcpy(*teste,"socorro");
   printf("Pai %s pede pra  dizer algo\n",*teste);
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
