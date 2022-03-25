#include <iostream>
#include <iomanip>


using namespace std;
 
class His
{
    private:
        double x,y;
        int a,b,c,d;
        string prof,mat;
    public:
         void ler();
         void mostrar();
};

void His::ler()
{
    cin>>a;
    cin.ignore();
    getline(cin, mat);
    getline(cin, prof);
  
    
    cin>>b;
    cin>>c;
    cin>>d;
    
    cin>>x;
    cin>>y;
    
    
}



void His::mostrar()
{
    cout << setfill ('0') <<  setw (4) << a << " ";
    cout << left << setfill (' ') <<  setw (50) << mat<< " ";
    cout << right << setfill (' ') << setw(4) << b << " ";
    cout << c << "/" << d << " ";
    cout << fixed<<setprecision(2);
    cout << right << setfill ('0') <<  setw (5)<<(x + 2.0*y)/3.0 << endl; 
}

int menu()
{
    int t;
    do{
       cout<<"1 - inicializar"<<endl;
       cout<<"2 - inserir nova disciplina"<<endl;
       cout<<"3 - listar historico"<<endl;
       cout<<"4 - sair"<<endl;
       cout<<"Entre com a sua opcao:"<<endl;
      cin>>t;
    }while(t<1 || t>4);
    return t;
}


int main()
{
    His p[100];
    int u=0;
    string ok;
    bool treco =true;
        do{
            switch(menu()){
                case 1:u=0;
                   cout << "Historico inicializado com sucesso!" <<  endl;   
                break;
                case 2:
                       p[u].ler();
                       u++;
                  cout << "Disciplina inserida com sucesso!" << endl;
                       break;
                case 3:
                       cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
                       for(int i=0;i<u;i++){
                        p[i].mostrar();
                        }
                        do{
                        cin>>ok;
                        }while(ok!="Ok");
                          break;
                case 4:
                   cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
                   treco=false;
                   break;
            }    
        }while(treco==true);
        
      
 
  return 0;
}
