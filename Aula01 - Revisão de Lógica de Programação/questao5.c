#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtdPontos, i;
    float n1,n2,n3,media;

    printf("Digite a quantidade de pontos: ");
    scanf("%i", &qtdPontos);

    for (i = 1; i <= qtdPontos; i++) {
        printf("Digite a nota 1 do ponto %i: ", i);
        scanf("%f", &n1);
        printf("Digite a nota 2 do ponto %i: ", i);
        scanf("%f", &n2);
        printf("Digite a nota 3 do ponto %i: ", i);
        scanf("%f", &n3);

        media = (n1 + n2 + n3) / 3;

        if (media < 40) {
            printf("O ponto %i esta seco com media %.2f\n", i, media);
        } else {
            printf("O ponto %i esta umido com media %.2f\n", i, media);
        }

    }

    return 0;
}