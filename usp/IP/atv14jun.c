// Isabella Cremonezi Morija - 14579951

#include <stdio.h>
#include <stdlib.h>

struct matriz
{
    int matriz[10][10];
    int qtdLin;
    int qtdCol;
};

// PROTÓTIPOS DAS FUNÇÕES
void inserirEl(struct matriz* mat);
void maiorEmLinha(struct matriz* mat);
void maiorEmCol(struct matriz* mat);
void menorEmLinha(struct matriz* mat);
void menorEmCol(struct matriz* mat);
void imprimirMatriz(struct matriz* mat);
void maiorElemento(struct matriz* mat);
void menorElemento(struct matriz* mat);
void somaLinhas(struct matriz* mat);
void somaColunas(struct matriz* mat);
void linhaMaiorSoma(struct matriz* mat);
void colunaMaiorSoma(struct matriz* mat);
void multiplicarMatrizes(struct matriz* matA, struct matriz* matB, struct matriz* matC);

int main()
{
    // 1. Definição da matriz
    printf("Digite quantas linhas e colunas (máximo 10).\n");

    int lin = 11;
    int col = 11;
    while( lin > 10 ){
        printf("Linhas: ");
        scanf("%d", &lin);
    }
    while( col > 10 ){
        printf("Colunas: ");
        scanf("%d", &col);
    }

    struct matriz* mat = (struct matriz*)malloc(sizeof(struct matriz));
    mat->qtdCol = col;
    mat->qtdLin = lin;


    // 2. Uma rotina para serem inseridos elementos inteiros nessa matriz
    inserirEl(mat);
    imprimirMatriz(mat);


    // 3. Rotinas para:

    // mostrar o maior elemento de cada linha
    maiorEmLinha(mat);
    // mostrar o maior elemento de cada coluna
    maiorEmCol(mat);
    // mostrar o menor elemento de cada linha
    menorEmLinha(mat);
    // mostrar o maior elemento de cada coluna
    menorEmCol(mat);


    // 4. rotinas para 

    // mostrar em quais linha e coluna está o maior elemento da matriz
    maiorElemento(mat);
    // mostrar em quais linha e coluna está o menor elemento da matriz
    menorElemento(mat);
    // mostrar a soma dos valores de cada linha
    somaLinhas(mat);
    // mostrar a soma dos valores de cada coluna
    somaColunas(mat);
    // mostrar qual linha possui a maior soma dos valores de cada linha
    linhaMaiorSoma(mat);
    // mostrar qual colunapossui a maior soma dos valores de cada coluna
    colunaMaiorSoma(mat);


    // DESAFIO: multiplicação de matrizes
    printf("\n");
    printf("=== MULTIPLICAÇÃO DE MATRIZES ===");
    printf("\nDigite quantas linhas e colunas para a matriz B.\n");
    int linB, colB;
    printf("Linhas: ");
    scanf("%d", &linB);
    printf("Colunas: ");
    scanf("%d", &colB);

    struct matriz* matB = (struct matriz*)malloc(sizeof(struct matriz));
    matB->qtdCol = colB;
    matB->qtdLin = linB;

    inserirEl(matB);
    imprimirMatriz(matB);

    // matC será a matriz resultante
    struct matriz* matC = (struct matriz*)malloc(sizeof(struct matriz));
    multiplicarMatrizes(mat, matB, matC);



    free(mat);
    free(matB);
    free(matC);

}


void inserirEl(struct matriz* mat)
{
    printf("\n");
    printf("Insira os elementos\n");

    for(int i=0; i < (mat->qtdLin); i++)
    {
        printf("== Linha %d ==\n", i+1);
        for(int j=0; j < (mat->qtdCol); j++)
        {
            printf("[%d][%d]: ", i+1, j+1);
            scanf("%d", &(mat->matriz[i][j]));
        }
    }
}

void maiorEmLinha(struct matriz* mat)
{
    printf("\n");
    for(int i = 0; i < (mat->qtdLin); i++)
    {
        int maior = mat->matriz[i][0];
        for(int j = 0; j < (mat->qtdCol); j++)
        {
            if (mat->matriz[i][j] > maior) maior = mat->matriz[i][j];
        }
        
        printf("Maior da linha %d: %d\n", i+1, maior);
    }
}

void maiorEmCol(struct matriz* mat)
{
    printf("\n");
    for(int j = 0; j < (mat->qtdCol); j++)
    {
        int maior = mat->matriz[0][j];
        for(int i = 0; i < (mat->qtdLin); i++)
        {
            if (mat->matriz[i][j] > maior) maior = mat->matriz[i][j];
        }
        
        printf("Maior da coluna %d: %d\n", j+1, maior);
    }
}

void menorEmLinha(struct matriz* mat)
{
    printf("\n");
    for(int i = 0; i < (mat->qtdLin); i++)
    {
        int menor = mat->matriz[i][0];
        for(int j = 0; j < (mat->qtdCol); j++)
        {
            if (mat->matriz[i][j] < menor) menor = mat->matriz[i][j];
        }
        
        printf("Menor da linha %d: %d\n", i+1, menor);
    }
}

void menorEmCol(struct matriz* mat)
{
    printf("\n");
    for(int j = 0; j < (mat->qtdCol); j++)
    {
        int menor = mat->matriz[0][j];
        for(int i = 0; i < (mat->qtdLin); i++)
        {
            if (mat->matriz[i][j] < menor) menor = mat->matriz[i][j];
        }
        
        printf("Menor da coluna %d: %d\n", j+1, menor);
    }
}

void imprimirMatriz(struct matriz* mat)
{
    printf("\n");
    for (int i = 0; i < mat->qtdLin; i++)
    {
        for (int j = 0; j < mat->qtdCol; j++)
        {
            printf("%d ", mat->matriz[i][j]);
        }
        printf("\n");
    }
}

void maiorElemento(struct matriz* mat)
{
    printf("\n");
    int maior = mat->matriz[0][0];
    int lin = 0, col = 0;

    for(int i = 0; i < mat->qtdLin; i++)
    {
        for(int j = 0; j < mat->qtdCol; j++)
        {
            if (mat->matriz[i][j] > maior)
            {
                maior = mat->matriz[i][j];
                lin = i;
                col = j;
            }
        }
    }
    
    printf("Maior elemento: %d está na linha %d, coluna %d\n", maior, lin+1, col+1);
}

void menorElemento(struct matriz* mat)
{
    printf("\n");
    int menor = mat->matriz[0][0];
    int lin = 0, col = 0;

    for(int i = 0; i < mat->qtdLin; i++)
    {
        for(int j = 0; j < mat->qtdCol; j++)
        {
            if (mat->matriz[i][j] < menor)
            {
                menor = mat->matriz[i][j];
                lin = i;
                col = j;
            }
        }
    }
    
    printf("Menor elemento: %d está na linha %d, coluna %d\n", menor, lin+1, col+1);
}

void somaLinhas(struct matriz* mat)
{
    printf("\n");
    for (int i = 0; i < mat->qtdLin; i++)
    {
        int soma = 0;
        for (int j = 0; j < mat->qtdCol; j++)
        {
            soma += mat->matriz[i][j];
        }
        printf("Soma dos valores da linha %d: %d\n", i+1, soma);
    }
}

void somaColunas(struct matriz* mat)
{
    printf("\n");
    for (int j = 0; j < mat->qtdCol; j++)
    {
        int soma = 0;
        for (int i = 0; i < mat->qtdLin; i++)
        {
            soma += mat->matriz[i][j];
        }
        printf("Soma dos valores da coluna %d: %d\n", j+1, soma);
    }
}

void linhaMaiorSoma(struct matriz* mat)
{
    printf("\n");
    int maiorSoma = -1;
    int linha = 0;
    for (int i = 0; i < mat->qtdLin; i++)
    {
        int soma = 0;
        for (int j = 0; j < mat->qtdCol; j++)
        {
            soma += mat->matriz[i][j];
        }
        if (soma > maiorSoma)
        {
            maiorSoma = soma;
            linha = i;
        }
    }
    printf("Linha com maior soma dos valores: linha %d com soma %d\n", linha+1, maiorSoma);
}

void colunaMaiorSoma(struct matriz* mat)
{
    printf("\n");
    int maiorSoma = -1;
    int coluna = 0;
    for (int j = 0; j < mat->qtdCol; j++)
    {
        int soma = 0;
        for (int i = 0; i < mat->qtdLin; i++)
        {
            soma += mat->matriz[i][j];
        }
        if (soma > maiorSoma)
        {
            maiorSoma = soma;
            coluna = j;
        }
    }
    printf("Coluna com maior soma dos valores: coluna %d com soma %d\n", coluna+1, maiorSoma);
}

void multiplicarMatrizes(struct matriz* matA, struct matriz* matB, struct matriz* matC)
{
    printf("\n");
    if (matA->qtdCol != matB->qtdLin)
    {
        printf("Não é possível multiplicar as matrizes: o número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return;
    }

    matC->qtdLin = matA->qtdLin;
    matC->qtdCol = matB->qtdCol;

    for (int i = 0; i < matC->qtdLin; i++)
    {
        for (int j = 0; j < matC->qtdCol; j++)
        {
            matC->matriz[i][j] = 0;
            for (int k = 0; k < matA->qtdCol; k++)
            {
                matC->matriz[i][j] += matA->matriz[i][k] * matB->matriz[k][j];
            }
        }
    }

    printf("Resultado da multiplicação das matrizes (matriz C):\n");
    imprimirMatriz(matC);
}