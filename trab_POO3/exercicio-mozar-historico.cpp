#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>


using namespace std;

class Dis
{
    public:
        virtual void ler(){}
        virtual void mostrar(){}
        virtual void mostrar2(){}
        virtual void mostrar3(){}
        virtual int getCodigo()   { return 0;      }
        virtual int getCreditos() { return 0;      }
        virtual int getSemestre() { return 0;      }
        virtual int getAno()      { return 0;      }
        virtual double getmono()    { return 0;      }
        virtual double getapre()    { return 0;      }
        virtual double getpra()    { return 0;      }
        virtual double getmedia()   {return 0;}
        
};

class tipo1 : public Dis{
	private:
        string mat, prof;
        double n1, n2, media;
        int cod, cre, sem, ano;
	public:
		void ler();
		void mostrar();
        int getCodigo()     {return cod;  };
        string getNome()    {return mat;    };
        int getCreditos()   {return cre;};
        int getAno()        {return ano;};
        int getSemestre()   {return sem;};
          double getmedia()  {return media;};
};

void tipo1::ler(){
    cout<<"codigo: ";
    cin >> cod;

    cin.ignore();
    cout<<"materia: ";
    getline (cin,mat);

    cout<<"creditos: ";
    cin >> cre;

    cout<<"ano: ";
    cin >> ano;

    cout<<"semestre:";
    cin >> sem;
 
    cout<<"nota 1: ";
    cin >> n1;
  
    cout<<"nota 2: ";
    cin >> n2;
    media=(n1 + 2.0*n2)/2.0;
}

void tipo1::mostrar(){
    cout << setprecision(2) << fixed;
    cout << setfill('0') << setw(4) << cod << " ";
    cout << setfill(' ') << setw(54) << left << mat;
    cout << right << cre << " " << right << ano << "/" << sem << " ";
    cout << setfill('0') << setw(5) << media << endl;
}


class tipo2 : public Dis{
		private:
        string mat, prof;
        double n1, n2, media;
        int cod, cre, sem, ano;
	public:
		void ler();
		void mostrar2();
        int getCodigo()     {return cod;  };
        string getNome()    {return mat;    };
        int getCreditos()   {return cre;};
        int getAno()        {return ano;};
        int getSemestre()   {return sem;};
          double getmedia()  {return media;};
};

void tipo2::ler(){
    cout<<"codigo: ";
    cin >> cod;

    cin.ignore();
    cout<<"materia: ";
    getline (cin,mat);

    cout<<"creditos: ";
    cin >> cre;

    cout<<"ano: ";
    cin >> ano;

    cout<<"semestre: ";
    cin >> sem;
 
    cout<<"nota 1: ";
    cin >> n1;
  
    cout<<"nota 2: ";
    cin >> n2;
    media=(n1 + 2.0*n2)/3.0;
}




void tipo2::mostrar2(){
    cout << setprecision(2) << fixed;
    cout << setfill('0') << setw(4) << cod << " ";
    cout << setfill(' ') << setw(54) << left << mat;
    cout << right << cre << " " << right << ano << "/" << sem << " ";
    cout << setfill('0') << setw(5) << media << endl;
}


class tipo3 : public Dis{
		private:
        string mat;
        double apre,pra, mono, media;
        int cod, cre, sem, ano;
	public:
		void ler();
		void mostrar3();
          int getCodigo()     {return cod;};
        string getNome()    {return mat;};
        int getCreditos()   {return cre;};
        int getAno()        {return ano;};
        int getSemestre()   {return sem;};
    	double getmono()    { return mono; };
        double getapre()    { return apre; };
        double getpra()    { return pra;};
        double getmedia()   {return media;};
        
};

void tipo3::ler(){
    cout<<"codigo: ";
    cin >> cod;

    cin.ignore();
    cout<<"materia: ";
    getline (cin,mat);

    cout<<"creditos: ";
    cin >> cre;

    cout<<"ano: ";
    cin >> ano;

    cout<<"semestre: ";
    cin >> sem;
    
    cout<<"monografia: ";
    cin >> mono;
    cout<<"apresentcao: ";
    cin >> apre;
    cout<<"pratica: ";
    cin>> pra;
    media=(2*mono + 3*apre + pra)/6;
}

void tipo3::mostrar3(){
    if(media>=7){
    
    cout << setprecision(2) << fixed;
    cout << setfill('0') << setw(4) << cod << " ";
    cout << setfill(' ') << setw(54) << left << mat;
    cout << right << cre << " " << right << ano << "/" << sem << " "<<endl;
    cout << "monografia    apresentacao    pratica    media" << endl;
   cout << mono <<"            " << apre <<"           " << pra << "     ";
    cout << setfill('0') << setw(5) << media << endl;
    }
}


class His {
private:
    Dis* v[100];
    int qtd;

public:
    His();
    virtual ~His();
    int achar(int x);
    void inserir(Dis *d);
    void remover(int x);
    void alterar(int x);
    void l();
    void l2();
    void l3();
};

His::His(){
    qtd = 0;
}


His::~His(){
    for (int i = 0; i < qtd; i++)
        delete v[i];
}

Dis* criar(){
    int opc;
    do{
        cout<<"_____escolha__um__tipo__de__listagem_______"<<endl;
        cout << "1 - listagem 1" << endl;
        cout << "2 - listagem 2" << endl;
        cout << "3 - listagem 3" << endl;
        cout<<"------------------------------------------"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opc;
    } while (opc < 1 || opc > 3);
    switch (opc){
    case 1:
        return new tipo1();
    case 2:
        return new tipo2();
    case 3:
        return new tipo3();
    default:
        cout << endl
             << "Opcao invalida!" << endl;
        exit(0);
    }
}

void His::inserir(Dis *d){
    v[qtd] = d;
    qtd++;
}

int His::achar(int x)
{
  int codigo, i = 0;
    bool achou = 0;
    while ( achou==0 && i < qtd )
    {
        if ( v[i]->getCodigo() == x )
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
        v[posicao]->ler();
        cout << "Disciplina alterada com sucesso!" << endl;
    }
    else 
        cout << "Disciplina nao encontrada!" << endl;
}

void His::l(){
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for (int i = 0; i < qtd; i++){
        v[i]->mostrar();
    }
}

void His::l2(){
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for (int i = 0; i < qtd; i++)
        v[i]->mostrar2();
}

void His::l3(){
    cout << "Cod. Nome                                               Cred  Ano/S" << endl;
    for (int i = 0; i < qtd; i++)
        v[i]->mostrar3();
}





int menu(){
    int opc;
    do{
        cout<<"________________HISTORICO _____________________"<<endl;
        cout << "1. inserir disciplina" << endl
             << "2. remover disciplina pelo codigo" << endl
             << "3. alterar dados da disciplina dado o codigo" << endl
             << "4. listar todas as disciplinas" << endl
             << "5. listar todas as disciplinas do tipo 2" << endl
             << "6. listar todoas as disciplinas do tipo 3" << endl
             << "7. Sair" << endl
             <<"_____________________________________________"<<endl
             << "Escolha uma opcao: ";
        cin >> opc;
    } while (opc < 1 || opc > 7);

    return opc;

}


int main(){
    Dis* d;
    His h;
    bool treco = false;
    int x;
    do{
        switch (menu()){
        case 1:
            d = criar();
            d->ler();
            h.inserir(d);
            cout << "Inserida com sucesso!" << endl;
            break;
        case 2:
            cin >> x;
            h.remover(x);
            cout << "Removida com sucesso!" << endl;
            break;
        case 3:
            cin >> x;
            d->ler();
            h.alterar(x);
            cout << "Alterada com sucesso!" << endl;
            break;
        case 4:
            h.l();
            break;
        case 5:
            h.l2();
            break;
        case 6:
            h.l3();
            break;
        case 7:
            treco = true;
            cout << "Obrigado por utilizar nosso programa <3" << endl;
        }
    }while(treco!=true);
}








    }while(treco!=true);
}
