#include <stdio.h>
#include <unistd.h>

int main()
{
int filho,neto;
filho=fork();
if(filho==0)neto=fork();
if(filho!=0)filho=fork();
if(filho!=0)filho=fork();
printf("id=%d\n", getpid());
while(1);
}
