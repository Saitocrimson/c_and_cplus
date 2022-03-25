#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <list> 


using namespace std; 

class Agenda {
    protected:
        string nome, email, cel;
    public:
        void ler();
        string getNome()  { return nome; }
        string getEmail() {return email;}
        string getCel()    { return cel;}
};

void Agenda::ler(){ 

    cin.ignore();
    getline(cin, nome);
    getline(cin, email);
    getline(cin, cel);
}


class Mc {
   private:
        list< Agenda> V;
   public:
        void inserir(Agenda d);
        void remover(string e);
        void listar(Agenda d);
};


void Mc::inserir(Agenda d){
   V.push_back(d);
}

void Mc::remover(string e)
{
     V.remove_if([e](const Agenda& V){return((Agenda)V).getEmail()==e;});
} 


void Mc::listar(Agenda d){
    cout<< "Nome Email                  Telefone" << endl;
    for (auto d : V)
    {
        cout <<right <<d.getNome()<<"  "; 
        cout << setfill(' ') << setw(20) << left <<d.getEmail();
        cout << setfill(' ') << setw(3) << " " <<d.getCel();
        cout<< endl;
    }
}

int menu(){
    int num;
     do{
     cout <<    "1 - inserir" << endl
             << "2 - remover" << endl
             << "3 - listar" <<endl  
             << "4 - sair" << endl
             << "Entre com a sua escolha: "<<endl;
             cin >> num;
         
     } while (num < 1 || num > 4);
     return num;
} 

int main()
{
        Agenda d;
        Mc c;
        bool ok = false;
        string e;
        do{
   switch (menu()){
        case 1:
           d.ler(); 
           c.inserir(d); 
           break;
         case 2: 
            cin.ignore();
            getline(cin, e);
            c.remover(e);
            break;
         case 3:
            c.listar(d);break;
          case 4:
            ok = true;
            break; 
        default:
            break;
       
   } 
    }while(ok!=true);

cout<<"Programa encerrado!"<<endl;
}
