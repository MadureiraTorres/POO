#include <iostream>
#include <string>
using namespace std;


// Definição de classes
class IPagamento{
    public:
        virtual void processar(float valor) = 0;
        virtual ~IPagamento(){};
};

class IAutenticavel{
    public:
        virtual void autenticar() = 0;
        virtual ~IAutenticavel(){};
};

class Pix : public IPagamento{
    public:
        void processar(float valor) override{
            cout << "Pix: " << valor << endl;
        }
};

class Cartao : public IPagamento, public IAutenticavel{
    public:
        void processar(float valor) override{
            //autenticar();
            cout << "Cartao: " << valor << endl;
        }
        void autenticar() override{
            cout << "Cartao autenticado" << endl;
        }
};

//cabeçalho de funções
void processarPagamento(IPagamento *pagamento, float valor);

//main
int main(){
    IPagamento *p1 = new Pix();
    IPagamento *p2 = new Cartao();

    cout << endl;
    processarPagamento(p1, 100);
    cout << endl;
    processarPagamento(p2, 200);
    cout << endl;


    delete(p1);
    delete(p2);

    return 0;
}

//demais funções
void processarPagamento(IPagamento *pagamento, float valor){
    pagamento -> processar(valor);
}