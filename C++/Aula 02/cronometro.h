#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

/*
armazenar tempo com precisão, mas sem o usuário saver como o tempo é armazenado internamente
atributos privados:
- tempo_inicio (marca o momento iniciado)
- tempo_total (acumula o tempo entre paradas)
- rodando (booleano que indica se está em contagem)

métodos públicos:
- iniciar()
- parar()
- resetar()
- exibir_tempo()

métodos privados:
- registrar_volta(), exibir tempo da volta sem parar a contagem
- tempo_decorrido(), calcular intervalo desde o último iniciar

principal restrição:  O código externo nunca manipula tempo_inicio diretamente.
Não deve ser possível “trapacear” o cronômetro atribuindo um valor falso ao tempo.
*/

class Cronometro{
    private:
        time_point<steady_clock> tempoInicio;
        duration<double> tempoTotal;
        bool rodando;

        void registrarVolta(){
            double volta = tempoDecorrido().count();
            cout << "Tempo da volta: " << volta << " segundos" << endl;
        }

        duration<double> tempoDecorrido() const{
            return steady_clock::now() - tempoInicio;
        }

    public:
        Cronometro() : tempoTotal(0), rodando(false){}

        void iniciar(){
            if(!rodando){
                tempoInicio = steady_clock::now();
                rodando = true;
            }
        }

        void parar(){
            if(rodando){
                tempoTotal += tempoDecorrido();
                rodando = false;
            }
        }

        void resetar(){
            tempoTotal = duration<double>(0);
            rodando = false;
        }

        void exibirTempo(){
            double exibir = tempoTotal.count();
            if (rodando){
                exibir += tempoDecorrido().count();
            }
            cout << "Tempo total: " << exibir << " segundos" << endl;
        }

        void volta(){
            if(rodando){
                registrarVolta();
            } else {
                cout << "O cronômetro não está rodando. Inicie para registrar uma volta." << endl;
            }
        }
};

#endif