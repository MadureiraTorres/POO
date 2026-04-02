#include "termostato.h"

int main(){
    Termostato t;

    // Testando o termostato
    t.exibirEstado();

    //ligando, aumentando, exibindo estado
    t.ligar();
    t.aumentar(5);
    t.exibirEstado();

    //diminuindo, exibindo estado
    t.diminuir(3);
    t.exibirEstado();

    //desligando, exibindo estado
    t.desligar();
    t.exibirEstado();

    //tentando aumentar temperatura com termostato desligado
    t.aumentar(2);
    t.exibirEstado();

    //tentando aumentar temperatura para um valor inválido
    t.ligar();
    t.aumentar(30);
    t.exibirEstado();

    return 0;
}
