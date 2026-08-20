#include <stdio.h>
#include <stdlib.h>

int main() {

    int litros;
    float valor,desconto;
    float percentual,valorDesconto,valorBruto,valorLiquido;

    printf("Digite a quantidade de litros entregues: ");
    scanf("%i", &litros);
    printf("Digite o valor a ser cobrado pelo litro: ");
    scanf("%f", &valor);
    printf("Digite o percentual do desconto: ");
    scanf("%f", &desconto);

    valorBruto = litros * valor;
    percentual = desconto / 100;
    valorDesconto = valorBruto * percentual;
    valorLiquido = valorBruto - valorDesconto;

    printf("%i litros de leite a %.2f reais o litro. \n", litros, valor);
    printf("Valor bruto: %.2f \n", valorBruto);
    printf("Valor a ser descontado: %.2f \n", desconto);
    printf("Valor liquido: %.2f \n", valorLiquido);


    return 0;
}