// Isabella Cremonezi Morija - Turma 04 -  n° 14579951
// Clara Pires Campardo - Turma 04 - n° 15446433

#include <stdio.h>

int imprimir(int vetor[], int size);
int popular(int vetor[], int n, int size);  // popula um vetor, com um inteiro n, de tamanho "size" elementos
int ordenar(int vetor[], int size);         // Bubble Sort
int get_merge(int vet1[], int vet2[], int merge[], int repetidos[]);    // insere elementos de vet1 e vet2 (se já não existe igual) no terceiro vetor "merge".
int checarRep(int x, int vet[], int repetidos[]);   // checa presença do numero x no vetor (merge); se já presente, insere no quarto vetor "repetidos".
int contagemRep(int repetidos[]);   // expoe todos repetidos + sua contagem de presença em vet1 e vet2.


int main()
{
    // a)
    int vet1[20];
    int vet2[20];
    popular(vet1, -1, 20);
    popular(vet2, -1, 20);

    printf("EP-1 -> insira numeros naturais; -1 para finalizar.\n");

    int temp;

    printf("Insira elementos para 1o vetor\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &temp);
        if (temp < 0)
            break;

        vet1[i] = temp;
    }

    printf("Insira elementos para 2o vetor\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &temp);

        if (temp < 0)
            break;

        vet2[i] = temp;
    }

    printf("vetor1 antes: ");
    imprimir(vet1, 20);
    printf("vetor2 antes: ");
    imprimir(vet2, 20);
    printf("\n");

    // b)
    ordenar(vet1, 20);
    ordenar(vet2, 20);

    printf("vetor1 ordenado: ");
    imprimir(vet1, 20);
    printf("vetor2 ordenado: ");
    imprimir(vet2, 20);
    printf("\n");

    // c)
    int merge[40];     // feito em uma função; não deve ter valores repetidos
    int repetidos[40]; // repetições presentes em vet1 e vet2

    popular(merge, -1, 40);
    popular(repetidos, -1, 40);

    get_merge(vet1, vet2, merge, repetidos);

    printf("vetor merge: ");
    imprimir(merge, 40);

    printf("\nnumeros repetidos:\n");
    contagemRep(repetidos); // imprime elemento específico + quantas vezes apareceu

    return 0;
}

int imprimir(int vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (vetor[i] != -1)
        {
            if (i == 0)
                printf("%d", vetor[i]);
            else
                printf(", %d", vetor[i]);
        }
    }
    printf(".\n");
    return 1;
}

int popular(int vetor[], int n, int size)
{
    for (int i = 0; i < size; i++)
    {
        vetor[i] = n;
    }

    return 1;
}

int ordenar(int vetor[], int size)
{
    int temp;
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1 || vetor[i] == -1)
                break;

            if (vetor[i] > vetor[i + 1] && vetor[i] != -1 && vetor[i + 1] != -1)
            {
                temp = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = temp;
            }
        }
    }
    return 1;
}

int checarRep(int x, int vet[], int repetidos[])
{
    for (int i = 0; i < 40; i++)
    {
        if (x == vet[i])
        {
            // empurrar pra repetidos[]
            int posiRep = 0;
            for (int j = 0; j < 40; j++)
            {
                if (repetidos[j] == -1)
                {
                    posiRep = j;
                    break;
                }
            }

            repetidos[posiRep] = x;
            return (1);
        }
    }
    return 0;
}

int get_merge(int vet1[], int vet2[], int merge[], int repetidos[])
{
    int merge_idx=0;

    // primeiro vetor
    for (int i = 0; i < 20; i++)
    {

        if (vet1[i] == -1)
        {
            break;
        }
        if (checarRep(vet1[i], merge, repetidos) == 0)
        {
            merge[merge_idx] = vet1[i];
            merge_idx++;
        }
    }
    // segundo vetor
    for (int i = 0; i < 20; i++)
    {
        if (vet2[i] == -1)
        {
            break;
        }
        if (checarRep(vet2[i], merge, repetidos) == 0)
        {
            merge[merge_idx] = vet2[i];
            merge_idx++;
        }
    }

    ordenar(merge, 40);
    ordenar(repetidos, 40);
    return 1;
}

int contagemRep(int repetidos[])
{
    int ocorrencia[40]; // cada elemento (se não houver um igual) somará +1
    int visitado[40]; // guarda elementos já visitados, para nao ter soma do mesmo numero se esse aparecer 2+ vezes em repetidos.
    popular(ocorrencia, 0, 40);
    popular(visitado, -1, 40);

    int index;

    for (int i = 0; i < 40; i++)
    {
        if (repetidos[i] == -1)
        {
            break;
        }

        // a partir de index, saberemos quantaz vezes repetidos[i] aparece
        index = i;

        // procurar número de repetidos[] em visitado[]
        for (int j = 0; j < 40; j++)
        {
            if (repetidos[i] == visitado[j])
            {
                index = j;
                break;
            }
        }

        visitado[index] = repetidos[index];

        ocorrencia[index]++;
    }

    for (int i = 0; i < 40; i++)
    {
        if (ocorrencia[i] >= 1)
        {
            printf("%d apareceu %d vezes.\n", visitado[i], ocorrencia[i] + 1);
        }
    }

    return 1;
}