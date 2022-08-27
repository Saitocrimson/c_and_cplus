#include <stdio.h>

typedef struct pessoa {
    int idade;
    char sexo;
    double salario;
    int numFilhos;
}Pessoa;


double resto(double y)
{
   
    return (y - 15)/100000;
}
double media(double y){
    return y/15;
}


double somatudo(Pessoa *p)
{
    int i;
    double y;
    for(i = 0; i < 15; i++){
        y=y+p[i].salario;
    }
    
    return y;
}

int salario_ver(Pessoa *p, int i)
{
    if(p[i].salario <=500) return 1;
    else return -1;
   
}


int filho_ver(Pessoa *p, int i)
{
    int soma=0;
    if(p[i].numFilhos==3) return 1;
    else return -1;
   
}

int lerqtdM(Pessoa *p)
{
    int i, soma=0;
    for(i = 0; i < 15; i++){
        if(p[i].sexo == 'm' || p[i].sexo =='M')
            if(filho_ver(p,i)>0 && salario_ver(p,i)>0){printf("%d\n", i); soma++;}
    }
    return soma;
}

void lerHabitante(Pessoa *p){
    int i;
    for(i = 0; i < 15; i++){
        printf("Digite a idade:");
        scanf("%d", &p[i].idade);
        printf("Digite o sexo (m para mulheres e h para homem):");
        scanf("%s", &p[i].sexo);
        printf("Digite a quantidade de filhos:");
        scanf("%d", &p[i].numFilhos);
        printf("Digite o salario:");
        scanf("%lf", &p[i].salario);
       
    }
}

int menorIdade(Pessoa *p){
    int i,menor=p[0].idade ;
    for(i = 1; i < 15; i++){
       // printf("%d\n", p[i].idade);
        if(p[i].idade < menor)
            menor = p[i].idade;
    }
    return menor;
}


int maiorIdade(Pessoa *p){
    int i, maior = p[0].idade,menor=0;
    for(i = 1; i < 15; i++){
       // printf("%d\n", p[i].idade);
        if(p[i].idade > maior)
            maior = p[i].idade;
    }
    return maior;
}

void executa(Pessoa *p)
{
   lerHabitante(p);
   printf("Ao todo o grupo possui %d de mulheres com 3 filhos que recebem ate 500 reais\n", lerqtdM(p));  
   printf("Media salario: %.2lf\n", media(somatudo(p))+resto(somatudo(p)));  
   printf("Maior idade: %d\n", maiorIdade(p));  
   printf("Menor idade: %d\n", menorIdade(p));  
}



int main(){
    Pessoa p[15];
    executa(p);
   
}
