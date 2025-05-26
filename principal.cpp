#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lib.h"

int main()
{
    Celula *listaA = NULL;
    Celula *listaB = NULL;
    int quantidade = 30;
    srand(time(NULL));

    while (quantidade > 0)
    {
        listaA = inserir(rand() % 100, listaA);
        listaB = inserir(rand() % 100, listaB);
        quantidade--;
    }

    cout << "\nElementos da lista A:\n";
    exibir(listaA);

    cout << "\nElementos da lista B:\n";
    exibir(listaB);

    cout << "\n\nRemovendo os elementos pares da listaA\n";
    listaA = removePares(listaA);

    // unir listas
    cout << "\nunindo listas...\n";
    Celula *listaUnificada = NULL;
    listaUnificada = unirListas(listaA, listaB);
    exibir(listaUnificada);

    // ordenar lista unificada
    ordenarBolha(listaUnificada);
    cout << "\n\nExibindo lista unificada ordenada:\n";   
    exibir(listaUnificada);

    // exclusao lista unificada
    cout << "\n\nExcluindo elementos da lista unificada ordenada...\n";   
    listaUnificada = removerTodos(listaUnificada);
    cout << "\nExibindo lista unificada ordenada apos delesao:\n";  
    exibir(listaUnificada);

    return 1;
}