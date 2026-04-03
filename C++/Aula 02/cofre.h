#ifndef COFRE_H
#define COFRE_H

/*
atribtos privados:
– combinacao: string definida na criação do objeto,
– conteudo: lista de itens guardados, inicia vazia,
– aberto: booleano,– tentativas_erradas: contador, inicia em zero
– bloqueado: booleano, inicia como falso

metodos públicos:
- abrir(combinacao): verifica a combinação.  se correta, abre o cofre e zera o
contador de erros; se errada, incrementa o contador e bloqueia após três falhas;
- fechar(): fecha o cofre, se estiver aberto
- guardar(item): adiciona um item ao conteúdo, se o cofre estiver aberto
- retirar(item): remove um item do conteúdo, se o cofre estiver aberto
- listarConteudo(): exibe os itens guardados, se o cofre estiver aberto
- estaBloqueado(): retorna se o cofre está bloqueado

metodos privados:
- verificarAcesso(): checa se o cofre está aberto e não bloqueado, chamado por
guardar e retirar
- listarConteudo(): para evitar repetição
- resetarBloqueio(codigoMaster): aceita uma senha mestra diferente da normal, desbloqueia
o cofre e zera o contador de erros

principal restrição: o código externo nunca acessa conteudo, combinacao ou 
aberto diretamente.

*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Cofre {
    private:
        string combinacao;
        list<string> conteudo;
        bool aberto;
        int tentativas_erradas;
        bool bloqueado;

        bool verificarAcesso() const{
            return aberto && !bloqueado;
        }

    public:
        Cofre(const std::string& combinacao)
            : combinacao(combinacao),
            aberto(false),
            tentativas_erradas(0),
            bloqueado(false){}

        bool abrir(const std::string& tentativa){
            if (bloqueado){
                cout << "Cofre bloqueado! Use resetarBloqueio().\n";
                return false;
            }
            if (tentativa == combinacao){
                aberto = true;
                tentativas_erradas = 0;
                cout << "Cofre aberto com sucesso.\n";
                return true;
            } else{
                tentativas_erradas++;
                cout << "Combinação errada. Tentativas: " << tentativas_erradas << "/3\n";
                if (tentativas_erradas >= 3){
                    bloqueado = true;
                    cout << "Cofre BLOQUEADO após 3 tentativas erradas!\n";
                }
                return false;
            }
        }

        void fechar(){
            if (aberto){
                aberto = false;
                cout << "Cofre fechado.\n";
            } else{
                cout << "O cofre já está fechado.\n";
            }
        }

        void guardar(const std::string& item) {
            if (!verificarAcesso()) {
                cout << "Acesso negado: cofre fechado ou bloqueado.\n";
                return;
            }
            conteudo.push_back(item);
            cout << "Item \"" << item << "\" guardado.\n";
        }

        void retirar(const std::string& item){
            if (!verificarAcesso()){
                cout << "Acesso negado: cofre fechado ou bloqueado.\n";
                return;
            }
            auto it = find(conteudo.begin(), conteudo.end(), item);
            if (it != conteudo.end()){
                conteudo.erase(it);
                cout << "Item \"" << item << "\" retirado.\n";
            } else{
            cout << "Item \"" << item << "\" não encontrado.\n";
            }
        }

        void listarConteudo() const{
            if (!verificarAcesso()){
                cout << "Acesso negado: cofre fechado ou bloqueado.\n";
                return;
            }
            if (conteudo.empty()){
                cout << "O cofre está vazio.\n";
                return;
            }
            cout << "Conteúdo do cofre:\n";
            for (const auto &item : conteudo){
                cout << "  - " << item << "\n";
            }
        }

        bool estaBloqueado() const{
            return bloqueado;
        }

        void resetarBloqueio(const string &codigoMaster){
            const string SENHA_MESTRA = "MASTER_2024";
            if (codigoMaster == SENHA_MESTRA){
                bloqueado = false;
                tentativas_erradas = 0;
                cout << "Bloqueio resetado com sucesso.\n";
            }
            else{
                cout << "Código mestre inválido.\n";
            }
        }
};


#endif