#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>

int somaPares(int id, int v[1000])
{
    int i,soma=0;
    int inicio = id * 250;
    int fim = (id + 1) * 250;
    for(i=inicio;i<fim;i++){
        if(v[i] % 2 == 0) 
            soma++;
    }
    return soma;
}

int main()
{
        int x,*y,i,v[1000];
        int shmid = shmget(IPC_PRIVATE, 100, 0600);
         y = shmat(shmid, 0, 0);
        *y=0;
     for(int i=0;i<1000;i++)
                v[i] = i;
     for(i = 0; i < 3; i++){
      x = fork();
      if(x == 0){
        *y+=somaPares(i, v);
        exit(0);
      }
    }
      
     *y+=somaPares(i,v);
     for(i=0; i<3; i++) wait(NULL);
    printf("Soma Total = %d\n", *y);
    shmdt(y);
    shmctl(shmid, IPC_RMID, 0);
    return 0;   
       
}
