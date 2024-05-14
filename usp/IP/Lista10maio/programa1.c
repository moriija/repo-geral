#include <stdio.h>

int rotinaA(int vetor[])
{
    // Crie um vetor de inteiros de até 20 posições e inclua (via digitação) os valores para cada uma delas.

    printf("Criando vetor. digite até 20 números inteiros; digite 0 para finalizar\n");

    // populando vetor com 0

    int num;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            vetor[i] = NULL;
            break;
        }
        vetor[i] = num;
    }
}

int rotinaB(int vetor[])
{
    // Apresente na tela: o maior elemento do vetor (e sua posição), o menor elemento do vetor (e sua posição), a soma de todos os elementos do vetor e a média deles

    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] == NULL)
        {
            break;
        }
        printf("%d\n", vetor[i]);
    }
}

int rotinaC()
{
    // Elabore uma rotina que entre com um inteiro (variável x) como parâmetro. Indique quantas vezes o valor dessa variável x aparece entre os elementos do vetor e em quais posições
}

int main()
{
    int vetor[20];
    rotinaA(vetor);
    rotinaB(vetor);
}