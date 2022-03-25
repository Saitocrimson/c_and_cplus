#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

using namespace std;

class Dis
{
    private:
        string mat, prof;
        double n1, n2, media;
        int cod, cre, sem, ano;
    public:
        void ler();
        void mostrar();
        string getNome()        { return mat;      }
        string getProfessor()   { return prof; }
        int getCodigo()         { return cod;    }
        int getAno()            { return ano;       }
        int getSemestre()       { return sem;  }
        double getMedia()       { return media;     }
        int getCredito()        { return cre;   }
};


class His
{
    private:
        Dis v[10];
        int qtd;
        double cr;
    public:
        void iniciar(){qtd=0;};
        void inserir(Dis d, His &h);
        int achar(int x);
        void remover(int x);
        void alterar(int x);
        void mostrarTodas();
        void AnoSem(int &a,int &b);
        void mostrarNome();
        void mostrarP();
        void cred();
        void mostratudo();
};




void Dis::ler(){
    cin >> cod;
    cin.ignore();
    getline (cin,mat);
    getline (cin,prof);
    cin >> cre;
    cin >> ano;
    cin >> sem;
    cin >> n1;
    cin >> n2;
    media=(n1 + 2.0*n2)/3.0;
}

void His::inserir(Dis d, His &h){
    h.v[h.qtd] = d;
    h.qtd++;
}

int His::achar(int x)
{
  int codigo, i = 0;
    bool achou = 0;
    while ( achou==0 && i < qtd )
    {
        if ( v[i].getCodigo() == x )
            achou = 1;
        else 
            i++;
    }
    return achou ? i : -1;
}

void His::remover(int x)
{
    int posicao = achar(x);
    int i;
    if ( posicao > -1 )
    {
        for ( i = posicao+1 ; i < qtd ; i++, posicao++ )
        {
            v[posicao] = v[i];
        }
        qtd--;
        cout << "Disciplina removida com sucesso!" << endl;
    }
    else 
        cout << "Disciplina nao encontrada!" << endl;
}

void His::alterar(int x)
{
    int posicao = achar(x);
    if ( posicao > -1 )
    {
        v[posicao].ler();
        cout << "Disciplina alterada com sucesso!" << endl;
    }
    else 
        cout << "Disciplina nao encontrada!" << endl;
}

void Dis::mostrar(){
    cout << setprecision(2) << fixed;
    cout << setfill('0') << setw(4) << cod << " ";
    cout << setfill(' ') << setw(54) << left << mat;
    cout << right << cre << " " << right << ano << "/" << sem << " ";
    cout << setfill('0') << setw(5) << (n1 + 2.0*n2)/3.0 << endl;
}

void His::AnoSem(int &a,int &b){
    int i;
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for(i = 0; i<qtd; i++)
        if ((v[i].getAno() == a) && (v[i].getSemestre() == b))v[i].mostrar();
}

void His::mostrarTodas(){
    int i;
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for(i=0;i<qtd;i++)
        v[i].mostrar();
}

void His::mostrarP(){
    int i, posN = 0, posP = 0;
    string s;
    cin.ignore();
    getline(cin,s);
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for(i = 0; i<qtd; i++){
        posN = v[i].getNome().find(s);
        posP = v[i].getProfessor().find(s);
        if (posN > -1 || posP > -1)v[i].mostrar();
    }


}



void His::cred()
{
    int i;
    double pesoTotal = 0;
    cr = 0;
    for ( i = 0 ; i < qtd ; i++ )
    {
        pesoTotal += v[i].getCredito();
        cr += v[i].getMedia()*v[i].getCredito();
    }
    if ( cr > 0 )
        cr /= pesoTotal;
}

void His::mostratudo()
{
    int i;
    mostrarTodas();
    cred();
    cout << "Coeficiente de Rendimento                                           ";
    cout << setfill ('0') <<  setw (5) << setprecision(2) << fixed << cr << endl;
}

int menu()
{
    int t;
    do{
        cout<<"1 - inserir nova disciplina"<<endl;
        cout<<"2 - remover disciplina pelo codigo"<<endl;
        cout<<"3 - alterar disciplina pelo codigo"<<endl;
        cout<<"4 - listar todas as disciplinas"<<endl;
        cout<<"5 - listar disciplinas de um ano/semestre"<<endl;
        cout<<"6 - listar disciplinas pelo nome/professor"<<endl;
        cout<<"7 - Historico"<<endl;
        cout<<"8 - sair"<<endl;
        cout<<"Entre com a sua opcao:" << endl;
      cin>>t;
    }while(t<1 || t>8);
    return t;
}

int main()
{
    His p;
    Dis d;
    int u=0,y,w;
    string ok;
    p.iniciar();
    bool treco =true; 
        do{
            switch(menu()){
                case 1:
                  d.ler();
                  p.inserir(d,p);
                  cout << "Disciplina inserida com sucesso!" << endl;
                  break;
                case 2:
                      cin >> y;
                      p.remover(y);
                      break;
                     
                case 3:
                        cin >> y;
                        p.alterar(y);
                        break;
                case 4:
                        p.mostrarTodas();
                        do
                            cin>>ok;
                        while(ok!="Ok");
                        break;
                case 5:
                        
                        cin >> y >> w;
                        p.AnoSem(y,w);
                        do
                            cin>>ok;
                        while(ok!="Ok");
                        break;
                case 6:
                        p.mostrarP();
                        do
                            cin>>ok;
                        while(ok!="Ok");
                        break;
                case 7:
                         p.mostratudo();
                         do
                            cin>>ok;
                        while(ok!="Ok");
                        break;
                case 8:
                    cout<<"Obrigado por utilizar o programa de cadastro, volte sempre!"<<endl;
                    treco=false;
                    break;
            }    
        }while(treco==true);
        
      
 
  return 0;
}
