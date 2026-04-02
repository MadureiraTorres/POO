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

#endif