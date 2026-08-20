/*
 * 2. Construa um programa em C ANSI que defina uma estrutura Animal com
 *    raca, cor, peso e sexo, armazene 10 animais em um vetor de estruturas,
 *    implemente uma funcao lerAnimal(Animal *a) e outra
 *    imprimirAnimal(const Animal *a), e ao final imprima todos os cadastros.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        char raca[50];
        char cor[20];
        float peso;
        char sexo;
    } Animal;
Animal Animais[10];

void lerAnimal(Animal *a) {
    printf("Digite a raca: ");
    scanf("%s", a->raca);
    printf("Digite a cor: ");
    scanf("%s", a->cor);
    printf("Digite o peso: ");
    scanf("%f", &a->peso);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &a->sexo);
}

void imprimirAnimal(const Animal *a) {
    printf("Raca: %s\n", a->raca);
    printf("Cor: %s\n", a->cor);
    printf("Peso: %.2f\n", a->peso);
    printf("Sexo: %c\n", a->sexo);
}

int main(void)
{   
    printf("Cadastro de Animais\n");
    for (int i = 0; i < 10; i++) {
        lerAnimal(&Animais[i]);
    }
    printf("\n");
    system("clear");
    printf("Animais cadastrados:\n");
    for (int i = 0; i < 10; i++) {
        imprimirAnimal(&Animais[i]);
    }

    return 0;
}
