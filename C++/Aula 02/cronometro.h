#include <iostream>
#include <string>
using namespace std;

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

};