#2. Um cronômetro de competição deve registrar tempos com precisão, mas o usuário não
#precisa — nem deve — saber como o tempo é armazenado internamente. O que importa é
#apertar “iniciar”, “parar” e ver o resultado. Implemente versões em Python e C++ para uma
#classe de Cronometro com as seguintes características.
# • Atributos privados:
# -tempo_inicio (marca o momento em que foi iniciado),
# -tempo_total (acumula o tempo entre paradas) e
# -rodando (booleano que indica se está em contagem).
#• Métodos públicos:
# -iniciar() começa a contagem — se já estiver rodando, exibe aviso;
# -parar() interrompe e acumula o tempo decorrido — se já estiver parado, exibe
#aviso;
# -resetar() zera tudo;
# -exibir_tempo() mostra o tempo total acumulado em segundos com duas casas
#decimais.
#• Métodos privados:
# -registrar_volta(), que exibe o tempo da volta atual sem parar a contagem;
# -tempo_decorrido() que calcula o intervalo desde o último iniciar.
#• Principal restrição: O código externo nunca manipula tempo_inicio diretamente.
#Não deve ser possível “trapacear” o cronômetro atribuindo um valor falso ao tempo.
#Dica: Em Python, use o módulo time e a função time.time().#

import time

class Cronometro:    

    def __init__(self):
        self.__tempo_inicio = 0
        self.__tempo_total = 0
        self.__rodando = False

    def iniciar(self):
        if not self.__rodando:
            self.__tempo_inicio = time.time()
            self.__rodando = True
        else:
            print("Aviso: O cronômetro já está rodando.")

    def parar(self):
        if self.__rodando:
            self.__tempo_total += self.__tempo_decorrido()
            self.__rodando = False
        else:
            print("Aviso: O cronômetro já está parado.")

    def resetar(self):
        self.__tempo_inicio = 0
        self.__tempo_total = 0
        self.__rodando = False

    def exibir_tempo(self):
        total = self.__tempo_total
        if self.__rodando:
            total += self.__tempo_decorrido()
        print(f"Tempo total: {total:.2f} segundos")

    def __tempo_decorrido(self):
        if self.__rodando:
            return time.time() - self.__tempo_inicio
        return 0

    def __registrar_volta(self):
        if self.__rodando:
            print(f"Tempo da volta atual: {self.__tempo_decorrido():.2f} segundos")

if __name__ == "__main__":
    import time
    c = Cronometro()
    c.iniciar()
    time.sleep(1.5)
    c.exibir_tempo()
    c.parar()
    c.exibir_tempo()
    c.resetar()
    c.exibir_tempo()
