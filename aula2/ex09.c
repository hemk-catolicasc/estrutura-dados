/*
 * 9. Implemente uma funcao em C ANSI chamada
 *    void imprimirNaPosicao(int linha, int coluna, char *msg) que utilize a
 *    biblioteca windows.h e a funcao SetConsoleCursorPosition() para
 *    posicionar o cursor na linha e coluna informadas e imprimir a mensagem,
 *    e no programa principal (main) solicite ao usuario os valores de linha,
 *    coluna e a mensagem para testar a funcao.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void imprimirNaPosicao(int linha, int coluna, char *msg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicao;
    posicao.X = coluna;
    posicao.Y = linha;
    SetConsoleCursorPosition(hConsole, posicao);
    printf("%s", msg);
}

int main(void)
{
    int linha, coluna;
    char msg[100];

    printf("Digite a linha: ");
    scanf("%d", &linha);
    printf("Digite a coluna: ");
    scanf("%d", &coluna);
    printf("Digite a mensagem: ");
    scanf("%s", msg);

    imprimirNaPosicao(linha, coluna, msg);

    return 0;
}
