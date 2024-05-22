// Isabella Cremonezi Morija - Turma 04 -  n° 14579951
// Clara Pires Campardo - Turma 04 - n° 15446433

#include <stdio.h>

int popular(int vetor[])
{
    for (int i = 0; i < 20; i++)
    {
        vetor[i] = -1;
    }
    return 1;
}

int ordenar(int vetor[])
{
    int temp;
    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            if (i == 19)
                break;

            if (vetor[i] > vetor[i + 1])
            {
                temp = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = temp;
            }
        }
    }
    return 1;
}

int main()
{
    // a)
    int vet1[20];
    int vet2[20];
    popular(vet1);
    popular(vet2);

    int temp;

    printf("Insira elementos para vet1\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &temp);
        if (temp < 0)
            break;

        vet1[i] = temp;
    }

    printf("Insira elementos para vet2\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &temp);

        if (temp < 0)
            break;

        vet2[i] = temp;
    }

    printf("vetor antes: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d, ", vet1[i]);
    }
    printf("\n");

    // b)
    ordenar(vet1);
    ordenar(vet2);

    printf("vetor depois: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d, ", vet1[i]);
    }
    printf("\n");
}