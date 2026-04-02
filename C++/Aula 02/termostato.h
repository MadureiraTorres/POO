#ifndef TERMOSTATO_H
#define TERMOSTATO_H

#include <iostream>
#include <string>
using namespace std;

/*
implementar classe termostato
-atributos privados: temperatura, ligado
-métodos públicos: ligar, desligar, aumentar(graus), diminuir(graus), exibirEstado()
-métodos privados: validarTemperatura(graus)
!nenhum código externo à classe pode ler ou alterar a temperatura diretamente, só pelos 
métodos públicos!

restrições:
-nenhum código externo à classe pode ler ou alterar a temperatura diretamente, só pelos 
métodos públicos!
-aumentar e diminuir só funcionam se o termostato estiver ligado e só são permitidos se
o resultado foir entre 0 e 40 graus (exibir mensagem de erro caso contrário)
*/

class Termostato{
    private:
        float temperatura;
        bool ligado;

        bool validarTemperatura(float graus){
            if(graus < 0 || graus > 40){
                cout << "Temperatura inválida! A temperatura deve estar entre 0 e 40 graus." << endl;
                return false;
            }
            return true;
        }

    public:
        Termostato() : temperatura(20), ligado(false){} // Construtor padrão, tirar dúvida sobre este tipo de construtor com o prof

        void ligar(){
            ligado = true;
            cout << "Termostato ligado." << endl;
        }

        void desligar(){
            ligado = false;
            cout << "Termostato desligado." << endl;
        }

        void aumentar(float graus){
            if(ligado){
                float novaTemperatura = temperatura + graus;
                if(validarTemperatura(novaTemperatura)){
                    temperatura = novaTemperatura;
                    cout << "Temperatura aumentada para " << temperatura << " graus." << endl;
                }
            } else {
                cout << "O termostato está desligado. Ligue-o para ajustar a temperatura." << endl;
            }
        }

        void diminuir(float graus){
            if(ligado){
                float novaTemperatura = temperatura - graus;
                if(validarTemperatura(novaTemperatura)){
                    temperatura = novaTemperatura;
                    cout << "Temperatura diminuída para " << temperatura << " graus." << endl;
                }
            } else {
                cout << "O termostato está desligado. Ligue-o para ajustar a temperatura." << endl;
            }
        }

        void exibirEstado(){
            cout << "Termostato está " << (ligado ? "ligado" : "desligado") 
                 << " com temperatura de " << temperatura << " graus." << endl;
            cout << "-----------------------------" << endl;
        }
};

#endif