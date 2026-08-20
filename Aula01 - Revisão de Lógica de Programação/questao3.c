#include <stdio.h>
#include <stdlib.h>

int main() {
    int escolha;
    float valor,valorConvertido;

    printf("[1] - Converter de metros para centimetros\n");
    printf("[2] - Converter de quilogramas pra gramas\n");
    printf("[3] - Converter de horas para minutos \n");
    printf("[4] - Converter de litros para mililitros\n");
    printf("[5] - Sair");
    printf("\nDigite a sua escolha: ");
    scanf("%i", &escolha);

    switch (escolha) {
        case 1:
            printf("Digite o valor em metros: ");
            scanf("%f", &valor);
            valorConvertido = valor * 100;
            printf("%.2f metros equivalem a %.2f centimetros\n", valor, valorConvertido);
            break;
        case 2:
            printf("Digite o valor em quilogramas: ");
            scanf("%f", &valor);
            valorConvertido = valor * 1000;
            printf("%.2f quilogramas equivalem a %.2f gramas\n", valor, valorConvertido);
            break;
        case 3:
            printf("Digite o valor em horas: ");
            scanf("%f", &valor);
            valorConvertido = valor * 60;
            printf("%.2f horas equivalem a %.2f minutos\n", valor, valorConvertido);
            break;
        case 4:
            printf("Digite o valor em litros: ");
            scanf("%f", &valor);
            valorConvertido = valor * 1000;
            printf("%.2f litros equivalem a %.2f mililitros\n", valor, valorConvertido);
            break;
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Escolha invalida!\n");
    }
    return 0;
}