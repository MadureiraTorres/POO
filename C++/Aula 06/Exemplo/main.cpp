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
    processarPagamento(p1, 100);
    delete(p1);

    return 0;
}

//demais funções
void processarPagamento(IPagamento *pagamento, float valor){
    pagamento -> processar(valor);
}