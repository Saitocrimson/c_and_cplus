#include <iostream>
#include <iomanip>


using namespace std;
 
class Aluno
{
    private:
        double x,y;
        int a,b,c,d;
        string prof,alu;
    public:
         void ler();
         void mostrar();
};

void Aluno::ler()
{
    cin>>a;
    cin.ignore();
    getline(cin, alu);
    getline(cin, prof);
  
    
    cin>>b;
    cin>>c;
    cin>>d;
    
    cin>>x;
    cin>>y;
    
    
}

void Aluno::mostrar()
{
    cout<<setfill('0')<<"Codigo    : "<<setw(4)<<a<<endl;
    cout<<"Nome      : "<<alu<<endl;
    cout<<"Professor : "<<prof<<endl;
    cout<<"Creditos  : "<<b<<endl;
    cout<<"Ano       : "<<c<<endl;
    cout<<"Semestre  : "<<d<<endl;
    cout << fixed<<setprecision(2);
    cout<<"Nota1     : "<<x<<endl;
    cout<<"Nota2     : "<<y<<endl;
    cout<<"Media     : "<<(x + (2.0*y))/3.0<<endl;
}


int main()
{
    Aluno p;
    int t=0;
    string ok;
    while (t<3){
        do{
        cout<<"1 - ler dados da disciplina"<<endl;
	    cout<<"2 - mostrar os dados da disciplina"<<endl;
	    cout<<"3 - sair"<<endl;
	    cout<<"Entre com a sua opcao:"<<endl;
	    cin>>t;
	    }while( t< 1 || t >3);
        if(t==1)p.ler();
        else if(t==2){
             p.mostrar();
            do
                cin>>ok;
            while(ok!="Ok");
        }
    }
    cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
    return 0;
}
