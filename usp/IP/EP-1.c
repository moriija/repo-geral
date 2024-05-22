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

// CONSERTAR PARA i=40, PARA merge[40]
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

int get_merge(int vet1[], int vet2[], int merge[])
{
    int parou = 0;
    // primeiro vetor
    for (int i = 0; i < 20; i++)
    {
        if (vet1[i] == -1)
        {
            parou = i;
            break;
        }
        if (!checarRep(vet1[i], merge))
            merge[i] = vet1[i];
    }

    // segundo vetor
    for (int i = 0; i < 20; i++)
    {
        if (vet2[i] == -1)
        {
            break;
        }
        if (!checarRep(vet2[i], merge))
            merge[parou + i] = vet2[i];
    }

    ordenar(merge);
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
        if (vet1[i] != -1)
            printf("%d, ", vet1[i]);
    }
    printf("\n");

    // b)
    ordenar(vet1);
    ordenar(vet2);

    printf("vetor ordenado: ");
    for (int i = 0; i < 20; i++)
    {
        if (vet1[i] != -1)
            printf("%d, ", vet1[i]);
    }
    printf("\n");

    // c)
    int merge[40];     // feito em uma função; não deve ter valores repetidos
    int repetidos[40]; // repetições presentes em vet1 e vet2

    popular(merge);
    popular(repetidos);

    get_merge(vet1, vet2, merge);
}