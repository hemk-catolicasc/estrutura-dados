#include <stdio.h>
#include <stdlib.h>

int maiorValor(int v[], int n) { 

    if (n == 1) {
        return v[0];
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }
    
    return maiorValor(v, n-1);
} 

int main() {
    int num;
    printf("digite o tamanho do vetor: ");
    scanf("%i", &num);
    int vetor[num];
  
    for (int i = 0; i < num; i++) {
        printf("Digite o valor do numero %i: ", i+1);
        scanf("%i", &vetor[i]);
    }

    printf("Vetor original: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", vetor[i]);
    }
    
    maiorValor(vetor, num);
    printf(" \n ");
    
    printf("Maior numero: %i", vetor[num-1]);
    
    return 0;
}