#include <stdio.h>
#define verdade 0
#define falso 1
#define para "s"


int media_filhos(int filho[], int qtd)
{
    int copia=0;
    for(int i=0;i<qtd;i++){
      copia=copia+filho[i];
    }
    return copia/qtd;
}

void menor(double salario2[],int qtd)
{

    double per=0;
    printf("\nO percentual de salarios menores que 380 foram: ");
   for(int i=0;i<qtd;i++){
      if(salario2[i]<380){
          per++;
      }
    }
    
    printf("%.2lf",(per*qtd)/100);
}


double resto(double y, int p)
{
   
    return (y-p)/100000;
}

double media_salario(double salario2[],int qtd)
{
    double copia=0;
  for(int i=0;i<qtd;i++){
      copia=copia+salario2[i];
      
    }
    return copia/qtd;
}


void arruma(double salario2[], int qtd)
{
  double copia;
  for(int i=0;i<qtd;i++){
    for(int j=0; j<qtd; j++){
      if(salario2[j]>salario2[j+1])
      {
        copia=salario2[j];
        salario2[j]=salario2[j+1];
        salario2[j+1]=copia;
      }
    }
  }
}


void ler(double salario[], double salario2[], int filhos[])
{
    int x=1,pessoa=0,fil;
    
    double t;
    printf("Digite -1 para encerrar\n");
    do{
        printf("Digite o salario da pessoa %d\n", pessoa+1);
        scanf("%lf", &salario[pessoa]);
        
         if(salario[pessoa]==-1.0)break;
          salario2[pessoa]=salario[pessoa];
       
        printf("Digite quantos filhos tem a pessoa %d\n", pessoa+1);
        scanf("%d", &filhos[pessoa]);
        if(filhos[pessoa]==-1)break;
        else pessoa++;
        if(salario[pessoa-1]==-1.0)x=verdade;
    }while(x==falso);
          
          arruma(salario2,pessoa);
          t=media_salario(salario,pessoa);
          fil=media_filhos(filhos,pessoa);
          printf("A media de salario deu aproximadamente: %.2lf, sendo o salario %.2lf o maior",t +resto(t,pessoa),salario2[pessoa]);
          menor(salario2, pessoa);
          printf("\nA media de filhos deu aproximadamente: %d",fil);
     
}
int main()
{
   double salario[1000], salario2[1000];
   int filhos[10000];
   ler(salario,salario2,filhos);
   

    return 0;
}
