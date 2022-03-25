#include<iostream>
#include<iomanip>
#include<list>


using namespace std;

class IPessoas
{
    public:
        virtual void ler()=0;
        virtual void mostrar()=0;
        virtual int getCodigo()=0;
        virtual string getNome()=0;
        virtual string getTipo()=0;
        virtual string getide()=0;
        virtual double getvalorIr()=0;
        virtual void mostrar2()=0;
        virtual void mos()=0;
};

class Cadastro : public IPessoas
{
    
        protected:
                int cod;
                string nome,jf,ide;
                double valor=0;
        public:
                virtual  void ler();
                virtual void mostrar()=0;
                virtual void mostrar2()=0;
                virtual void mos()=0;
                
                int getCodigo(){return cod;}
                string getNome() {return nome;}
                string getTipo(){return jf;}
                string getide(){return ide;}
                double getvalorIr(){return valor;}
                
                
};


void Cadastro::ler()
{
            cin>>cod;
            cin.ignore(); 
            getline (cin,nome);
            cin>>valor;
            cin.ignore(); 
            getline (cin,ide);
            
}


class fisica:public Cadastro
{
    private:
        string prof;
        int denp;

    public:
        string getProf2() {return prof;}
        int getdenp() {return denp;}
        void ler();
        void mostrar();
        void mostrar2();
        void mos();

};

void fisica::ler()
{
    Cadastro::ler();
    getline(cin, prof);
    cin>>denp ;
    jf="F";
}


void fisica::mostrar()
{
    cout  << setfill('0') << setw(5)<<right <<getCodigo() << "  "
        << setfill(' ') << setw(30) << left << getNome() << "  "
        << setw(2) <<getTipo() 
        << right << setw(21) << getide() << " "
        << "R$ " << setfill(' ')<< left << setw(9) << 0.07*getvalorIr() << endl;
        
}


void fisica::mos()
{
    cout << "R$ " << setfill(' ')<< left << setw(9) << 0.07*getvalorIr() << endl;
        
}



void fisica::mostrar2()
{
     cout << "Codigo : " << getCodigo()            << endl;
     cout << "Nome : " << getNome()             << endl;
     cout << "Renda Anual : " << getvalorIr()        << endl;
     cout << "CPF : " << getide()               << endl;
     cout << "Profissao : " << getProf2()   << endl;
     cout << "Dependentes : " << getdenp()    << endl;
}


class juridica:public Cadastro
{
    private:
        string mun;
        int ins;
        double auxiliar;
    public:
        string getMun() {return mun;}
        int getins() {return ins;}
        void ler();
        void mostrar();
        void mostrar2();
        void mos();
        void calcula();

};

void juridica::ler()
{
    Cadastro::ler();
    getline(cin, mun);
    jf="J";
    cin>>ins;if(valor>200000) auxiliar=  valor * 0.25 ;
    else  auxiliar =  valor*0.15 ;
}

void juridica::mostrar()
{
    
   
    cout << setfill('0') << setw(5)<<right << getCodigo() << "  "
    << setfill(' ') << setw(30) << left << getNome() << "  "
    << setw(2) << getTipo() 
    << right << setw(21) << getide() << " "
    << "R$ " << setfill(' ')<< left << setw(9) << auxiliar << endl;
    
}

void juridica::mos()
{
     cout << "R$ " << setfill(' ')<< left << setw(9) << auxiliar  << endl;
    
}



void juridica::mostrar2(){
     cout << "Codigo : " << getCodigo()        << endl;
     cout << "Nome : " << getNome()         << endl;
     cout << "Renda Anual : " << getvalorIr()    << endl;
     cout << "CNPJ : " << getide()         << endl;
     cout << "Inscr. Mun. : " << getMun()   << endl;
     cout << "Inscr. Est. : " << getins()   << endl;
}



class Dado {
private:
    list<IPessoas*>v;
public:
    void inserir(IPessoas* d);
    void remover(int e);
    void listar(IPessoas* d);
    void IR(int cod, IPessoas* d);
    void visualizar(int cod, IPessoas* d);
    
};

void Dado::IR(int cod, IPessoas* d){
    for(auto d:v)
    {
        if(d->getCodigo() == cod) 
        {
            d->mos();
        }
    }
}

void Dado:: visualizar(int cod, IPessoas* d)
{
    for(auto d:v)
    {
        if(d->getCodigo() == cod)
        {
            d->mostrar2();
        }
    }
}


void Dado::remover(int e)
{
    v.remove_if([e](const IPessoas* v){return((IPessoas*)v)->getCodigo()==e;});
} 


void Dado::listar(IPessoas* d){
    cout << "Codigo " << "Nome"   << setfill(' ')<< setw(30) << "F/J"<< setw(21) << "CPF/CNPJ"<< setw(13) << "IR" << endl;
    for (auto d : v)
    {
       d->mostrar();
    }
}

 
void Dado::inserir(IPessoas* d){
   v.push_back(d);
}

int menu(){
    int op;
    do{
        cout << "1 - inserir pessoa fisica" << endl
             << "2 - inserir pessoa juridica" << endl
             << "3 - remover" << endl
             << "4 - consultar" << endl
             << "5 - ir" << endl
             << "6 - listar" << endl
             << "7 - sair" << endl
             << "Entre com a sua escolha: "<<endl;
        cin >> op;
    } while (op < 1 || op > 7);
    return op;
}

int main()
{
        IPessoas* d;
        Dado c;
        bool ok = false;
        string e;
        int codigo;
        cout << setprecision(2) << fixed;
        do{
        switch (menu()){
        case 1:
            d = new fisica();
            d->ler();
            c.inserir(d);
            break;
        case 2:
            d = new juridica();
            d->ler();
            c.inserir(d);
            break;
        case 3:
            cin >> codigo;
            c.remover(codigo);
            break;
        case 4:
            cin >> codigo;
            c.visualizar(codigo, d);
            break;
        case 5:
            cin >> codigo;
            c.IR(codigo, d);              
            break;
        case 6:
            c.listar(d);
            break;
        case 7:
            cout << "Programa encerrado!" << endl;
            ok = true;
            break;
        default: 
            break;
        }
    }while (!ok);
}
