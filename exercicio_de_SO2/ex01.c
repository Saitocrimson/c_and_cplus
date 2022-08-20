/*Faça um código em C com duas funções: uma que diga se um ano é bissexto ou
não e outra que calcule quantos anos bissextos ocorreram desde o ano 1 até o ano
2010. Crie uma função de menu que permita ao usuário escolher qual função utilizar.*/
#include<stdio.h>
#include<stdlib.h>

int ano(int ano){
    if(ano%4==0){return 1;}
    else {
        if(ano%100==1 && ano%4==0){
            return 2;
        }
        if(ano%400==0){
            return 3;
        }
        else{
            return 4;
        }
    }

}

void verifica(){
    int count=0;
    for(int i=1;i<2022;i++){
          if(ano(i)==1 || ano(i)==2 || ano(i)==3){
              count++;
          }

    }
    printf("A quantidade de anos bissexto sao %d", count);

}


int main(){
    int ano2,x=0;
    verifica();

}
