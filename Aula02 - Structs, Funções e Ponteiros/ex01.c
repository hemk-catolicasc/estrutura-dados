/*
 * 1. Construa um programa em C ANSI que defina uma estrutura Pessoa
 *    (ex.: nome, idade, peso) e implemente duas funcoes:
 *    Pessoa lerPessoa(void) para preencher os campos via teclado e
 *    void imprimirPessoa(Pessoa p) para exibir os dados na tela.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TAM 5

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

// Variavel global
int qtd = 0;

Pessoa entrada(void);
void saida (Pessoa a);

int main (void)
{   
    int opcao;
    Pessoa bd[TAM];

    do {
        system("clear");
        printf("1 - Adicionar \n");
        printf("2 - Listar \n");
        printf("3 - Sair \n");
        printf("Digite a opcao: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: {
                if (qtd >= TAM) {
                    printf("Banco de dados cheio. Nao e possivel adicionar mais pessoas.\n");
                } else {
                    bd[qtd] = entrada();
                    qtd++;
                    printf("Pessoa adicionada com sucesso.\n");
                }
                break;
            }
            case 2: {
                if (qtd == 0) {
                    printf("Nenhuma pessoa cadastrada.\n");
                } else {
                    for (int i = 0; i < qtd; i++) {
                        saida(bd[i]);
                    }
                }
                break;
            }
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);
    return 0;
}

//função entrada
Pessoa entrada(void) {
    Pessoa a;

    printf("Digite o nome: ");
    scanf("%s", a.nome);
    printf("Digite a idade: ");
    scanf("%i", &a.idade);
    printf("Digite a altura: ");
    scanf("%f", &a.altura);
    return a;
}

//função saída
void saida (Pessoa a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %i\n", a.idade);
    printf("Altura: %.2f\n", a.altura);
}