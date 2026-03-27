#include <iostream>
using namespace std;

class Radio {
private:
    bool ligada;
    int volume;
    float estacao;
    float predefinicoes[6];

public:
    Radio() {
        ligada = false;
        volume = 5;
        estacao = 90.7f;
        predefinicoes[0] = 90.7f;
        predefinicoes[1] = 92.3f;
        predefinicoes[2] = 94.7f;
        predefinicoes[3] = 98.1f;
        predefinicoes[4] = 105.7f;
        predefinicoes[5] = 107.7f;
    }

    void ligarDesligar() {
        ligada = !ligada;
    }

    void setPredefinicao(int ind) {
        if (ind >= 0 && ind < 6)
            predefinicoes[ind] = estacao;
    }

    void irParaPredefinicao(int ind) {
        if (ind >= 0 && ind < 6)
            estacao = predefinicoes[ind];
    }

    void aumentarVolume() {
        volume = volume + 1;
    }

    void diminuirVolume() {
        volume = volume - 1;
    }

    void aumentarEstacao() {
        estacao = estacao + 0.2f;
    }

    void diminuirEstacao() {
        estacao = estacao - 0.2f;
    }

    float getEstacao() {
        return estacao;
    }
};

// Teste
int main() {
    Radio r;
    r.ligarDesligar();
    r.aumentarVolume();
    r.aumentarEstacao();
    r.setPredefinicao(0);
    r.irParaPredefinicao(0);
    cout << r.getEstacao() << endl;

    return 0;
}