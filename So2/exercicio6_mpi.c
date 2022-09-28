#include <stdio.h>
#include <mpi.h>


int somar(int ini, int v[1000]){
        int i=0, cont=0;
        int inicio= ini*250;
        int fim=(ini+1)*250;
        for(i=ini;i<fim;i++)
        {
                if(v[i]%2==0)
                    cont++;
        }

        return cont;


}

int main(int argc, char *argv[])
{
  int id,soma=0, v[1000],i,dd;
  for(i=0;i<1000;i++)
   {
          v[i]=i;
   }
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  if(id==0){

              soma+=somar(id,v);
              
              printf("id 0-%d\n", soma);
              MPI_Send(&soma,1,MPI_INT,3,0,MPI_COMM_WORLD);

     }

  if(id==1){  

              soma+=somar(id,v);
              printf("id 1-%d\n", soma);
             
              MPI_Send(&soma,1,MPI_INT,3,0,MPI_COMM_WORLD);


     }

  if(id==2){

              soma+=somar(id,v);
              printf("id 2-%d\n", soma);
             
              MPI_Send(&soma,1,MPI_INT,3,0,MPI_COMM_WORLD);

     }



  if(id==3) {

          int t,o,p,s;
     	  soma+=somar(id,v);
     	  s=soma+t+o+p;
          
          MPI_Status st;
          MPI_Recv(&t,1,MPI_INT,0,0,MPI_COMM_WORLD, &st);
          MPI_Recv(&o,1,MPI_INT,1,0,MPI_COMM_WORLD, &st);
          MPI_Recv(&p,1,MPI_INT,2,0,MPI_COMM_WORLD, &st);
	  printf("id 3-%d\n", s);



  }
  MPI_Finalize();
}
