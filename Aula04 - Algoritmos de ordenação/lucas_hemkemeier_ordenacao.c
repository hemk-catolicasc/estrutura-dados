/*
Disciplina: Estrutura de Dados
Atividade: Comparacao de desempenho entre metodos de ordenacao
Aluno: Lucas Hemkemeier

Conseguiu chegar nos valores de referencia?
R: Sim, consegui chegar exatamente aos valores de referencia e aos vistos no simulador
Se nao, em quais metodos e por que?
R:

Metodos analisados:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 10000
#define NCARTAS 8
#define NMETODOS 5
#define RODADAS 3

/* contadores globais */
long comparacoes, trocas, movimentacoes;

int vetorBase[TAM], vetorTeste[TAM], temp[TAM];

typedef struct {
    double comp, troc, mov, ms;
} Resultado;

const char *nomes[NMETODOS] = {"Bubble", "Selection", "Insertion", "Merge", "Quick"};

/* ---------------- metodos ---------------- */

void bubbleSort(int v[], int tam) {
    int i, n, aux, troca;
    n = 1;
    troca = 1;
    while (n <= tam && troca == 1) {
        troca = 0;
        for (i = 0; i < tam - 1; i++) {
            comparacoes++;                 /* v[i] > v[i+1], entre vizinhos */
            if (v[i] > v[i + 1]) {
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocas++;                  /* par fora de ordem */
                movimentacoes += 3;        /* 3 atribuicoes da troca */
            }
        }
        n++;
    }
}

void selectionSort(int v[], int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;                 /* v[j] < v[min], busca do menor */
            if (v[j] < v[min])
                min = j;
        }
        if (min != i) {                    /* so troca se o menor mudou */
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            trocas++;
            movimentacoes += 3;
        }
    }
}

void insertionSort(int v[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        movimentacoes++;                   /* guardar a chave */
        j = i - 1;
        /* j >= 0 e controle; so v[j] > chave conta como comparacao */
        while (j >= 0) {
            comparacoes++;
            if (!(v[j] > chave))
                break;
            v[j + 1] = v[j];
            movimentacoes++;               /* deslocamento */
            j--;
        }
        v[j + 1] = chave;
        movimentacoes++;                   /* insercao da chave */
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while (i <= meio && j <= fim) {
        comparacoes++;                     /* v[i] <= v[j], na intercalacao */
        if (v[i] <= v[j]) {
            temp[k] = v[i];
            i++;
        } else {
            temp[k] = v[j];
            j++;
        }
        movimentacoes++;                   /* copia para temp */
        k++;
    }
    while (i <= meio) {
        temp[k] = v[i];
        movimentacoes++;                   /* sobra da esquerda para temp */
        i++;
        k++;
    }
    while (j <= fim) {
        temp[k] = v[j];
        movimentacoes++;                   /* sobra da direita para temp */
        j++;
        k++;
    }
    for (i = inicio; i <= fim; i++) {
        v[i] = temp[i];
        movimentacoes++;                   /* copia de volta para v */
    }
}

void mergeSort(int v[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void troca(int *a, int *b) {
    int aux;
    if (a == b)                            /* mesma posicao nao e troca */
        return;
    aux = *a;
    *a = *b;
    *b = aux;
    trocas++;
    movimentacoes += 3;
}

int particiona(int v[], int inicio, int fim) {
    int pivo, i, j;
    pivo = v[fim];
    movimentacoes++;                       /* guardar o pivo */
    i = inicio - 1;
    for (j = inicio; j < fim; j++) {
        comparacoes++;                     /* v[j] < pivo, na particao */
        if (v[j] < pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

void quickSort(int v[], int inicio, int fim) {
    int posPivo;
    if (inicio < fim) {
        posPivo = particiona(v, inicio, fim);
        quickSort(v, inicio, posPivo - 1);
        quickSort(v, posPivo + 1, fim);
    }
}

/* ---------------- apoio ---------------- */

/* op 1: ordenado, op 2: invertido, op 3: aleatorio */
void geraNumero(int v[], int n, int op) {
    int i;
    for (i = 0; i < n; i++) {
        if (op == 1)
            v[i] = i + 1;
        else if (op == 2)
            v[i] = n - i;
        else
            v[i] = rand() % 10000;
    }
}

/* copia vetorBase para vetorTeste, zera contadores e mede so a ordenacao */
Resultado executa(int metodo, int n) {
    Resultado r;
    clock_t inicio, fim;
    int i;

    for (i = 0; i < n; i++)
        vetorTeste[i] = vetorBase[i];
    comparacoes = trocas = movimentacoes = 0;

    inicio = clock();
    switch (metodo) {
        case 0: bubbleSort(vetorTeste, n); break;
        case 1: selectionSort(vetorTeste, n); break;
        case 2: insertionSort(vetorTeste, n); break;
        case 3: mergeSort(vetorTeste, 0, n - 1); break;
        case 4: quickSort(vetorTeste, 0, n - 1); break;
    }
    fim = clock();

    for (i = 1; i < n; i++)
        if (vetorTeste[i - 1] > vetorTeste[i]) {
            printf("ERRO: %s nao ordenou o vetor\n", nomes[metodo]);
            exit(1);
        }

    r.comp = comparacoes;
    r.troc = trocas;
    r.mov = movimentacoes;
    r.ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    return r;
}

void linha(void) {
    printf("=====================================================================\n");
}

void imprimeTabela(const char *titulo, Resultado r[]) {
    int m;
    linha();
    printf("%s\n", titulo);
    linha();
    printf("%-10s %15s %12s %15s %12s\n", "Metodo", "Comparacoes", "Trocas", "Movimentacoes", "Tempo (ms)");
    for (m = 0; m < NMETODOS; m++)
        printf("%-10s %15.0f %12.0f %15.0f %12.2f\n", nomes[m], r[m].comp, r[m].troc, r[m].mov, r[m].ms);
    printf("\n");
}

/* imprime o(s) melhor(es) metodo(s) no indicador; empates aparecem juntos */
void imprimeMelhor(Resultado r[], int indicador) {
    double v[NMETODOS], menor;
    char txt[64] = "";
    int m;
    for (m = 0; m < NMETODOS; m++)
        v[m] = indicador == 0 ? r[m].comp : indicador == 1 ? r[m].mov : r[m].ms;
    menor = v[0];
    for (m = 1; m < NMETODOS; m++)
        if (v[m] < menor)
            menor = v[m];
    for (m = 0; m < NMETODOS; m++)
        if (v[m] == menor) {
            if (txt[0] != '\0')
                sprintf(txt + strlen(txt), "/");
            sprintf(txt + strlen(txt), "%s", nomes[m]);
        }
    printf(" %-22s", txt);
}

/* ---------------- validacao com as 8 cartas ---------------- */

void validaCartas(void) {
    /* sequencia inicial das 8 cartas sorteadas no simulador */
    int cartas[NCARTAS] = {11, 5, 3, 10, 8, 13, 9, 12};
    Resultado r[NMETODOS];
    int i, m;

    for (i = 0; i < NCARTAS; i++)
        vetorBase[i] = cartas[i];
    for (m = 0; m < NMETODOS; m++)
        r[m] = executa(m, NCARTAS);

    printf("Sequencia inicial das cartas:");
    for (i = 0; i < NCARTAS; i++)
        printf(" %d", cartas[i]);
    printf("\n");
    imprimeTabela("VALIDACAO - 8 CARTAS DO SIMULADOR", r);
}

/* ---------------- principal ---------------- */

int main(void) {
    Resultado res[3][NMETODOS], r;
    const char *titulos[3] = {
        "CENARIO 1 - DADOS ORDENADOS - 10000 ELEMENTOS",
        "CENARIO 2 - DADOS INVERTIDOS - 10000 ELEMENTOS",
        "CENARIO 3 - DADOS ALEATORIOS - 10000 ELEMENTOS (MEDIA DE 3 EXECUCOES)"
    };
    const char *cenarios[3] = {"Ordenados", "Invertidos", "Aleatorios"};
    int c, m, rodada, rodadas;

    srand((unsigned)time(NULL));

    validaCartas();

    for (c = 0; c < 3; c++) {
        for (m = 0; m < NMETODOS; m++)
            res[c][m].comp = res[c][m].troc = res[c][m].mov = res[c][m].ms = 0;

        /* ordenado e invertido: 1 execucao; aleatorio: 3 rodadas e media */
        rodadas = (c == 2) ? RODADAS : 1;
        for (rodada = 0; rodada < rodadas; rodada++) {
            geraNumero(vetorBase, TAM, c + 1);   /* vetor novo por rodada */
            for (m = 0; m < NMETODOS; m++) {
                r = executa(m, TAM);             /* mesma copia para os cinco */
                res[c][m].comp += r.comp / rodadas;
                res[c][m].troc += r.troc / rodadas;
                res[c][m].mov += r.mov / rodadas;
                res[c][m].ms += r.ms / rodadas;
            }
        }
        imprimeTabela(titulos[c], res[c]);
    }

    /* trocas ficam fora do resumo: Insertion e Merge nao trocam por natureza */
    linha();
    printf("RESUMO\n");
    linha();
    printf("%-11s %-22s %-22s %-22s\n", "Cenario", "Menos comparacoes", "Menos movimentacoes", "Menor tempo");
    for (c = 0; c < 3; c++) {
        printf("%-11s", cenarios[c]);
        imprimeMelhor(res[c], 0);
        imprimeMelhor(res[c], 1);
        imprimeMelhor(res[c], 2);
        printf("\n");
    }

    return 0;
}
