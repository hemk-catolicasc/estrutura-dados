// 1. Implemente um programa em C que crie uma lista simplesmente encadeada e permita a inserção de 5 valores inteiros informados pelo usuário.
// Ao final, o programa deverá percorrer a lista e exibir todos os elementos armazenados, na ordem em que estiverem encadeados.
// A inserção pode ser no início ou no final. Com inserção no final, a lista sai na ordem digitada; com inserção no início, sai na ordem inversa.
// As duas respostas estão certas, desde que a exibição mostre a lista como ela ficou.
// Para conferir: digitando 3, 8, 1, 6 e 4, com inserção no final, a saída é 3 -> 8 -> 1 -> 6 -> 4 -> NULL; com inserção no início, é 4 -> 6 -> 1 -> 8 -> 3 -> NULL.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *prox;
}LISTA;

int main() {
    int numero;
    LISTA *l = NULL;
    LISTA *aux;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &numero);
        LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
        novo->num = numero;
        novo->prox = l;
        l = novo;
    }

    aux = l;
    while (aux != NULL) {
        printf("%d -> ", aux->num);
        aux = aux->prox;
    }
    printf("NULL\n");

    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }

    return 0;
}
