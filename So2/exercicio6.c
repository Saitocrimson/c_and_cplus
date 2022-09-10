#include<stdio.h>
#include<unistd.h>
int v[1000];



int somavetor(int id)
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
        int x,y=0;
        for(int i=0;i<1000;i++){
                v[i] = i;

}
        x=fork();
        y=y+somavetor(0);
        if(x!=0){
            x=fork();
            y=y+somavetor(1);
        }
    
    if(x!=0){
            x=fork();
            y=y+somavetor(2);
        }if(x!=0)
        {
       y=y+somavetor(3);
        }
        printf("Total %d\n", y);
       // printf("id=%d\n", getpid());
       
        while(1);
}
