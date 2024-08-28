#include <stdio.h>

// Apresente um programa na linguagem C que crie e insira os elementos em dois vetores distintos de inteiros de tamanho máximo 20 elementos. Este programa deve indicar quais elementos que estão no vetor 1 são repetidos no vetor 2.
// Para esse exercício assuma que não há repetições de elementos no vetor 1.

void verificarRepeticoes(int vetor1[], int tamanho1, int vetor2[], int tamanho2) {
    printf("Elementos do vetor 1 que são repetidos no vetor 2:\n");
    for (int i = 0; i < tamanho1; i++) {
        for (int j = 0; j < tamanho2; j++) {
            if (vetor1[i] == vetor2[j]) {
                printf("%d ", vetor1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int tamanho1, tamanho2;

    printf("Digite o número de elementos para o vetor 1 (máximo 20): ");
    scanf("%d", &tamanho1);

    printf("Digite o número de elementos para o vetor 2 (máximo 20): ");
    scanf("%d", &tamanho2);

    int vetor1[tamanho1], vetor2[tamanho2];

    printf("Preencha o vetor 1:\n");
    for (int i = 0; i < tamanho1; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Preencha o vetor 2:\n");
    for (int i = 0; i < tamanho2; i++) {
        scanf("%d", &vetor2[i]);
    }

    verificarRepeticoes(vetor1, tamanho1, vetor2, tamanho2);

    return 0;
}