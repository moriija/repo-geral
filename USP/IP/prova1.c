# include <stdio.h>

// Q1 - Converter Celsius para Fahrenheit
double temperatura(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Q2 - Converter Decimal para Binário
void printBinario(int n) {
    if (n > 1) {
        printBinario(n / 2);
    }
    printf("%d", n % 2);
}

// Q3 - Calcular o Maior, o Menor e a Média de N Números Reais
void processnums() {
    int N;
    printf("Digite o número de elementos: ");
    scanf("%d", &N);
    
    double num, max, min, soma = 0.0;
    
    for (int i = 0; i < N; i++) {
        printf("Digite um número: ");
        scanf("%lf", &num);

        if(i==0){
            max = num;
            min = num;
        }
        if (num > max) max = num;
        if (num < min) min = num;
        soma += num;
    }
    
    double average = soma / N;
    printf("Maior número: %.2f\nMenor número: %.2f\nMédia: %.2f\n", max, min, average);
}

// Q4 - Criar Vetores com Menores e Maiores Valores de Índices Correspondentes
void compararArrays() {
    int vet1[10], vet2[10], minVet[10], maxVet[10];
    
    // Leitura dos vetores
    printf("Digite os valores para o vetor 1:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet1[i]);
    }
    
    printf("Digite os valores para o vetor 2:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet2[i]);
    }
    
    // Encontrar min e max para cada índice
    for (int i = 0; i < 10; i++) {
        minVet[i] = (vet1[i] < vet2[i]) ? vet1[i] : vet2[i];
        maxVet[i] = (vet1[i] > vet2[i]) ? vet1[i] : vet2[i];
    }
    
    // Imprimir os vetores min e max
    printf("Vetor de menores valores: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", minVet[i]);
    }
    printf("\nVetor de maiores valores: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", maxVet[i]);
    }
    printf("\n");
}

// Q5 - Calcular Média Descartando Maior e Menor Nota
double calcularNota(double notas[]){
    double max = notas[0], min = notas[0], soma = notas[0];
    
    for (int i = 1; i < 6; i++) {
        if (notas[i] > max) max = notas[i];
        if (notas[i] < min) min = notas[i];
        soma += notas[i];
    }
    
    return (soma - max - min) / (4);
}