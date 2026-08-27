/*
 * 5. Construa um programa em C ANSI que leia o raio r e calcule a area do
 *    circulo em uma funcao void areaCirculo(float r, float *area) que grave
 *    o resultado em *area (usar pi = 3.141592), e no main imprima a area
 *    com duas casas decimais.
 */

#include <stdio.h>
#include <stdlib.h>

void areaCirculo(float r, float *area) {
    const float pi = 3.141592;
    *area = pi * r * r;
}

int main(void)
{   
    float r, area;
    printf("Digite o raio do circulo: ");
    scanf("%f", &r);
    areaCirculo(r, &area);
    printf("Area do circulo: %.2f\n", area);
    return 0;
}
