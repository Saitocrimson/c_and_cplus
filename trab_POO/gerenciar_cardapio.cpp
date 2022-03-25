#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

class Pedido{
    protected:
       string nome;
       int codigo;
       double preco=0;
    public:
        void ler();
        string getNome()                { return nome; }
        int getCodigo()                 { return codigo;}
        double getPreco()               { return preco;}
        void Preco2 (double t)          {preco=t;}
};

void Pedido::ler(){
    cin >> codigo;
    cin.ignore();
    getline(cin, nome);
    cin >> preco;
}


class Mc {
    private:
        Pedido v[20];
        int qtd=0;
        

    public:
        int achar(int busca);
        void inserir(Pedido d);
        void remover(int busca);
        void alterar(int busca, double t );
        void listar();
        void valore(int x);
};



void Mc::inserir(Pedido d){
    v[qtd] = d;
    qtd++;
}

int Mc::achar(int busca){
    bool encontrei = false;
    int i = 0;
    while (!encontrei && i < qtd){
        if (busca == v[i].getCodigo())
            encontrei = true;
        else
            i++;
    }
    return encontrei ? i : -1;
}

void Mc::remover(int busca){
    int pos = achar(busca);
    for (int i = pos + 1; i < qtd; i++)
        v[i-1] = v[i];
    qtd--;
}

void Mc::alterar(int busca, double t){
   
    int pos = achar(busca);
    v[pos].Preco2(t);
}

void Mc::listar(){
    cout<< "Codigo Nome                             Preco" << endl;
    cout << setprecision(2) << fixed;
    for (int i = 0; i < qtd; i++){
        cout << setfill('0')<<setw(5) << right <<v[i].getCodigo()<<"  "; 
        cout << setfill(' ') << setw(20) << left <<v[i].getNome();
        cout << setfill('0') << setw(3) << "R$ " <<v[i].getPreco();
        cout<< endl;
    }
}

void Mc::valore(int x)
{
    int p= achar(x);
    if(p >-1)cout<<"R$ "<<v[p].getPreco()<<endl;
    else cout<<"R$ 0.00"<<endl;
}


int menu(){
    int opc;
    do{
        cout << "1 - inserir" << endl
             << "2 - remover" << endl
             << "3 - consultar" << endl
             << "4 - alterar" << endl
             << "5 - listar" << endl
             << "6 - sair" << endl
             << "Entre com a sua escolha: "<<endl;
        cin >> opc;
    } while (opc < 1 || opc > 6);
    return opc;
}

int main(){
    Pedido d;
    Mc h;
    bool fim = false;
    int x;
    double t;
    
    do{
        switch (menu()){
        case 1:
            d.ler();
            h.inserir(d);
            break;
        case 2:
            cin >> x;
            h.remover(x);
            break;
          
        case 3:
           cin>>x;
           h.valore(x);
           break;
        case 4:
            cin >> x;
            cin >> t;
            h.alterar(x, t);
            break;
        case 5:
            h.listar();
            break;
        case 6:
            fim = true; 
            break;
        default:
           menu();
            break;
        }
    }while(fim!=true);
    cout<<"Programa encerrado!"<<endl;
}   
