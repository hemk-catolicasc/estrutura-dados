#include <stdio.h>
#include <stdlib.h>

int main() {
    float khw,valorTotal,valorHora;

    printf("Digite o valor da conta em kWh: ");
    scanf("%f", &khw);

    if (khw <= 100) {
        valorHora = 0.60;
    } else if (khw <= 250) {
        valorHora = 0.85;
    } else {
        valorHora = 1.10;
    }

    valorTotal = khw * valorHora;

    printf("Valor a ser pago por kWh: R$ %.2f\n", valorHora);
    printf("Valor total da conta: R$ %.2f\n", valorTotal);

    return 0;
}