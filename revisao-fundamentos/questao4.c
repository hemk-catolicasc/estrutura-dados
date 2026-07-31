#include <stdio.h>
#include <stdlib.h>

int main() {
    float valorVenda,valorTotal = 0;
    int vendasTotal = 0;
    do {
        printf("Valor da venda: ");
        scanf("%f", &valorVenda);
        valorTotal += valorVenda;
        vendasTotal += 1;
    } while (valorVenda != 0);

    printf("Valor total das vendas: %.2f\n", valorTotal);
    printf("Total de vendas realizadas: %i\n", vendasTotal - 1);
    printf("Valor medio das vendas: %.2f\n", valorTotal / (vendasTotal - 1));
    return 0;
}