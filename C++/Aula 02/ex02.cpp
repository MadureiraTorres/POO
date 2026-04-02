#include "cronometro.h"

void esperar(int segundos);

int main(){
    Cronometro c;

    // Testando o cronômetro
    c.iniciar();
    esperar(2);
    c.volta();    
    
    esperar(1);
    c.parar();
    c.exibirTempo(); 

    c.iniciar();
    esperar(1);
    c.exibirTempo(); 

    c.resetar();
    c.exibirTempo();

    return 0;
}

void esperar(int segundos){
    auto inicio = chrono::steady_clock::now();
    while (chrono::duration<double>(chrono::steady_clock::now() - inicio).count() < segundos);
}