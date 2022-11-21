#include "Biblioteca.hpp"

Biblioteca::Biblioteca()
{
    strcpy(bookname, "Nome do Livro");
    strcpy(auname, "Nome do Autor");
    strcpy(sc, "ID do Livro");
    strcpy(sc1, "ID do Livro");
    q = 0;
    B = 0;
    p = 0;
}

void Biblioteca::getdata()
{
    int i;
    fflush(stdin);
    cout << endl << "Digite o nome do livro: ";
    cin.getline(bookname, 100);
    for (i = 0; bookname[i] != '\0'; i++)
    {
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

void Biblioteca::show(int i)
{
    cout << endl << "Nome do Livro: " << bookname;
    cout << endl << "Nome do Autor: " << auname;
    cout << endl << "ID do Livro: " << sc;
    cout << endl << "Nome de Publicacao: " << sc1;

    if (i == 2)
    {
        cout << endl << "Preco do Livro: " << p;
        cout << endl << "Quantidade de Livros: " << q;
    }
}

void Biblioteca::booklist(int i)
{
    int b, r = 0;
    system("cls");
    b = branch(i);
    system("cls");

    ifstream intf("Booksdata.txt", ios::binary);

    if (!intf)
    {
        cout << endl << "Arquivo nao encontrado";
    }
    else
    {
        cout << endl << "************ Lista de Livros ************" << endl;
        intf.read((char *)this, sizeof(*this));
        while (!intf.eof())
        {
            if (b == B)
            {
                if (q == 0 && i == 1)
                {
                }
                else
                {
                    r++;
                    cout << endl << "********** " << r << ". **********" << endl;
                    show(i);
                }
            }
            intf.read((char *)this, sizeof(*this));
        }
    }
    cout << endl << "Pressione qualquer tecla para continuar...";
    getch();
    system("cls");
    if (i == 1)
        student();
    else
        librarian();
}
void Biblioteca::modify()
{
    char st1[100];
    int i = 0, b, cont = 0;
    system("cls");
    cout << endl << "Por favor, selecione uma opcao: " << endl;
    cout << endl << "1. Modificar um livro";
    cout << endl << "2. Adicionar um livro";
    cout << endl << "3. Remover um livro";
    cout << endl << "4. Voltar ao menu principal";
    cout << endl << "Opcao: ";
    cin >> i;
    if (i == 1)
    {
        system("cls");
        b = branch(2);
        ifstream intf1("Booksdata.txt", ios::binary);
        if (!intf1)
        {
            cout << endl << "Arquivo nao encontrado";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            system("cls");
            librarian();
        }
        intf1.close();
        system("cls");
        cout << endl << "Por favor, selecione uma opcao: " << endl;
        cout << endl << "1. Pesquisar por nome do livro";
        cout << endl << "2. Pesquisar por ID do livro";
        cout << endl << "Opcao: ";
        cin >> i;
        fflush(stdin);
        if (i == 1)
        {
            system("cls");
            cout << endl << "Digite o nome do livro: ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
            intf.seekg(0);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; b == B && bookname[i] != '\0' && st1[i] != '\0' && (st1[i] == bookname[i] || st1[i] == bookname[i] + 32); i++)
                    ;
                if (bookname[i] == '\0' && st1[i] == '\0')
                {
                    cont++;
                    getdata();
                    
                    intf.seekp(intf.tellp() - sizeof(*this));
                    intf.write((char *)this, sizeof(*this));
                    break;
                }
                intf.read((char *)this, sizeof(*this));
            }
            intf.close();
        }
        else if (i == 2)
        {
            cout << endl << "Digite o ID do livro: ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
            intf.seekg(0);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; b == B && sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
                    ;
                if (sc[i] == '\0' && st1[i] == '\0')
                {
                    cont++;
                    getdata();
                    intf.seekp(intf.tellp() - sizeof(*this));
                    intf.write((char *)this, sizeof(*this));
                    break;
                }
                intf.read((char *)this, sizeof(*this));
            }

            intf.close();
        }
        else
        {
            cout << endl << "Opcao invalida";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            system("cls");
            modify();
        }
        if (cont == 0)
        {
            cout << endl << "Livro nao encontrado";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            system("cls");
            modify();
        }
        else
            cout << endl << "Livro modificado com sucesso";
    }
    else if (i == 2)
    {
        system("cls");
        B = branch(2);
        system("cls");
        getdata();
        ofstream outf("Booksdata.txt", ios::app | ios::binary);
        outf.write((char *)this, sizeof(*this));
        outf.close();
        cout << endl << "Livro adicionado com sucesso";
    }
    else if (i == 3)
    {
        system("cls");
        b = branch(2);
        ifstream intf1("Booksdata.txt", ios::binary);
        if (!intf1)
        {
            cout << endl << "Arquivo nao encontrado";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            intf1.close();
            system("cls");
            librarian();
        }
        intf1.close();
        system("cls");
        cout << endl << "Por favor, selecione uma opcao para deletar: " << endl;
        cout << endl << "1. Deletar por nome do livro";
        cout << endl << "2. Deletar por ID do livro";
        cout << endl << "Opcao: ";
        cin >> i;
        fflush(stdin);
        if (i == 1)
        {
            system("cls");
            cout << endl << "Digite o nome do livro: ";
            cin.getline(st1, 100);
            ofstream outf("temp.txt", ios::app | ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; b == B && bookname[i] != '\0' && st1[i] != '\0' && (st1[i] == bookname[i] || st1[i] == bookname[i] + 32); i++)
                    ;
                if (bookname[i] == '\0' && st1[i] == '\0')
                {
                    cont++;
                    intf.read((char *)this, sizeof(*this));
                }
                else
                {
                    outf.write((char *)this, sizeof(*this));
                    intf.read((char *)this, sizeof(*this));
                }
            }

            intf.close();
            outf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Booksdata.txt");
        }
        else if (i == 2)
        {
            cout << endl << "Digite o ID do livro: ";
            cin.getline(st1, 100);
            ofstream outf("temp.txt", ios::app | ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; b == B && sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
                    ;
                if (sc[i] == '\0' && st1[i] == '\0')
                {
                    cont++;
                    intf.read((char *)this, sizeof(*this));
                }
                else
                {
                    outf.write((char *)this, sizeof(*this));
                    intf.read((char *)this, sizeof(*this));
                }
            }
            outf.close();
            intf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Booksdata.txt");
        }
        else
        {
            cout << endl << "Opcao invalida";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            system("cls");
            modify();
        }
        if (cont == 0)
        {
            cout << endl << "Livro nao encontrado";
            cout << endl << "Pressione qualquer tecla para continuar...";
            getch();
            system("cls");
            modify();
        }
        else
            cout << endl << "Livro deletado com sucesso";
    }
    else if (i == 4)
    {
        system("cls");
        librarian();
    }
    else
    {
        cout << endl << "Opcao invalida";
        cout << endl << "Pressione qualquer tecla para continuar...";
        getch();
        system("cls");
        modify();
    }
    cout << endl << "Pressione qualquer tecla para continuar...";
    getch();
    system("cls");
    librarian();
}

int Biblioteca::branch(int x)
{
    int i;
    cout << "\n\t\t>>Please Choose one Branch :-\n";
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
    switch (i)
    {
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
        system("cls");
        if (x == 1)
            student();
        else
            librarian();
    default:
        cout << endl << "Opcao invalida";
        getch();
        system("cls");
        branch(x);
    }
    return 0;
}

void Biblioteca::see(int x)
{
    int i, b, cont = 0;
    char ch[100];
    system("cls");
    b = branch(x);
    ifstream intf("Booksdata.txt", ios::binary);
    if (!intf)
    {
        cout << endl << "Arquivo nao encontrado";
        cout << endl << "Pressione qualquer tecla para continuar...";
        getch();
        system("cls");
        if (x == 1)
            student();
        else
            librarian();
    }

    system("cls");
    cout << endl << "Por favor, selecione uma opcao para ver: " << endl;
    cout << endl << "1. Ver por nome do livro";
    cout << endl << "2. Ver por ID do livro";
    cout << endl << "Opcao: ";
    cin >> i;
    fflush(stdin);
    intf.read((char *)this, sizeof(*this));
    if (i == 1)
    {
        cout << endl << "Digite o nome do livro: ";
        cin.getline(ch, 100);
        system("cls");
        while (!intf.eof())
        {
            for (i = 0; b == B && q != 0 && bookname[i] != '\0' && ch[i] != '\0' && (ch[i] == bookname[i] || ch[i] == bookname[i] + 32); i++)
                ;
            if (bookname[i] == '\0' && ch[i] == '\0')
            {
                cout << endl << "Livro encontrado";
                show(x);
                cont++;
                break;
            }
            intf.read((char *)this, sizeof(*this));
        }
    }
    else if (i == 2)
    {
        cout << endl << "Digite o ID do livro: ";
        cin.getline(ch, 100);
        system("cls");
        while (!intf.eof())
        {
            for (i = 0; b == B && q != 0 && sc[i] != '\0' && ch[i] != '\0' && ch[i] == sc[i]; i++)
                ;
            if (sc[i] == '\0' && ch[i] == '\0')
            {
                cout << endl << "Livro encontrado";
                show(x);
                cont++;
                break;
            }
            intf.read((char *)this, sizeof(*this));
        }
    }
    else
    {
        cont++;
        cout << endl << "Opcao invalida";
        getch();
        system("cls");
        see(x);
    }
    intf.close();
    if (cont == 0)
        cout << endl << "Livro nao encontrado";

    cout << endl << "Pressione qualquer tecla para continuar...";
    getch();
    system("cls");
    if (x == 1)
        student();
    else
        librarian();
}

void Biblioteca::issue()
{
    char st[50], st1[20];
    int b, i, j, d, m, y, cont = 0;

    system("cls");
    cout << endl << "Por favor, selecione uma opcao: " << endl;
    cout << endl << "1. Emprestar livro";
    cout << endl << "2. Ver livros emprestados";
    cout << endl << "3. Pesquisar por estudantes que emprestaram livros";
    cout << endl << "4. Reemprestar livro";
    cout << endl << "5. Voltar ao menu anterior";
    cout << endl << "Opcao: ";
    cin >> i;
    fflush(stdin);
    if (i == 1)
    {
        system("cls");
        b = branch(2);
        system("cls");
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
    }
    else if (i == 2)
    {
        ifstream intf("student.txt", ios::binary);
        system("cls");
        cout << endl << "Livros emprestados: " << endl;
        intf.read((char *)this, sizeof(*this));
        i = 0;
        while (!intf.eof())
        {
            i++;
            cout << endl <<"********** " << i << ". **********" << endl;
            cout << endl << "Nome do estudante: " << auname;
            cout << endl << "ID do estudante: " << sc1;
            cout << endl << "Nome do livro: " << bookname;
            cout << endl << "ID do livro: " << sc;
            cout << endl << "Data de emprestimo: " << q << "/" << B << "/" << p << endl;
            intf.read((char *)this, sizeof(*this));
        }
        intf.close();
    }
    else if (i == 3)
    {
        system("cls");
        fflush(stdin);
        cout << endl << "Digite o nome do estudante: ";
        cin.getline(st, 50);
        cout << endl << "Digite o ID do estudante: ";
        cin.getline(st1, 20);
        system("cls");
        ifstream intf("student.txt", ios::binary);
        intf.read((char *)this, sizeof(*this));
        cont = 0;
        while (!intf.eof())
        {
            for (i = 0; sc1[i] != '\0' && st1[i] != '\0' && st1[i] == sc1[i]; i++)
                ;
            if (sc1[i] == '\0' && st1[i] == '\0')
            {
                cont++;
                if (cont == 1)
                {
                    cout << endl << "Livros emprestados por " << st << ": " << endl;
                    cout << endl << "Nome do estudante: " << auname;
                    cout << endl << "ID do estudante: " << sc1;
                }
                cout << endl << "******* " << cont << ". Detalhe do livro *******" << endl;
                cout << endl << "Nome do livro: " << bookname;
                cout << endl << "ID do livro: " << sc;
                cout << endl << "Data de emprestimo: " << q << "/" << B << "/" << p << endl;
            }
            intf.read((char *)this, sizeof(*this));
        }
        intf.close();
        if (cont == 0)
            cout << endl << "Nenhum livro emprestado por " << st;
    }
    else if (i == 4)
    {
        system("cls");
        fflush(stdin);
        cout << endl << "Digite o ID do estudante: ";
        cin.getline(st, 50);
        cout << endl << "Digite o ID do livro: ";
        cin.getline(st1, 20);
        fstream intf("student.txt", ios::in | ios::out | ios::ate | ios::binary);
        intf.seekg(0);
        intf.read((char *)this, sizeof(*this));
        while (!intf.eof())
        {
            for (i = 0; sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
                ;
            for (j = 0; sc1[j] != '\0' && st[j] != '\0' && st[j] == sc1[j]; j++)
                ;
            if (sc[i] == '\0' && sc1[j] == '\0' && st[j] == '\0' && st1[i] == '\0')
            {
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
    }
    else if (i == 5)
    {
        system("cls");
        b = branch(2);
        system("cls");
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
        while (!intf.eof())
        {
            for (i = 0; sc[i] != '\0' && st1[i] != '\0' && st1[i] == sc[i]; i++)
                ;
            for (j = 0; sc1[j] != '\0' && st[j] != '\0' && st[j] == sc1[j]; j++)
                ;
            if (sc[i] == '\0' && sc1[j] == '\0' && st[j] == '\0' && st1[i] == '\0' && cont == 0)
            {
                cont++;
                intf.read((char *)this, sizeof(*this));
                fine(q, B, p, d, m, y);
                cout << endl << "Livro devolvido com sucesso";
            }
            else
            {
                outf.write((char *)this, sizeof(*this));
                intf.read((char *)this, sizeof(*this));
            }
        }

        intf.close();
        outf.close();
        getch();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
    else if (i == 6)
    {
        system("cls");
        librarian();
    }
    else
        cout << endl << "Opcao invalida";

    cout << endl << "Pressione qualquer tecla para continuar";
    getch();
    system("cls");
    librarian();
}

void Biblioteca::fine(int d, int m, int y, int dd, int mm, int yy)
{
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

void Biblioteca::der(char st[], int b, int x)
{
    int i, cont = 0;
    fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
    intf.seekg(0);
    intf.read((char *)this, sizeof(*this));
    while (!intf.eof())
    {
        for (i = 0; b == B && sc[i] != '\0' && st[i] != '\0' && st[i] == sc[i]; i++)
            ;
        if (sc[i] == '\0' && st[i] == '\0')
        {
            cont++;
            if (x == 1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp() - sizeof(*this));
            intf.write((char *)this, sizeof(*this));
            break;
        }
        intf.read((char *)this, sizeof(*this));
    }
    if (cont == 0)
    {
        cout << endl << "Livro nao encontrado";
        cout << endl << "Pressione qualquer tecla para continuar";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}

void Biblioteca::get()
{
    int i;
    cout << endl << "*********** Sistema de Gerenciamento de Biblioteca ***********";
    cout << endl << "          UFMG - Universidade Federal de Minas Gerais"  << endl;
    cout << endl << "Por favor, escolha uma das opcoes abaixo: ";
    cout << endl << "1. Estudante";
    cout << endl << "2. Bibliotecario";
    cout << endl << "3. Sair";
    cout << endl << "Opcao: ";
    cin >> i;
    if (i == 1)
    {
        system("cls");
        student();
    }
    else if (i == 2)
        pass();

    else if (i == 3)
        exit(0);
    else
    {
        cout << endl << "Opcao invalida";
        getch();
        system("CLS");
        get();
    }
}

void Biblioteca::student()
{
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
    else if (i == 3)
    {
        system("cls");
        get();
    }
    else if (i == 4)
        exit(0);
    else
    {
        cout << endl << "Opcao invalida";
        getch();
        system("cls");
        student();
    }
}

void Biblioteca::pass()
{
    int i = 0;
    char ch, st[21], ch1[21] = {"pass"};
    cout << endl << "Insira a senha: ";
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            st[i] = '\0';
            break;
        }
        else if (ch == 8 && i > 0)
        {
            i--;
            cout << "\b \b";
        }
        else
        {
            cout << "*";
            st[i] = ch;
            i++;
        }
    }
    ifstream inf("password.txt");
    inf >> ch1;
    inf.close();
    for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
        ;
    if (st[i] == '\0' && ch1[i] == '\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout << endl << "Senha incorreta"; 
        cout << endl << "Tente novamente";
        getch();
        system("cls");
        get();
    }
}

void Biblioteca::librarian()
{
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
    switch (i)
    {
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
        system("cls");
        get();
        break;
    case 6:
        password();
        break;
    case 7:
        exit(0);
    default:
        cout << endl << "Opcao invalida";
        getch();
        system("cls");
        librarian();
    }
}

void Biblioteca::password()
{
    int i = 0, j = 0;
    char ch, st[21], ch1[21] = {"pass"};
    system("cls");
    cout << endl << "*********** Mudar senha ***********";
    cout << endl << "Insira a senha atual: ";
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            st[i] = '\0';
            break;
        }
        else if (ch == 8 && i > 0)
        {
            i--;
            cout << "\b \b";
        }
        else
        {
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
    if (st[i] == '\0' && ch1[i] == '\0')
    {
        system("cls");
        cout << endl << "*********** Mudar senha ***********";
        cout << endl << "Insira a nova senha (menor que 20 caracteres e nao use espacos): ";
        cout << endl << "Senha: ";
        fflush(stdin);
        i = 0;
        while (1)
        {
            j++;
            ch = getch();
            if (ch == 13)
            {
                for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
                    ;
                if (j > 20 || st[i] == ' ')
                {
                    cout << endl << "Senha invalida, tenta novamente";
                    getch();
                    system("cls");
                    password();
                    librarian();
                }
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ofstream outf("password.txt");
        outf << st;
        outf.close();
        cout << endl << "Senha alterada com sucesso";
        cout << endl << "Pressione qualquer tecla para continuar";
        getch();
        system("cls");
        librarian();
    }
    else
    {
        cout << endl << "Senha incorreta";
        cout << endl << "Insira 1 para tentar novamente ou 2 para voltar ao menu anterior: ";
        cin >> i;
        if (i == 1)
        {
            system("cls");
            password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}