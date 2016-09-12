#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <limits>

#define TAM_FILA 5

using namespace std;

//imprime o menu podendo ou não imprimir as opções
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
        cout << "   5. Imprimir valores da fila" << endl;
        cout << "   0. Sair" << endl;
         cout << "==============================================================================================" << endl;
        cout << ">>";
    }
}

int lerEntrada(const char* print)
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
    int *fila;
    int elementos;
    int tam_fila;

public:
    Fila(int _tam_fila)
    {
        tam_fila = _tam_fila;
        fila = new int[tam_fila];
        elementos = 0;
    }
    ~Fila(){
        delete fila;
    }
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
        if(elementos < tam_fila)
            fila[elementos++] = valor;
        else
            return 0;
        return 1;
    }

    void removerElemento()
    {
        //reagrupa, remove o primeiro elemento
        for(int i=0;i<(elementos-1);i++)
            fila[i] = fila[i+1];
        elementos--;
    }

    void imprimirValores()
    {
        cout << " Valores da fila - " << elementos << "/" << tam_fila << " Elementos" <<  endl;
        for(int i=0;i<elementos;i++)
            cout << i+1 << " - " << fila[i] << endl;
        system("pause");
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
    //Se a pilha não esta vazia
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
        cout << "   Primeiro da fila: " << (*fila)->retornaElemento(0) << endl;
    else
        cout << "   Fila vazia!" << endl;

    system("pause");
}

void removerElementoFila(Fila** fila)
{
    imprimeMenu(false);
    cout << " 4. Remover valor da fila" << endl;
    if((*fila)->getElementos()){
        cout << "   Valor removido: " << (*fila)->retornaElemento(0) << endl;
        (*fila)->removerElemento();
    }
    else
        cout << "   Fila vazia, nenhum elemento removido!" << endl;

    system("pause");
}



int main()
{
    Valor* topo_pilha = NULL;
    Fila* fila = new Fila(TAM_FILA);
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
            removerElementoFila(&fila);
            break;
        /// Imprimir valores da fila
        case '5':
            imprimeMenu(false);
            fila->imprimirValores();
            break;
        /// Entrada inválida
        default:
            break;
        }
    }

    delete fila;
    return 0;
}
