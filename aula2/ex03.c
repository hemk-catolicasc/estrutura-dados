/*
 * 3. Construa um programa em C ANSI que defina uma estrutura Peca com
 *    codigo, nome, cor, peso e preco, implemente lerPeca(Peca *p) e
 *    imprimirPeca(Peca *p).
 */

#include <stdio.h>
#include <stdlib.h>

struct Peca {
        int codigo;
        char nome[50];
        char cor[20];
        float peso;
        float preco;
    };

struct Peca lerPeca() {
    struct Peca p;
    printf("Digite o codigo: ");
    scanf("%i", &p.codigo);
    printf("Digite o nome: ");
    scanf("%s", p.nome);
    printf("Digite a cor: ");
    scanf("%s", p.cor);
    printf("Digite o peso: ");
    scanf("%f", &p.peso);
    printf("Digite o preco: ");
    scanf("%f", &p.preco);
    return p;
}

void imprimirPeca(struct Peca p) {
    printf("Codigo: %i\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Cor: %s\n", p.cor);
    printf("Peso: %.2f\n", p.peso);
    printf("Preco: %.2f\n", p.preco);
}

int main(void)
{ 
    struct Peca p = lerPeca();
    imprimirPeca(p);
    return 0;
}

