#include <iostream>
#include <string>
using namespace std;

class IPagamento{
    public:
        virtual void processar(float valor) = 0;
        virtual ~IPagamento(){};
};

class Pix : public IPagamento{
    public:
        void processar(float valor) override{
            cout << "Pix:␣" << valor << endl;
        }
};

class Cartao : public IPagamento{
    public:
        void processar(float valor) override{
            cout << "Cartao:␣" << valor << endl;
        }
};

void processarPagamento(IPagamento *pagamento, float valor);

int main(){
    IPagamento *p1 = new Pix();
    processarPagamento(p1, 100);
    delete(p1);

    return 0;
}

void processarPagamento(IPagamento *pagamento, float valor){
    pagamento -> processar(valor);
}