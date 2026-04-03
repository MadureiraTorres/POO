#include "jogador.h"

/*
Perguntar para o prof:
-como definir as classes iniciais e se elas vão ser outras classes de fato no código?
-sobre o nível nunca ser negativo, explicar que as classes iniciais já vem com um level pre-setado e não tem como ser menor que aquilo
*/

int main(){
    Jogador jogador1("Rafael", "Guerreiro", 1, 0, 10, 5, 5, 10, 5, 5, 5, 5, 100, 50);
    jogador1.exibirStatus();

    //recebendo um dano de 20 pontos
    jogador1.receberDano(20);
    cout << "\nApós receber 20 pontos de dano:\n";
    jogador1.exibirStatus();

    //curando 10 pontos de vida
    jogador1.curar(10);
    cout << "\nApós curar 10 pontos de vida:\n";
    jogador1.exibirStatus();

    return 0;
}
