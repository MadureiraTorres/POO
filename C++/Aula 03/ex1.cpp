#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*
criar classe Logger que abre um arquivo de texto e registra a data/hora de
início de sessão, a classe deve ter o método registrar(mensagem) para escrever no
arquivo; O destrutor deve registrar a a data/hora de encerramento e fechar o 
arquivo. Objetivo é garantir que o arquivo nunca fique aberto sem ser fechado.
*/

class Logger{
    private:
        ofstream file;
        time_t startTime;
        time_t endTime;

    public:
        Logger(const string& filename){
            file.open(filename, ios::app);
            startTime = time(nullptr);
            file << "Início da sessão: " << ctime(&startTime);
        }

        void registrar(const string& mensagem){
            if (file.is_open()){
                file << "[" << ctime(&endTime) << "] " << mensagem << endl;
            }
        }

        ~Logger(){
            endTime = time(nullptr);
            file << "Encerramento da sessão: " << ctime(&endTime);
            file.close();
        }
};

int main(){
    Logger logger("log.txt");
    logger.registrar("Esta é uma mensagem de log.");

    return 0;
}