// 4. Adapte a estrutura da lista simplesmente encadeada para uma lista duplamente encadeada, incluindo o ponteiro para o elemento anterior.
// Em seguida, implemente uma função de inserção no início e outra de inserção no final da lista. 
// Ao final, exiba todos os elementos armazenados, mostrando que o encadeamento foi realizado corretamente. 
// A seguir, mostre a lista em ambos os sentidos para confirmar que os ponteiros estão corretos.
// As ligações que a inserção no final altera estão descritas na seção da lista duplamente encadeada. 
// Um jeito de conferir que os ponteiros ant também estão certos é exibir a lista nos dois sentidos, 
// como no exemplo completo da lista dupla: o percurso de trás para a frente precisa dar a mesma sequência ao contrário.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *ant;
    struct lista *prox;
}LISTA;

LISTA *inserirInicio(LISTA *l, int valor) {
    LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
    novo->num = valor;
    novo->ant = NULL;
    novo->prox = l;
    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

LISTA *inserirFinal(LISTA *l, int valor) {
    LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
    LISTA *aux;
    novo->num = valor;
    novo->prox = NULL;

    if (l == NULL) {
        novo->ant = NULL;
        return novo;
    }

    aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
    return l;
}

void exibirFrente(LISTA *l) {
    LISTA *aux = l;
    printf("Frente: ");
    while (aux != NULL) {
        printf("%d <-> ", aux->num);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void exibirTras(LISTA *l) {
    LISTA *aux = l;
    printf("Tras: ");
    if (aux == NULL) {
        printf("NULL\n");
        return;
    }
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    while (aux != NULL) {
        printf("%d <-> ", aux->num);
        aux = aux->ant;
    }
    printf("NULL\n");
}

int main() {
    LISTA *l = NULL;
    LISTA *aux;

    l = inserirFinal(l, 10);
    l = inserirFinal(l, 20);
    l = inserirInicio(l, 5);

    exibirFrente(l);
    exibirTras(l);

    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }

    return 0;
}
