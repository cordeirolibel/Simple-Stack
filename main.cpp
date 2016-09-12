#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <limits>

#define TAM_FILA 5

using namespace std;

void imprimeMenu(bool tudo=true)
{
    system("cls");
    cout << "   ____                            ___               ____    __                    __          " << endl;
    cout << "  /\\  _`\\   __                    /\\_ \\             /\\  _`\\ /\\ \\__                /\\ \\         " << endl;
    cout << "  \\ \\,\\L\\_\\/\\_\\    ___ ___   _____\\//\\ \\      __    \\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\     " << endl;
    cout << "   \\/_\\__ \\\\/\\ \\ /' __` __`\\/\\ '__`\\\\ \\ \\   /'__`\\   \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , <     " << endl;
    cout << "     /\\ \\L\\ \\ \\ \\/\\ \\/\\ \\/\\ \\ \\ \\L\\ \\\\_\\ \\_/\\  __/     /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\   " << endl;
    cout << "     \\ `\\____\\ \\_\\ \\_\\ \\_\\ \\_\\ \\ ,__//\\____\\ \\____\\    \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ " << endl;
    cout << "      \\/_____/\\/_/\\/_/\\/_/\\/_/\\ \\ \\/ \\/____/\\/____/     \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/ " << endl;
    cout << "                               \\ \\_\\                                                           " << endl;
    cout << "                                \\/_/                                                           " << endl;
    cout << "==============================================================================================" << endl;
    if(tudo)
    {
        cout << " Selecione uma opção:" << endl;
        cout << "   1. Inserir valor em uma pilha encadeada" << endl;
        cout << "   2. Mover valor da pilha para uma fila sequencial" << endl;
        cout << "   3. Consultar o valor do topo da pilha e da fila" << endl;
        cout << "   4. Remover valor da fila" << endl;
        cout << "   0. Sair" << endl;
         cout << "==============================================================================================" << endl;
        cout << ">>";
    }
}

int lerEntrada(char* print)
{
    int input = -1;
    bool valid= false;
    do
    {
        cout << print;
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << " Entrada inválida!" << endl;
        }
    }
    while (!valid);
    return (input);
}

class Valor
{
    int valor;
    Valor* ant;
public:
    int getValor()
    {
        return valor;
    }
    Valor* getAnt()
    {
        return ant;
    }
    Valor(int _valor, Valor* _ant)
    {
        valor = _valor;
        ant = _ant;
    }
};

class Fila
{
    int fila[TAM_FILA];
    int elementos = 0;
public:
    int getElementos()
    {
        return elementos;
    }

    int retornaElemento(int index)
    {
        return fila[index];
    }

    int adicionarElemento(int valor)
    {
        if(elementos <= TAM_FILA)
            fila[elementos++] = valor;
        else
            return 0;
        return 1;
    }

    int removerElemento()
    {
        if(elementos != 0)
        {
            elementos--;
            return 1;
        }
        return 0;
    }
};

void adicionarValorPilha(Valor** topo)
{
    imprimeMenu(false);
    cout << " 1. Inserir valor em uma pilha encadeada" << endl;
    int valor = lerEntrada("  Valor que será adicionado à pilha: ");
    if((*topo)==NULL)
        (*topo) = new Valor(valor, NULL);
    else
        (*topo) = new Valor(valor, (*topo));

    system("pause");
}

void moverValorPilha(Valor** topo, Fila** fila)
{
    imprimeMenu(false);
    cout << " 2. Mover valor da pilha para uma fila sequencial" << endl;
    if((*topo) != NULL)
    {
        // Se a fila não está cheia
        if((*fila)->adicionarElemento((*topo)->getValor()))
        {
            cout << "   Valor movido: " << (*topo)->getValor() << endl;
            Valor* tmp = (*topo)->getAnt();
            delete (*topo);
            (*topo) = tmp;
        }
        else
        {
            cout << "   Fila cheia! Valor não foi movido!" << endl;
        }
    }
    else
    {
        cout << "   Pilha vazia! Valor não foi movido!" << endl;
    }

    system("pause");
}

void consultarElementos(Valor** topo, Fila** fila)
{
    imprimeMenu(false);
    cout << " 3. Consultar o valor do topo da pilha e da fila" << endl;

    if((*topo) != NULL)
        cout << "   Topo da pilha: " << (*topo)->getValor() << endl;
    else
        cout << "   Pilha vazia!" << endl;

    if((*fila)->getElementos() != 0)
        cout << "   Topo da fila: " << (*fila)->retornaElemento((*fila)->getElementos()-1) << endl;
    else
        cout << "   Fila vazia!" << endl;

    system("pause");
}

void removerElementoFila(Fila** fila)
{
    imprimeMenu(false);
    cout << " 4. Remover valor da fila" << endl;
    if((*fila)->removerElemento())
        cout << "   Valor removido: " << (*fila)->retornaElemento((*fila)->getElementos()) << endl;
    else
        cout << "   Fila vazia, nenhum elemento removido!" << endl;

    system("pause");
}

int main()
{
    Valor* topo_pilha = NULL;
    Fila* fila = new Fila();
    char ent;

    setlocale(LC_ALL, "Portuguese");

    while(1)
    {
        imprimeMenu();

        cin >> ent;

        switch(ent)
        {
        case '0':
            return 0;
            break;
        /// Inserir valor em uma pilha encadeada
        case '1':
            adicionarValorPilha(&topo_pilha);
            break;
        /// Mover valor da pilha para uma fila sequencial
        case '2':
            moverValorPilha(&topo_pilha, &fila);
            break;
        /// Consultar o valor do topo da pilha e da fila
        case '3':
            consultarElementos(&topo_pilha, &fila);
            break;
        /// Remover valor da fila
        case '4':
            imprimeMenu(false);
            removerElementoFila(&fila);
            break;
        /// Entrada inválida
        default:
            break;
        }
    }
    return 0;
}
