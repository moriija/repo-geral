#include <stdio.h>

int rotinaA(int vetor[])
{
    // Crie um vetor de inteiros de até 20 posições e inclua (via digitação) os valores para cada uma delas.

    printf("Criando vetor. digite ate 20 numeros inteiros; digite 0 para finalizar\n");

    // populando vetor com 0

    int num;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            vetor[i] = 0;
            break;
        }
        vetor[i] = num;
    }
}

int rotinaB(int vetor[])
{
    // Apresente na tela: o maior elemento do vetor (e sua posição), o menor elemento do vetor (e sua posição), a soma de todos os elementos do vetor e a média deles

    int maior = vetor[0];
    int menor = vetor[0];
    int posiMaior = 1;
    int posiMenor = 1;
    float soma = 0;
    int nElementos = 0;

    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] == 0)
        {
            break;
        }

        if (vetor[i] > maior)
        {
            maior = vetor[i];
            posiMaior = i + 1;
        }
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            posiMenor = i + 1;
        }
        soma = soma + vetor[i];
        nElementos++;
    }

    printf("maior: %d, posicao %d\n", maior, posiMaior);
    printf("menor: %d, posicao %d\n", menor, posiMenor);
    printf("Soma: %.0f\n", soma);
    printf("Media: %.2f\n", soma / nElementos);
}

int rotinaC(int x)
{
    // Elabore uma rotina que entre com um inteiro (variável x) como parâmetro. Indique quantas vezes o valor dessa variável x aparece entre os elementos do vetor e em quais posições
}

int main()
{
    int vetor[20];
    rotinaA(vetor);
    rotinaB(vetor);

    int x;
    printf("\nRotina C: digite o valor a ser analisado\n");
    scanf("%d", &x);
}