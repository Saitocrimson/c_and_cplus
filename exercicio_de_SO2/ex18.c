#include <stdio.h>

void tri(double A, double B, double C)
{
  if (A>=B+C){
     printf("NAO FORMA TRIANGULO\n");
    }
    else if((A*A) == (B*B) + (C* C)){
        printf("TRIANGULO RETANGULO\n");
        }
    else if((A*A) > (B * B) + (C * C))
        {
        printf("TRIANGULO OBTUSANGULO\n");}
  else if((A * A) < (B * B) + (C * C))
        {
        printf("TRIANGULO ACUTANGULO\n");
        }
    if((A==B && B==C  &&  A==C)){
            printf("TRIANGULO EQUILATERO\n");
        }
    else if(( A == B)||(A==C)||(C==B)){
        printf("TRIANGULO ISOSCELES\n");
        
    }
} 

void ler(double *a, double  *b, double *c, double *A, double *B, double *C){
do{
  printf("Digite 3 valores para o lado\n");
scanf("%lf %lf %lf", &(*a),&(*b),&(*c));
  }while((*a)<=0 || (*b)<=0 || (*c)<=0);
if (((*b)>=(*a)) && ((*b)>=(*c)) ){
           (*A)=(*b);
           (*B)=(*a);
           (*C)=(*c);
    }
   else if ((*c)>=(*a) && ((*c)>=(*b)) ){
         (*A) = (* c);
         (*B )= (* b);
          (* C)= (*a);
        
        }
    else if(((*a)>=(*b)) && ((*a)>=(*c)) ){
           (*A)=(*a);
           (*B)=(*b);
           (*C)= (*c);
        } 

}



int main()
{
    double a,b,c,A,B,C;
    ler(&a,&b,&c,&A,&B,&C);
    tri(A,B,C);
    return 0;
}
