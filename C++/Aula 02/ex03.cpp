#include "cofre.h"

int main(){
    Cofre cofre("1234");

    // Tenta guardar sem abrir
    cofre.guardar("Passaporte");

    // Tentativas erradas de abertura
    cofre.abrir("0000");
    cofre.abrir("4321");
    cofre.abrir("9999"); // bloqueia aqui

    // Tenta abrir com combinação correta (bloqueado)
    cofre.abrir("1234");

    // Reseta o bloqueio
    cofre.resetarBloqueio("MASTER_2024");

    // Abre corretamente
    cofre.abrir("1234");

    // Operações com o cofre aberto
    cofre.guardar("Passaporte");
    cofre.guardar("Dinheiro");
    cofre.guardar("Joias");
    cofre.listarConteudo();

    cofre.retirar("Dinheiro");
    cofre.retirar("Notebook"); // item inexistente
    cofre.listarConteudo();

    // Fecha e tenta operar fechado
    cofre.fechar();
    cofre.guardar("Documento");
    cofre.listarConteudo();

    return 0;
}