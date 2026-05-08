#include "pagamento.h"

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
