#include "Biblioteca.hpp"

/**
 * @brief Construtor da classe Biblioteca
 *
 */
Biblioteca::Biblioteca() {
  strcpy(bookname, "Nome do Livro");
  strcpy(auname, "Nome do Autor");
  strcpy(sc, "ID do Livro");
  strcpy(sc1, "ID do Livro");
  q = 0;
  B = 0;
  p = 0;
}

/**
 * @brief Função que adiciona um livro na biblioteca
 *
 */
void Biblioteca::getdata() {
  int i;
  fflush(stdin);
  getch2();
  cout << endl << "Digite o nome do livro: ";
  cin.getline(bookname, 100);
  for (i = 0; bookname[i] != '\0'; i++) {
    if (bookname[i] >= 'a' && bookname[i] <= 'z')
      bookname[i] -= 32;
  }
  cout << endl << "Digite o nome do autor: ";
  cin.getline(auname, 50);
  cout << endl << "Digite o nome de publicacao: ";
  cin.getline(sc1, 50);
  cout << endl << "Digite o ID do livro: ";
  cin.getline(sc, 20);
  cout << endl << "Digite o preço do livro: ";
  cin >> p;
  cout << endl << "Digite a quantidade de livros: ";
  cin >> q;
}

/**
 * @brief Função que mostra os dados de um livro
 *
 * @param i
 */
void Biblioteca::show(int i) {
  cout << endl << "Nome do Livro: " << bookname;
  cout << endl << "Nome do Autor: " << auname;
  cout << endl << "ID do Livro: " << sc;
  cout << endl << "Nome de Publicacao: " << sc1;

  if (i == 2) {
    cout << endl << "Preco do Livro: " << p;
    cout << endl << "Quantidade de Livros: " << q;
  }
  getch2();
}

/**
 * @brief Função que mostra os dados dos livros
 *
 * @param i
 */
void Biblioteca::booklist(int i) {
  int b, r = 0;
  int clear = 0;
  clear = system("clear");
  b = branch(i);
  clear = system("clear");

  ifstream intf("Booksdata.txt", ios::binary);

  if (!intf) {
    cout << endl << "Arquivo nao encontrado";
  } else {
    cout << endl << "************ Lista de Livros ************" << endl;
    intf.read((char *)this, sizeof(*this));
    while (!intf.eof()) {
      if (b == B) {
        if (q == 0 && i == 1) {
        } else {
          r++;
          cout << endl << "********** " << r << ". **********" << endl;
          show(i);
        }
      }
      intf.read((char *)this, sizeof(*this));
    }
  }
  cout << endl << "Pressione qualquer tecla para continuar...";
  getch2();
  clear = system("clear");
  if (i == 1)
    student();
  else
    librarian();
}

/**
 * @brief Função que modificada os dados de um livro
 *
 */
void Biblioteca::modify() {
  int clear = 0;
  char st1[100];
  int i = 0, b, cont = 0;
  clear = system("clear");
  cout << endl << "Por favor, selecione uma opcao: " << endl;
  cout << endl << "1. Modificar um livro";
  cout << endl << "2. Adicionar um livro";
  cout << endl << "3. Remover um livro";
  cout << endl << "4. Voltar ao menu principal";
  cout << endl << "Opcao: ";
  cin >> i;
  if (i == 1) {
    clear = system("clear");
    b = branch(2);
    ifstream intf1("Booksdata.txt", ios::binary);
    if (!intf1) {
      cout << endl << "Arquivo nao encontrado";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      clear = system("clear");
      librarian();
    }
    intf1.close();
    clear = system("clear");
    cout << endl << "Por favor, selecione uma opcao: " << endl;
    cout << endl << "1. Pesquisar por nome do livro";
    cout << endl << "2. Pesquisar por ID do livro";
    cout << endl << "Opcao: ";
    cin >> i;
    fflush(stdin);
    if (i == 1) {
      clear = system("clear");
      cout << endl << "Digite o nome do livro: ";
      getch2();
      cin.getline(st1, 100);
      clear = system("clear");
      fstream intf("Booksdata.txt",
                   ios::in | ios::out | ios::ate | ios::binary);
      intf.seekg(0);
      intf.read((char *)this, sizeof(*this));
      while (!intf.eof()) {
        for (i = 0; b == B && bookname[i] != '\0' && st1[i] != '\0' &&
                    (st1[i] == bookname[i] || st1[i] == bookname[i] + 32);
             i++)
          ;
        if (bookname[i] == '\0' && st1[i] == '\0') {
          cont++;
          getdata();

          intf.seekp(intf.tellp() - sizeof(*this));
          intf.write((char *)this, sizeof(*this));
          break;
        }
        intf.read((char *)this, sizeof(*this));
      }
      intf.close();
    } else if (i == 2) {
      cout << endl << "Digite o ID do livro: ";
      getch2();
      cin.getline(st1, 100);
      clear = system("clear");
      fstream intf("Booksdata.txt",
                   ios::in | ios::out | ios::ate | ios::binary);
      intf.seekg(0);
      intf.read((char *)this, sizeof(*this));
      while (!intf.eof()) {
        for (i = 0;
             b == B && sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
          ;
        if (sc[i] == '\0' && st1[i] == '\0') {
          cont++;
          getdata();
          intf.seekp(intf.tellp() - sizeof(*this));
          intf.write((char *)this, sizeof(*this));
          break;
        }
        intf.read((char *)this, sizeof(*this));
      }

      intf.close();
    } else {
      cout << endl << "Opcao invalida";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      clear = system("clear");
      modify();
    }
    if (cont == 0) {
      cout << endl << "Livro nao encontrado";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      clear = system("clear");
      modify();
    } else
      cout << endl << "Livro modificado com sucesso";
    getch2();
  } else if (i == 2) {
    clear = system("clear");
    B = branch(2);
    clear = system("clear");
    getdata();
    ofstream outf("Booksdata.txt", ios::app | ios::binary);
    outf.write((char *)this, sizeof(*this));
    outf.close();
    cout << endl << "Livro adicionado com sucesso";
  } else if (i == 3) {
    clear = system("clear");
    b = branch(2);
    ifstream intf1("Booksdata.txt", ios::binary);
    if (!intf1) {
      cout << endl << "Arquivo nao encontrado";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      intf1.close();
      clear = system("clear");
      librarian();
    }
    intf1.close();
    clear = system("clear");
    cout << endl << "Por favor, selecione uma opcao para deletar: " << endl;
    cout << endl << "1. Deletar por nome do livro";
    cout << endl << "2. Deletar por ID do livro";
    cout << endl << "Opcao: ";
    cin >> i;
    fflush(stdin);
    if (i == 1) {
      clear = system("clear");
      cout << endl << "Digite o nome do livro: ";
      getch2();
      cin.getline(st1, 100);
      ofstream outf("temp.txt", ios::app | ios::binary);
      ifstream intf("Booksdata.txt", ios::binary);
      intf.read((char *)this, sizeof(*this));
      while (!intf.eof()) {
        for (i = 0; b == B && bookname[i] != '\0' && st1[i] != '\0' &&
                    (st1[i] == bookname[i] || st1[i] == bookname[i] + 32);
             i++)
          ;
        if (bookname[i] == '\0' && st1[i] == '\0') {
          cont++;
          intf.read((char *)this, sizeof(*this));
        } else {
          outf.write((char *)this, sizeof(*this));
          intf.read((char *)this, sizeof(*this));
        }
      }

      intf.close();
      outf.close();
      remove("Booksdata.txt");
      rename("temp.txt", "Booksdata.txt");
    } else if (i == 2) {
      cout << endl << "Digite o ID do livro: ";
      cin.getline(st1, 100);
      ofstream outf("temp.txt", ios::app | ios::binary);
      ifstream intf("Booksdata.txt", ios::binary);
      intf.read((char *)this, sizeof(*this));
      while (!intf.eof()) {
        for (i = 0;
             b == B && sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
          ;
        if (sc[i] == '\0' && st1[i] == '\0') {
          cont++;
          intf.read((char *)this, sizeof(*this));
        } else {
          outf.write((char *)this, sizeof(*this));
          intf.read((char *)this, sizeof(*this));
        }
      }
      outf.close();
      intf.close();
      remove("Booksdata.txt");
      rename("temp.txt", "Booksdata.txt");
    } else {
      cout << endl << "Opcao invalida";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      clear = system("clear");
      modify();
    }
    if (cont == 0) {
      cout << endl << "Livro nao encontrado";
      cout << endl << "Pressione qualquer tecla para continuar...";
      getch2();
      clear = system("clear");
      modify();
    } else
      cout << endl << "Livro deletado com sucesso";
  } else if (i == 4) {
    clear = system("clear");
    librarian();
  } else {
    cout << endl << "Opcao invalida";
    cout << endl << "Pressione qualquer tecla para continuar...";
    getch2();
    clear = system("clear");
    modify();
  }
  cout << endl << "Pressione qualquer tecla para continuar...";
  getch2();
  clear = system("clear");
  librarian();
}

/**
 * @brief Função que mostra todos os tipos de livros
 *
 * @param x
 * @return int
 */
int Biblioteca::branch(int x) {
  int i;
  int clear = 0;
  cout << endl << "Por favor, selecione um tipo de livro: " << endl;
  cout << endl << "1. Ficcao";
  cout << endl << "2. Romance";
  cout << endl << "3. Acao";
  cout << endl << "4. Suspense";
  cout << endl << "5. Terror";
  cout << endl << "6. Biografia";
  cout << endl << "7. Voltar ao menu anterior";
  cout << endl << "Opcao: ";
  cin >> i;
  switch (i) {
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 3;
    break;
  case 4:
    return 4;
    break;
  case 5:
    return 5;
    break;
  case 6:
    return 6;
    break;
  case 7:
    clear = system("clear");
    if (x == 1)
      student();
    else
      librarian();
  default:
    cout << endl << "Opcao invalida";
    getch2();
    clear = system("clear");
    branch(x);
  }
  return 0;
}

/**
 * @brief Função que mostra todos os livros de um determinado tipo
 *
 * @param x
 */
void Biblioteca::see(int x) {
  int clear = 0;
  int i, b, cont = 0;
  char ch[100];
  clear = system("clear");
  b = branch(x);
  ifstream intf("Booksdata.txt", ios::binary);
  if (!intf) {
    cout << endl << "Arquivo nao encontrado";
    cout << endl << "Pressione qualquer tecla para continuar...";
    getch2();
    clear = system("clear");
    if (x == 1)
      student();
    else
      librarian();
  }

  clear = system("clear");
  cout << endl << "Por favor, selecione uma opcao para ver: " << endl;
  cout << endl << "1. Ver por nome do livro";
  cout << endl << "2. Ver por ID do livro";
  cout << endl << "Opcao: ";
  cin >> i;
  fflush(stdin);
  intf.read((char *)this, sizeof(*this));
  if (i == 1) {
    cout << endl << "Digite o nome do livro: ";
    getch2();
    cin.getline(ch, 100);
    clear = system("clear");
    while (!intf.eof()) {
      for (i = 0; b == B && q != 0 && bookname[i] != '\0' && ch[i] != '\0' &&
                  (ch[i] == bookname[i] || ch[i] == bookname[i] + 32);
           i++)
        ;
      if (bookname[i] == '\0' && ch[i] == '\0') {
        cout << endl << "Livro encontrado";
        show(x);
        cont++;
        break;
      }
      intf.read((char *)this, sizeof(*this));
    }
  } else if (i == 2) {
    cout << endl << "Digite o ID do livro: ";
    cin.getline(ch, 100);
    clear = system("clear");
    while (!intf.eof()) {
      for (i = 0;
           b == B && q != 0 && sc[i] != '\0' && ch[i] != '\0' && ch[i] == sc[i];
           i++)
        ;
      if (sc[i] == '\0' && ch[i] == '\0') {
        cout << endl << "Livro encontrado";
        show(x);
        cont++;
        break;
      }
      intf.read((char *)this, sizeof(*this));
    }
  } else {
    cont++;
    cout << endl << "Opcao invalida";
    getch2();
    clear = system("clear");
    see(x);
  }
  intf.close();
  if (cont == 0)
    cout << endl << "Livro nao encontrado";

  cout << endl << "Pressione qualquer tecla para continuar...";
  getch2();
  clear = system("clear");
  if (x == 1)
    student();
  else
    librarian();
}

/**
 * @brief Função que gerencia o emprestimo de livros
 *
 */
void Biblioteca::issue() {
  int clear = 0;
  char st[50], st1[20];
  int b, i, j, d, m, y, cont = 0;

  clear = system("clear");
  cout << endl << "Por favor, selecione uma opcao: " << endl;
  cout << endl << "1. Emprestar livro";
  cout << endl << "2. Ver livros emprestados";
  cout << endl << "3. Pesquisar por estudantes que emprestaram livros";
  cout << endl << "4. Reemprestar livro";
  cout << endl << "5. Voltar ao menu anterior";
  cout << endl << "Opcao: ";
  cin >> i;
  fflush(stdin);
  if (i == 1) {
    clear = system("clear");
    b = branch(2);
    clear = system("clear");
    fflush(stdin);
    cout << endl << "Digite o nome do livro: ";
    cin.getline(bookname, 100);
    cout << endl << "Digite o ID do livro: ";
    cin.getline(sc, 20);
    // strcpy(st,sc);
    der(sc, b, 1);
    cout << endl << "Digite o nome do estudante: ";
    cin.getline(auname, 100);
    cout << endl << "Digite o ID do estudante: ";
    cin.getline(sc1, 20);
    cout << endl << "Digite a data de emprestimo: ";
    cin >> q >> B >> p;
    ofstream outf("student.txt", ios::binary | ios::app);
    outf.write((char *)this, sizeof(*this));
    outf.close();
    cout << endl << "Livro emprestado com sucesso";
  } else if (i == 2) {
    ifstream intf("student.txt", ios::binary);
    clear = system("clear");
    cout << endl << "Livros emprestados: " << endl;
    intf.read((char *)this, sizeof(*this));
    i = 0;
    while (!intf.eof()) {
      i++;
      cout << endl << "********** " << i << ". **********" << endl;
      cout << endl << "Nome do estudante: " << auname;
      cout << endl << "ID do estudante: " << sc1;
      cout << endl << "Nome do livro: " << bookname;
      cout << endl << "ID do livro: " << sc;
      cout << endl
           << "Data de emprestimo: " << q << "/" << B << "/" << p << endl;
      intf.read((char *)this, sizeof(*this));
      getch2();
    }
    intf.close();
  } else if (i == 3) {
    clear = system("clear");
    fflush(stdin);
    cout << endl << "Digite o nome do estudante: ";
    cin.getline(st, 50);
    cout << endl << "Digite o ID do estudante: ";
    cin.getline(st1, 20);
    clear = system("clear");
    ifstream intf("student.txt", ios::binary);
    intf.read((char *)this, sizeof(*this));
    cont = 0;
    while (!intf.eof()) {
      for (i = 0; sc1[i] != '\0' && st1[i] != '\0' && st1[i] == sc1[i]; i++)
        ;
      if (sc1[i] == '\0' && st1[i] == '\0') {
        cont++;
        if (cont == 1) {
          cout << endl << "Livros emprestados por " << st << ": " << endl;
          cout << endl << "Nome do estudante: " << auname;
          cout << endl << "ID do estudante: " << sc1;
        }
        cout << endl
             << "******* " << cont << ". Detalhe do livro *******" << endl;
        cout << endl << "Nome do livro: " << bookname;
        cout << endl << "ID do livro: " << sc;
        cout << endl
             << "Data de emprestimo: " << q << "/" << B << "/" << p << endl;
      }
      intf.read((char *)this, sizeof(*this));
    }
    intf.close();
    if (cont == 0)
      cout << endl << "Nenhum livro emprestado por " << st;
  } else if (i == 4) {
    clear = system("clear");
    fflush(stdin);
    cout << endl << "Digite o ID do estudante: ";
    cin.getline(st, 50);
    cout << endl << "Digite o ID do livro: ";
    cin.getline(st1, 20);
    fstream intf("student.txt", ios::in | ios::out | ios::ate | ios::binary);
    intf.seekg(0);
    intf.read((char *)this, sizeof(*this));
    while (!intf.eof()) {
      for (i = 0; sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
        ;
      for (j = 0; sc1[j] != '\0' && st[j] != '\0' && st[j] == sc1[j]; j++)
        ;
      if (sc[i] == '\0' && sc1[j] == '\0' && st[j] == '\0' && st1[i] == '\0') {
        d = q;
        m = B;
        y = p;
        cout << endl << "Digite a data de reemprestimo: ";
        cin >> q >> B >> p;
        fine(d, m, y, q, B, p);                   // fn1
        intf.seekp(intf.tellp() - sizeof(*this)); // fn3
        intf.write((char *)this, sizeof(*this));  // fn5
        cout << endl << "Livro reemprestado com sucesso";
        break;
      }
      intf.read((char *)this, sizeof(*this));
    }
    intf.close();
  } else if (i == 5) {
    clear = system("clear");
    b = branch(2);
    clear = system("clear");
    fflush(stdin);
    cout << endl << "Digite o ID do livro: ";
    cin.getline(st1, 20);
    der(st1, b, 2);
    cout << endl << "Digite o ID do estudante: ";
    cin.getline(st, 20);
    cout << endl << "Digite a data de devolucao: ";
    cin >> d >> m >> y;
    ofstream outf("temp.txt", ios::app | ios::binary);
    ifstream intf("student.txt", ios::binary);
    intf.read((char *)this, sizeof(*this));
    while (!intf.eof()) {
      for (i = 0; sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
        ;
      for (j = 0; sc1[j] != '\0' && st[j] != '\0' && st[j] == sc1[j]; j++)
        ;
      if (sc[i] == '\0' && sc1[j] == '\0' && st[j] == '\0' && st1[i] == '\0' &&
          cont == 0) {
        cont++;
        intf.read((char *)this, sizeof(*this));
        fine(q, B, p, d, m, y);
        cout << endl << "Livro devolvido com sucesso";
      } else {
        outf.write((char *)this, sizeof(*this));
        intf.read((char *)this, sizeof(*this));
      }
    }

    intf.close();
    outf.close();
    getch2();
    remove("student.txt");
    rename("temp.txt", "student.txt");
  } else if (i == 6) {
    clear = system("clear");
    librarian();
  } else
    cout << endl << "Opcao invalida";

  cout << endl << "Pressione qualquer tecla para continuar";
  getch2();
  clear = system("clear");
  librarian();
}

/**
 * @brief  Função que calcula a multa
 *
 * @param d
 * @param m
 * @param y
 * @param dd
 * @param mm
 * @param yy
 */
void Biblioteca::fine(int d, int m, int y, int dd, int mm, int yy) {
  long int n1, n2;
  int years, l, i;
  const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  n1 = y * 365 + d;
  for (i = 0; i < m - 1; i++)
    n1 += monthDays[i]; // fn1353
  years = y;
  if (m <= 2)
    years--;
  l = years / 4 - years / 100 + years / 400;
  n1 += l;
  n2 = yy * 365 + dd;
  for (i = 0; i < mm - 1; i++)
    n2 += monthDays[i];
  years = yy;
  if (m <= 2)
    years--;
  l = years / 4 - years / 100 + years / 400;
  n2 += l;
  n1 = n2 - n1;
  n2 = n1 - 15;
  if (n2 > 0)
    cout << endl << "Multa de " << n2 << " dias";
}

/**
 * @brief Função que verifica se o livro está disponível
 *
 * @param st
 * @param b
 * @param x
 */
void Biblioteca::der(char st[], int b, int x) {
  int clear = 0;
  int i, cont = 0;
  fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
  intf.seekg(0);
  intf.read((char *)this, sizeof(*this));
  while (!intf.eof()) {
    for (i = 0; b == B && sc[i] != '\0' && st[i] != '\0' && st[i] == sc[i]; i++)
      ;
    if (sc[i] == '\0' && st[i] == '\0') {
      cont++;
      if (x == 1) {
        q--;
      } else {
        q++;
      }
      intf.seekp(intf.tellp() - sizeof(*this));
      intf.write((char *)this, sizeof(*this));
      break;
    }
    intf.read((char *)this, sizeof(*this));
  }
  if (cont == 0) {
    cout << endl << "Livro nao encontrado";
    cout << endl << "Pressione qualquer tecla para continuar";
    getch2();
    clear = system("clear");
    issue();
  }
  intf.close();
}

/**
 * @brief Função principal do programa
 *
 */
void Biblioteca::get() {
  int clear = 0;
  int i;
  cout << endl
       << "*********** Sistema de Gerenciamento de Biblioteca ***********";
  cout << endl
       << "          UFMG - Universidade Federal de Minas Gerais" << endl;
  cout << endl << "Por favor, escolha uma das opcoes abaixo: ";
  cout << endl << "1. Estudante";
  cout << endl << "2. Bibliotecario";
  cout << endl << "3. Sair";
  cout << endl << "Opcao: ";
  cin >> i;
  if (i == 1) {
    clear = system("clear");
    student();
  } else if (i == 2)
    pass();

  else if (i == 3)
    exit(0);
  else {
    cout << endl << "Opcao invalida";
    getch2();
    clear = system("clear");
    get();
  }
}

/**
 * @brief Função que mostra o painel do estudante
 *
 */
void Biblioteca::student() {
  int clear = 0;
  int i;
  cout << endl << "*********** Seja bem-vindo(a) Estudante ***********";
  cout << endl << "Por favor, escolha uma das opcoes abaixo: ";
  cout << endl << "1. Ver lista de livros";
  cout << endl << "2. Pesquisar livro";
  cout << endl << "3. Voltar ao menu anterior";
  cout << endl << "4. Fechar aplicacao";
  cout << endl << "Opcao: ";
  cin >> i;
  if (i == 1)
    booklist(1);
  else if (i == 2)
    see(1);
  else if (i == 3) {
    clear = system("clear");
    get();
  } else if (i == 4)
    exit(0);
  else {
    cout << endl << "Opcao invalida";
    getch2();
    clear = system("clear");
    student();
  }
}

/**
 * @brief Função que verifica a senha do bibliotecário
 *
 */
void Biblioteca::pass() {
  FilePassword f;
  int clear = 0, first = 1;
  int i = 0;
  char ch, st[21], ch1[21] = {"pass"};
  cout << endl << "Insira a senha: ";
  while (1) {
    ch = getch2();
    if (first == 1) {
      first = 0;
      if (ch == 10)
        ch = getch2();
    }
    if (ch == 10) {
      st[i] = '\0';
      break;
    } else if (ch == 8 && i > 0) {
      i--;
      cout << "\b \b";
    } else {
      cout << "*";
      st[i] = ch;
      i++;
    }
  }
  ifstream inf = f.read();
  inf >> ch1;
  inf.close();
  for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
    ;
  if (st[i] == '\0' && ch1[i] == '\0') {
    clear = system("clear");
    librarian();
  } else {
    cout << endl << "Senha incorreta";
    cout << endl << "Tente novamente";
    getch2();
    clear = system("clear");
    get();
  }
}

/**
 * @brief Função que mostra o painel do bibliotecário
 *
 */
void Biblioteca::librarian() {
  int clear = 0;
  int i;
  cout << endl << "*********** Seja bem-vindo(a) Bibliotecario ***********";
  cout << endl << "Por favor, escolha uma das opcoes abaixo: ";
  cout << endl << "1. Ver lista de livros";
  cout << endl << "2. Pesquisar livro";
  cout << endl << "3. Adicionar/Modificar livro";
  cout << endl << "4. Emprestar livro";
  cout << endl << "5. Voltar ao menu anterior";
  cout << endl << "6. Mudar senha";
  cout << endl << "7. Fechar aplicacao";
  cout << endl << "Opcao: ";
  cin >> i;
  switch (i) {
  case 1:
    booklist(2);
    break;
  case 2:
    see(2);
    break;
  case 3:
    modify();
    break;
  case 4:
    issue();
    break;
  case 5:
    clear = system("clear");
    get();
    break;
  case 6:
    password();
    break;
  case 7:
    exit(0);
  default:
    cout << endl << "Opcao invalida";
    getch2();
    clear = system("clear");
    librarian();
  }
}

/**
 * @brief Função de gerenciamendo de senha
 *
 */
void Biblioteca::password() {
  int clear = 0;
  int i = 0, j = 0;
  char ch, st[21], ch1[21] = {"pass"};
  clear = system("clear");
  cout << endl << "*********** Mudar senha ***********";
  cout << endl << "Insira a senha atual: ";
  while (1) {
    int first = 1;
    ch = getch2();
    if (first == 1) {
      first = 0;
      if (ch == 10)
        ch = getch2();
    }
    if (ch == 10) {
      st[i] = '\0';
      break;
    } else if (ch == 8 && i > 0) {
      i--;
      cout << "\b \b";
    } else {
      cout << "*";
      st[i] = ch;
      i++;
    }
  }
  ifstream intf("password.txt");
  intf >> ch1;
  intf.close();
  for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
    ;
  if (st[i] == '\0' && ch1[i] == '\0') {
    clear = system("clear");
    cout << endl << "*********** Mudar senha ***********";
    cout << endl
         << "Insira a nova senha (menor que 20 caracteres e nao use espacos): ";
    cout << endl << "Senha: ";
    fflush(stdin);
    i = 0;
    while (1) {
      j++;
      ch = getch2();
      if (ch == 10) {
        for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
          ;
        if (j > 20 || st[i] == ' ') {
          cout << endl << "Senha invalida, tenta novamente";
          getch2();
          clear = system("clear");
          password();
          librarian();
        }
        st[i] = '\0';
        break;
      } else if (ch == 8 && i > 0) {
        i--;
        cout << "\b \b";
      } else {
        cout << "*";
        st[i] = ch;
        i++;
      }
    }
    // se o ultimo caracter for um espaço, remove
    if (st[i - 1] == ' ')
      st[i - 1] = '\0';
    ofstream outf("password.txt");
    outf << st;
    outf.close();
    cout << endl << "Senha alterada com sucesso";
    cout << endl << "Pressione qualquer tecla para continuar";
    getch2();
    clear = system("clear");
    librarian();
  } else {
    cout << endl << "Senha incorreta";
    cout
        << endl
        << "Insira 1 para tentar novamente ou 2 para voltar ao menu anterior: ";
    cin >> i;
    if (i == 1) {
      clear = system("clear");
      password();
    } else {
      clear = system("clear");
      librarian();
    }
  }
}
