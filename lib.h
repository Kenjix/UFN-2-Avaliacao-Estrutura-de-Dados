#include <cstdlib>
using namespace std;

typedef struct no
{
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int dado, Celula *lista)
{
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = dado;
    novo->prox = NULL;

    if (lista == NULL)
    {
        return novo;
    }
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox)
    {
        if (dado == p->dado)
            return lista; // controle de duplicados
    }

    p->prox = novo;
    return lista;
}

void exibir(Celula *lista)
{
    if (lista)
    {
        Celula *p;
        for (p = lista; p; p = p->prox)
        {
            cout << p->dado << " ";
        }
    }
    else
    {
        cout << "A lista esta vazia ou nao existe";
    }
}

Celula *ordenarBolha(Celula *lista)
{
    Celula *p;
    int tmp;
    bool houveTroca;

    do
    {
        houveTroca = false;
        for (p = lista; p->prox; p = p->prox)
        {
            if (p->dado > p->prox->dado)
            {
                houveTroca = true;
                tmp = p->dado;
                p->dado = p->prox->dado;
                p->prox->dado = tmp;
            }
        }
    } while (houveTroca);
    return lista;
}

Celula *remover(int valor, Celula *lista)
{
    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox)
    {
        if (valor == p->dado)
        {
            if (p == lista)
            {
                lista = lista->prox;
                free(p);
                return lista;
            }
            if (!p->prox)
            {
                pR->prox = NULL;
                free(p);
                return lista;
            }
            pR->prox = p->prox;
            free(p);
            return lista;
        }
    }
    return lista;
}

Celula *removePares(Celula *lista)
{
    if (lista)
    {
        Celula *p = lista;

        while (p)
        {
            Celula *prox = p->prox;

            if (p->dado % 2 == 0)
            {
                cout << "Removendo par da lista " << p->dado << "...\n";
                lista = remover(p->dado, lista);
            }

            p = prox;
        }
    }

    return lista;
}

Celula *unirListas(Celula *listaA, Celula *listaB)
{

    if (!listaA)
    {
        return listaB;
    }

    if (listaA && listaB)
    {
        Celula *p;
        for (p = listaA; p->prox != NULL; p = p->prox);

        p->prox = listaB;
    }

    return listaA;
}

Celula *removerTodos(Celula *lista)
{
    if (lista)
    {
        Celula *p = lista;

        while (p)
        {
            Celula *prox = p->prox;

            cout << "Removendo elemento da lista " << p->dado << "...\n";
            lista = remover(p->dado, lista);

            p = prox;
        }
    }

    return lista;
}