#include <iostream>

#define TAM_FILA 5

using namespace std;

class Valor
{
    int valor;
    Valor* ant;
public:
    int getValor()
    {
        return valor;
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
    int adicionarElemento(int valor)
    {
        if(elementos <= TAM_FILA)
            fila[elementos++] = valor;
        else
            return 0;
        return 1;
    }

    void removerElemento()
    {
        if(elementos == 0)
        {
            // TO-DO: NOPE!
        }
        else
        {
            // TO-DO: Mostrar fila[elementos]
            elementos--;
        }
    }

};

void adicionarValorPilha(int valor, Valor* topo)
{
    if(topo==NULL)
        topo = new Valor(valor, NULL);
    topo = new Valor(valor, topo);
}

void moverValorPilha(Valor* topo, Fila* fila)
{
    if(topo != NULL)
    {
        // Se a fila não está cheia
        if(fila->adicionarElemento(topo->getValor()))
        {
            Valor* tmp = topo;
            // TO-DO: Mostrar valor removido
            delete topo;
            topo = tmp;
        }
        else
        {
            // TO-DO: Fila cheia!!!
        }
    }
    else
    {
        // TO-DO: Pilha vazia
    }
}

int main()
{
    Valor* topo_pilha = NULL;
    int in;

    cout << "1. Inserir valor em uma pilha encadeada" << endl;
    cout << "2. Mover valor da pilha para uma fila sequencial" << endl;
    cout << "3. Consultar o valor do topo da pilha e da fila" << endl;
    cout << "4. Remover valor da fila" << endl;
    cout << "0. Sair" << endl;
    cout << "==================================================" << endl;
    cin >> in;

    switch(in)
    {
    case 0:
        return;
        break;
    case 1:
        adicionarValorPilha();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }



    return 0;
}


