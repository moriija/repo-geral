#include <stdio.h>

// Apresente um programa similar ao do exercício 3 mas dessa vez podem haver repetições de elementos no vetor 1. Nesse caso, apenas um dos elementos do vetor 1 deve ser considerado para a análise.

void preencherVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int estaNoVetor(int x, int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (vetor[i] == x) {
            return 1;
        }
    }
    return 0;
}

void verificarRepeticoes(int vetor1[], int tam1, int vetor2[], int tam2) {
    int vetor1SemRep[tam1];
    int tam1SemRep = 0;

    // remover duplos do vetor 1
    for (int i = 0; i < tam1; i++) {
        if (estaNoVetor(vetor1[i], vetor1SemRep, tam1SemRep) == 0) {
            vetor1SemRep[tam1SemRep] = vetor1[i];
            tam1SemRep++;
        }
    }

    printf("Elementos do vetor 1 que são repetidos no vetor 2:\n");
    for (int i = 0; i < tam1SemRep; i++) {
        for (int j = 0; j < tam2; j++) {
            if (vetor1SemRep[i] == vetor2[j]) {
                printf("%d ", vetor1SemRep[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int tam1, tam2;

    printf("Digite o número de elementos para o vetor 1 (máximo 20): ");
    scanf("%d", &tam1);

    printf("Digite o número de elementos para o vetor 2 (máximo 20): ");
    scanf("%d", &tam2);

    int vetor1[tam1], vetor2[tam2];

    printf("Preencha o vetor 1:\n");
    for (int i = 0; i < tam1; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Preencha o vetor 2:\n");
    for (int i = 0; i < tam2; i++) {
        scanf("%d", &vetor2[i]);
    }

    verificarRepeticoes(vetor1, tam1, vetor2, tam2);

    return 0;
}