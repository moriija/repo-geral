#include <stdio.h>

void rotinaA(int vetor[])
{
    // Crie um vetor de inteiros de até 20 posições e inclua (via digitação) os valores para cada uma delas.

    printf("Criando vetor. digite ate 20 numeros inteiros; digite -1 para finalizar\n");

    int num;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        if (num < 0)
        {
            vetor[i] = -1;
            break;
        }
        vetor[i] = num;
    }
    return;
}

void rotinaB(int vetor[])
{
    // Apresente na tela: o maior elemento do vetor (e sua posição), o menor elemento do vetor (e sua posição), a soma de todos os elementos do vetor e a média deles

    int maior = vetor[0];
    int menor = vetor[0];
    int posiMaior = 0;
    int posiMenor = 0;
    float soma = 0;
    int nElementos = 0;

    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] < 0) break;

        if (vetor[i] > maior)
        {
            maior = vetor[i];
            posiMaior = i;
        }
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            posiMenor = i;
        }
        soma = soma + vetor[i];
        nElementos++;
    }

    printf("\nOBS: posição se inicia com 0.\n");
    printf("maior: %d, posicao %d\n", maior, posiMaior);
    printf("menor: %d, posicao %d\n", menor, posiMenor);
    printf("Soma: %.0f\n", soma);
    printf("Media: %.2f\n", soma / nElementos);

    return;
}

void rotinaC(int x, int vetor[])
{
    // Elabore uma rotina que entre com um inteiro (variável x) como parâmetro. Indique quantas vezes o valor dessa variável x aparece entre os elementos do vetor e em quais posições
    int xEmVetor = 0;

    for(int i =0; i<20; i++)
    {
        if(vetor[i] < 0) break;

        if(x == vetor[i]){
            printf("x na posicao %d.\n", i);
            xEmVetor++;
        }
    }
    printf("x=%d apareceu %d vezes no vetor.\n", x, xEmVetor);

    return;
}

int main()
{
    int vetor[20];
    rotinaA(vetor);
    rotinaB(vetor);

    int x = 0;
    while(x < 0)
    {
        printf("\nRotina C: digite o valor da variável x: ");
        scanf("%d", &x);
    }
    rotinaC(x, vetor);
}