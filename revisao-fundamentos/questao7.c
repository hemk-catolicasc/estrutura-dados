#include <stdio.h>
#include <stdlib.h>

int main() {
    int codigo[8];
    int quantidade[8];
    int consulta;

    for (int i = 1; i <= 8; i++) {
        printf("Digite o codigo do produto %d: ", i);
        scanf("%d", &codigo[i]);
        printf("Digite a quantidade vendida do produto %d: ", i);
        scanf("%d", &quantidade[i]);
    }

    printf("Digite o codigo do produto que deseja consultar: ");
    scanf("%d", &consulta);

    for (int i = 1; i <= 8; i++) {
        if (codigo[i] == consulta) {
            printf("Produto encontrado: %d\n", codigo[i]);
            printf("Quantidade vendida: %d\n", quantidade[i]);
            break;
        } else {
            if (i == 8) {
                printf("Produto nao cadastrado no estoque.\n");
            }
        }
    }

    return 0;
}