// Isabella Cremonezi Morija - 14579951

#include <stdio.h>

// Função para ordenar o vetor usando o método de inserção
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elementos do arr[0..i-1] que são maiores que key
        // para uma posição à frente da sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para realizar busca binária
int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Verifica se x está presente no meio
        if (arr[m] == x)
            return m;

        // Se x for maior, ignora a metade esquerda
        if (arr[m] < x)
            l = m + 1;

        // Se x for menor, ignora a metade direita
        else
            r = m - 1;
    }

    // Se o elemento não estiver presente no array
    return -1;
}

int main() {
    int vetor[30];
    int n = 0; // Número atual de elementos no vetor
    int novo_numero, buscar_numero;
    char opcao;

    printf("Digite os numeros (maximo 30):\n");
    while (n < 30) {
        printf("Numero %d: ", n + 1);
        scanf("%d", &vetor[n]);
        n++;
        insertionSort(vetor, n);

        if (n < 30) {
            printf("Deseja inserir um novo numero (s/n)? ");
            scanf(" %c", &opcao);
            if (opcao == 'n' || opcao == 'N') {
                break;
            }
        }
    }

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite um numero para buscar: ");
    scanf("%d", &buscar_numero);

    int resultado = binarySearch(vetor, n, buscar_numero);

    if (resultado != -1) {
        printf("Numero encontrado na posicao: %d\n", resultado);
    } else {
        printf("Numero nao encontrado no vetor.\n");
    }

    return 0;
}