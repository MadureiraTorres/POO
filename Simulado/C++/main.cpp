//sistema heimdall

//descrição 
/*
Registrar operações de retirada e devolição de chaves, armazenando 
informações sobre os usuários responsáveis, horários de movimentação e
situação cadastral de cada chave. 

Disponibilizar uma interface que permita visualizar quais chaves estão
disponíveis, emprestadas ou em atraso.

Cada chava deve estar associada a um ambiente específico da instituição

Usuários previamente cadastrados e autorizados poderão solicitar a 
retirada de uma chave para a utilização temporária

Ao realizar uma retirada, o sistema deverá registrar o usuário 
responsável, a chave solicitada, o carimbo de data/hora da retirada, a
previsão de devolução e a justificativa de uso.

Quando a chave for devolvida, o sistema registrará o momento exato da
devolução e atualizará o status do objeto chave.

O sistema também deverá permitir consultas e auditorias sobre o 
histórico de movimentações.
*/

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//requisitos funcionais
/*
1 - cadastrar, editar e remover usuários autorizados (distinguindo seus
papéis).

2 - cadastrar, editar e remover ambientes da instituição.

3 - cadastrar, editar e remover chaves físicas.

4 - associar cada chave de forma unívoca a um ambiente específico.

5 - registrar a operação de retirada (empréstimo) de uma chave por um
usuário.

6 - registrar a operação de devolução de uma chave, calculando eventuais
atrasos.

7 - consultar o histórico completo de movimentações de uma chave 
específica.

8 - consultar a listagem de todas as chaves atualmente emprestadas.

9 - identificar e listar de forma isolada as chaves com devolução em 
atraso.

10 - exibir um painel informando a situação atual de todas as chaves do
catálogo.

11 - gerar relatórios textuais de utilização (frequência de uso por 
ambiente ou usuário).
*/

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//regras de negócio
/*
1 - apenas usuários ativos e devidamente autorizados podem retirar
chaves.

2 - uma chave só pode estar sob a posse de um único usuário por vez.

3 - não é permitido realizar a retirada de uma chave cujo status atual
seja "emprestada".

4 - toda operação de retirada e devolução deve registrar o timestamp
exato do evento.

5 - o fechamento de um empréstimo deve calcular se o prazo previsto foi
respeitado.

6 - não é permitido a exclusão lógica ou física de chaves que possuam 
empréstimos ativos.

7 - o histórico de movimentações é imutável (não pode ser alterado ou
apagado) para fins de auditoria.

8 - chaves cuja data atual ultrapasse a data prevista de devolução
devem ter seu estado alterado para "em atraso".
*/

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//requisitos de projeto e implementação 
/*
encapsulamento: atributos estritamente privados com métodos de acesso
(getters/setters) sintonizados às necessidades de negócio (evitar 
exposição desnecessária).

herança e polimorfismo: utilização de superclasses (ou interfaces) para
especialização de tipos de usuários aplicando polimorfismo em métodos
cujas regras variem por categoria.

tratamento de exceções: lançamento e captura de exceções customizáveis
para violações de regras de negócio (ex: tentar retirar chave 
indisponível).

associações: modelagem correta de relacionamentos 1:1, 1:N e N:M 
(agregação/composição) entre os objetos do domínio.

arquitetura: sepração clara entre as classes de entidade, a camada de
negócio (seviços/controladores) e a interface com o usuário (UI CLI ou
GUI).
*/

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=