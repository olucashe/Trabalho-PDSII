<div id="top"></div>

# Trabalho-PDSII: Sistema de Gerência de Biblioteca 

> O Sistema de Biblioteca é uma abstração de um sistema de Gerência de Biblioteca.

[![Contributors][contributors-shield]][contributors-url]
[![Tamanho][tamanho-shield]][tamanho-url]
[![Linguagens][linguagens-shield]][linguagens-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<br/>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Sumário</summary>
  <ol>
    <li>
      <a href="">O Projeto</a>
    </li>
    <li>
      <a href="#começando-">Começando 🚀</a>
      <ul>
        <li><a href="#pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#instalação">Instalação</a></li>
      </ul>
    </li>
    <li><a href="#">Como utilizar o Projeto</a></li>
    <li><a href="#contruibuindo">Contruibuindo</a></li>
    <li><a href="#-user-stories">☕ User Stories</a></li>
    <li><a href="#-colaboradores">🤝 Colaboradores</a></li>
    <li><a href="#-links-úteis">🔗 Links Úteis</a></li>
  </ol>
</details>


## Começando 🚀

> [![Documentação Doxygen][documentacao-shield]][documentacao-url]

Para começar a utilizar o repositório, você precisa cumprir todos os requisitos abaixo:

### Pré-requisitos

* Ter um compilador c++ instalado.
* Ter o mingw na versão 11.2.0 e/ou c++ na versão 17 ou superior.
* Ter o cmake instalado.
* Ter o git instalado.
* Estar em um ambiente linux e/ou derivado.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

### Instalação

1. Clone o repositório.
   ```sh
   git clone https://github.com/olucashe/Trabalho-PDSII.git
   ```
2. Entre no diretório do repositório.
    ```sh
    cd Trabalho-PDSII
    ```
3. Execute o comando `make` para gerar o projeto.
    ```sh
    make
    ```

4. (opcional) Execute o comando `make test` para testar o projeto.
    ```sh
    make tests
    ```
<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## Como utilizar o Projeto

Para começar a utilizar, após a instalação, basta rodar:

- Para Linux:

```sh
  ./main
```
- Para Windows:

```sh
  ./main.exe
```


<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## Contruibuindo

As contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Quaisquer contribuições que você fizer são **muito apreciadas**.

Se você tiver uma sugestão para melhorar o projeto, por favor, faça um fork do repositório e crie um pull request. Você também pode simplesmente abrir um issue com a tag "melhoria".
Não se esqueça de dar uma estrela ao projeto! Obrigado novamente!

1. Dê um fork no projeto
2. Cria sua branch de melhoria (`git checkout -b feature/MelhoriaIncrivel`)
3. Faça um commit de suas mudanças (`git commit -m 'feat: adicionado uma melhoria incrível'`)
4. Faça um push para sua branch (`git push origin feature/MelhoriaIncrivel`)
5. Abra um pull request.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## ☕ User Stories
    
### 1. Cadastro de dados de Pessoas

Como administrador da plataforma, desejo um sistema no qual consigo cadastrar as pessoas que escreveram os livros e seus dados, como nome, sobrenome e data de nascimento dessas pessoas.

### 2. Cadastro de Autores

Como usuário, desejo saber de qual autor os livros são, bem como se o autor já faleceu, o ano da morte do mesmo. Desejo saber o nome e sobrenome do autor, bem como a data de nascimento do mesmo.

### 3. Cadastro de Livros

Como usuário, desejo poder ver todos os livros disponíveis na biblioteca, bem como seu titulo, editora, autor, qual seria a publicação e edição do mesmo. Também gostaria de saber o seu preços para compra, bem como também se o livro já foi usado e qual é sua condição fisica, como novo, seminovo, usado, etc.

### 4. Banco de dados de Livros

Como administrador, desejo ter um banco de dados com os dados dos meus livros, de maneira que a cada vez inicio o programa, a persistência de dados se perpetua. Desejo poder adicionar livros novos no banco de dados, bem como editar o livro e marcar como vendido. Desejo imprimir o titulo e ter a opção de salvar os dados editados no meu banco ou não.

### 5. Contabilizar Venda

Como administrador, desejo saber quais livros já vendi, qual foi meu custo, faturamento e lucro com os mesmos. Desejo listar os livros já vendidos e ver o relatório detalhado conforme os dados citados.

### 6. Realizar Venda

Como cliente, desejo poder escolher um dentre os livros e, sabendo o preço do mesmo, realizar a compra de uma unidade de cada livro desejado.

### 7. Exportar banco de dados

Como administrador, desejo ter fácil acesso ao meu banco de dados, de maneira que possa exportar o mesmo e, em outra instalação do programa, importar os dados do mesmo. Dessa maneira, consigo utilizar o banco de dados em outra loja de minha franquia com os mesmos produtos em estoque, sem precisar de refazer toda a base de cadastro.

### 8. Banco de dados de Vendas

Como administrador, desejo saber para quem vendi cada livro, armazenando este dado em um banco de dados de vendas, no qual informa o nome do cliente e os dados do livro.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## 🔗 Links Úteis

- [Histórias de usuários com exemplos e um template](https://www.atlassian.com/br/agile/project-management/user-stories)
- [Parser Json](https://github.com/eteran/cpp-json)
- [UUID](https://github.com/mariusbancila/stduuid)
- [GLS](https://github.com/microsoft/GSL)

[documentacao-shield]: https://img.shields.io/badge/Documentação%20Doxygen-clique%20aqui-blue
[documentacao-url]: https://google.com.br
[linguagens-shield]: https://img.shields.io/github/languages/count/olucashe/Trabalho-PDSII?style=for-the-badge
[linguagens-url]: https://github.com/olucashe/Trabalho-PDSII/
[tamanho-shield]: https://img.shields.io/github/repo-size/olucashe/Trabalho-PDSII?style=for-the-badge
[tamanho-url]: https://github.com/olucashe/Trabalho-PDSII/
[contributors-shield]: https://img.shields.io/github/contributors/olucashe/Trabalho-PDSII.svg?style=for-the-badge
[contributors-url]: https://github.com/olucashe/Trabalho-PDSII/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/olucashe/Trabalho-PDSII.svg?style=for-the-badge
[forks-url]: https://github.com/olucashe/Trabalho-PDSII/network/members
[stars-shield]: https://img.shields.io/github/stars/olucashe/Trabalho-PDSII.svg?style=for-the-badge
[stars-url]: https://github.com/olucashe/Trabalho-PDSII/stargazers
[issues-shield]: https://img.shields.io/github/issues/olucashe/Trabalho-PDSII.svg?style=for-the-badge
[issues-url]: https://github.com/olucashe/Trabalho-PDSII/issues
[license-shield]: https://img.shields.io/github/license/olucashe/Trabalho-PDSII.svg?style=for-the-badge
[license-url]: https://github.com/olucashe/Trabalho-PDSII/blob/master/LICENSE.txt

