#include "jogador.h"

/*
Perguntar para o prof:
-como definir as classes iniciais e se elas vão ser outras classes de fato no código?
-sobre o nível nunca ser negativo, explicar que as classes iniciais já vem com um level pre-setado e não tem como ser menor que aquilo
*/

int main(){
    Jogador jogador1("Solaire", "Cavaleiro", 1, 0, 100, 10, 10, 10, 10, 10, 10, 10);
    jogador1.exibirStatus();

    return 0;
}
