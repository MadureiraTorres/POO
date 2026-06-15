#include "jogador.h"

int main(){
    Jogador p1("Player", 1, 100);
    
    //testes
    cout << "Status inicial" << endl;
    p1.exibirStatus();

    cout << endl;
    cout << "Status pós-dano" << endl;
    p1.receberDano(15);
    p1.exibirStatus();

    cout << endl;
    cout << "Status pós curar" << endl;
    p1.curar(5);
    p1.exibirStatus();

    cout << endl;
    cout << "Status morto" << endl;
    p1.receberDano(100);
    p1.exibirStatus();

    cout << endl;
    cout << "Status final (não cura se estiver morto)" << endl;
    p1.curar(500);
    p1.exibirStatus();


    return 0;
}