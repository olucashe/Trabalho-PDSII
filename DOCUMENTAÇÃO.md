# Projeto "Sistema de Gerenciamento de Biblioteca" <h1>
O Sistema de Biblioteca é uma abstração de um sistema de Gerência de Biblioteca. Esse projeto é um trabalho da disciplina de Programação e Desenvolvimento de Software II e foi desenvolvida com base na linguagem C++, usando os Conceitos trabalhados 
durante o semestre, dentre eles Abstração, Encapsulamento, Herança e Polimorfismo,
Modularidade e componentes reusáveis, Tratamento de exceções, entre outros conceitos abordados na disciplina.
  
  
 ## Introdução ao projeto:
  Para começar, iremos enumerar as histórias de usuário(User Stories) e explicá-las. As histórias de usuário abaixo descrevem o que um usuário faz ou necessita fazer como parte de sua função no projeto, tendo como base um administrador da biblioteca e um usuário comum como pessoas que usarão o código. Essas histórias de usuário guiaram o desenvolvimento do trabalho e o objetivo era fazer o que foi proposto nelas.  
  


## ☕ User Stories
    
### 1. Cadastro de livros

Como administrador da biblioteca quero poder executar uma lista de ações, ver lista dos livros, pesquisar por esses livros, adicionar e modificar os livros.

### 2. Cadastro ou modificação de livros

Como bibliotecario quero ter a capacidade fazer alterações nos livros, por classificação através da pesquisa pelo seu nome ou seu ID. Diante disso, ele poderá mudar as características dos livros.

### 3. Cadastro de Livros

Como usuário, desejo poder ver todos os livros disponíveis na biblioteca, bem como seu titulo, autor e seu ID. Também gostaria de saber o seu preços para compra. Além disso, vai ser possível fazer uma pesquisa com os dados dos livros.

### 4. Banco de dados de Livros

Como administrador, desejo ter um banco de dados com os dados dos meus livros, de maneira que a cada vez inicio o programa, a persistência de dados se perpetua. Desejo poder adicionar livros novos no banco de dados, bem como editar o livro e marcar como vendido. Desejo imprimir o titulo e ter a opção de salvar os dados editados no meu banco ou não.

### 5. Contabilizar Empréstimo

Como administrador, desejo saber quais livros já emprestei, qual estudante que pegou o livro e os dados do livro e do estudante. Desejo listar os livros já emprestados e ver o relatório detalhado conforme os dados citados.

### 6. Realizar  Empréstimo

Como administrador, quero poder emprestar um livro para algum estudante desde que sejam informado, seu nome, ID, e o nome do livro, a partir dessas informações é possível emprestar esse livro e também ver a lista dos livros que foram alocados para os estudantes.

### 7. Pesquisa por livros 

Como administrador ou estudante, quero ser capaz de pesquisar e ver os dados dos livros, que são dividos por suas respectivas categorias. Sendo assim, vai ser possível ver o nome do livro, o autor e seu ID.

### 8. Banco de dados de Empréstimo

Como administrador, desejo saber para quem empreste cada livro, armazenando este dado em um banco de dados de empréstimo, no qual informa o nome do estudante os dados do livro.

### 9. Emprestar livro mais de uma vez

Como administrador, desejo ter a opção de emprestar um livro mais de uma vez para um estudante, para conseguir executar tal operação, será necessário o ID e o nome do estudante.

### 10. Mudar dados do administrador

Como administrador, desejo ter a opção de fazer outra senha para substituir a antiga que por definição é pass, sendo assim será possível alterar a senha para executar as ações do administrador.
  
  
  
  ## Detalhamento do Projeto:
  Como citado acima, o projeto foi desenvolvido em C++ e tem como base o uso da Programação orientada a objetos. A seguir enumeraremos as classes usadas no projeto e a função de cada uma no código.
  
1. Biblioteca
Essa Classe apresenta um arquivo cpp com os métodos devidamente aplicados e um arquivo hpp. Nessa classe, temos:
* Variáveis char: bookname (nome do livro), auname(nome do autor) , sc, sc1
* Variáveis int: q, B, P
  
  Além disso, nessa classe, temos as funções:
  * get: Função principal do programa
  * student: Função que mostra o painel do estudante
  * pass: Função que verifica a senha do bibliotecário
  * librarian: Função que mostra o painel do bibliotecário
  * password: Função de gerenciamento de senha
  * getdata: Função que adiciona um livro na biblioteca
  * show: Função que mostra os dados de um livro
  * booklist: Função que mostra os dados dos livros
  * modify: Função que modifica os dados de um livro
  * see: Função que mostra todos os livros de um determinado tipo
  * branch: Função que mostra todos os tipos de livros
  * issue: Função que gerencia o emprestimo de livros
  * der: Função que verifica se o livro está disponível
  * fine: Função que calcula a multa
  
2. File
Essa classe é uma classe mãe e faz a leitura de algo.
  
3. FilePassword
Essa classe herda o método da classe File. Com ela, conseguimos fazer a leitura da senha do Bibliotecário de um arquivo txt, e essa senha por padrão é "pass".
  
