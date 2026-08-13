/*
 * 1. Construa um programa em C ANSI que defina uma estrutura Pessoa
 *    (ex.: nome, idade, peso) e implemente duas funcoes:
 *    Pessoa lerPessoa(void) para preencher os campos via teclado e
 *    void imprimirPessoa(Pessoa p) para exibir os dados na tela.
 */

#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
        char nome[50];
        int idade;
        float peso;
    };

struct Pessoa lerPessoa() {
    struct Pessoa p;
    printf("Digite o nome: ");
    scanf("%s", p.nome);
    printf("Digite a idade: ");
    scanf("%i", &p.idade);
    printf("Digite o peso: ");
    scanf("%f", &p.peso);
    return p;
}

void imprimirPessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %i\n", p.idade);
    printf("Peso: %.2f\n", p.peso);
}

int main(void)
{ 
    struct Pessoa p = lerPessoa();
    imprimirPessoa(p);
    return 0;
}
