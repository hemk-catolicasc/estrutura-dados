#include <stdio.h>
#include <stdlib.h>

int main() {
    int minutos[10];
    int totalMinutos = 0;
    int acimaMedia = 0;

    for (int i = 1; i <= 10; i++) {
        printf("Digite o tempo gasto no %i ° atendimento: ", i );
        scanf("%d", &minutos[i]);
        totalMinutos += minutos[i];
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = i + 1; j <= 10; j++) {
            if (minutos[i] > minutos[j]) {
                int aux = minutos[i];
                minutos[i] = minutos[j];
                minutos[j] = aux;
            }
        }
    }

    float media = (float)totalMinutos / 10;

    for (int i = 1; i <= 10; i++) {
        if (minutos[i] > media) {
            acimaMedia += 1;
        }
    }

    printf("Tempo medio gasto: %.2f minutos\n", media);
    printf("Maior tempo gasto: %d minutos\n", minutos[10]);
    printf("Menor tempo gasto: %d minutos\n", minutos[1]);
    printf("Numero de atendimentos acima da media: %d\n", acimaMedia);

    return 0;
}