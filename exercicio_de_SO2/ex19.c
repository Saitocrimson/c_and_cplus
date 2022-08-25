#include <stdio.h>

void compara(double cops[], double temp[], char mes[][12]){
for(int i=0;i<12;i++)
{
if(temp[i]==cops[0])printf("Menor temperatura eh %.2lf do mes %s\n", temp[i], mes[i]);
  if(temp[i]==cops[11])printf("Maior temperatura eh %.2lf do mes %s\n", temp[i], mes[i]);
}
}




void arruma(double cops[])
{
  double copia;
  for(int i=0;i<12;i++){
    for(int j=0; j<11; j++){
      if(cops[j]>cops[j+1])
      {
        copia=cops[j];
        cops[j]=cops[j+1];
        cops[j+1]=copia;





      }
    }
  }

  }
void ler(char meses[][12], double temp[],double cops []){
  for(int i=0; i<12;i++){
printf("Digite a temperatura do mes %s\n", meses[i]);

  scanf("%lf", &temp[i]);
cops[i]=temp[i];


}
}
int main() {
    char meses[12][12]={"janeiro", "fevereiro", "marco","abril", "maio", "junho", "julho", "agosto", "setembro","outubro","novembro","dezembro"};
    double temp[12], cops[12];
    ler(meses, temp,cops);
    arruma(cops);
    compara(cops,temp,meses);
    return 0;
}
