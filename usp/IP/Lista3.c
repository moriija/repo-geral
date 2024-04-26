#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func1(int N) // quantidade de numero primo
{
    short int primos = 0;
    short int primobool = 1;

    int num;
    for(int i=0; i<N; i++){
        printf("Número: ");
        scanf("%d", &num);

        // checar se num é primo
        while (1)
        {
            if (num <= 1) break;
            for(short int j=2; j < num; j++)
            {
                if (j!=num && num % j == 0){
                    primobool = 0;
                    break;
                }
            }
            if (primobool){
                primos++;
            }
            break;
        }  
    }

    printf("Dos números digitados, %d são primos.\n", primos);
    return 1;
}

int func2(int num) // numero palíndromo
{
    if (num<=0) return 0;

    // numero de casas
    short int casas = 0;
    for(int i=num; i>0; i = i/10) casas++;

    int numinv = 0;
    int aux2 = num;
    int aux1=num;

    for(short int i=1; i<=casas; i++)
    {
        if (aux1<=0) break;

        // INVERTENDO O NUMERO
        aux2 = aux1; // 72
        aux1 = aux1/10; // 7
        numinv += (aux2 - aux1*10)*pow(10,casas-i);
    }
    //printf("numinv: %d\n", numinv);
    
    if ( numinv == num ){
        return 1;
    }

    return 0;
}

int func3(int par1, int par2)
{
    // Checando se parametros servem
    if (par1 <= 0) return 0;
    if (par2/10 > 0) return 0; // número de unico digito


    // casas do par1
    short int casas = 0;
    for(int i=par1; i>0; i = i/10) casas++;

    // criando array de algarismos
    int algas[casas];
    int digito;

    for (int i=0; par1>0; i++)
    {
        digito = par1%10;
        algas[i] = digito;
        par1 = par1/10;
    }

    // analisando numeros repetidos
    short int rep = 0;
    for (int i=0; i<casas; i++)
    {
        if (algas[i]==par2 && algas[i+1]==par2){
            rep++;
        }
    }

    return rep;
}


int main()
{
    // Função 1 - Escreva uma rotina que receba como parâmetro uma quantidade de números a serem inseridos e que depois peça para que sejam digitados cada um desses números inteiros e positivos.
    // Ao final, deve ser mostrado quantos desses números são primos.
    printf("\nFunção 1 - digite números a serem analisados como primos\n");
    int qntdPrimos = 3; // quantidade de primos a serem analisados
    func1(qntdPrimos);


    // Função 2 - Elabore uma função que retorne 1 caso o número inteiro passado como parâmetro é palíndromo. Caso o número passado como parâmetro seja 0, negativo ou não ser palíndromo, deve ser retornado 0.
    printf("\nFunção 2 - número a ser analisado como palíndromo: ");
    int num;
    scanf("%d", &num);

    if (func2(num)) printf("Número %d é palíndromo.\n", num);
    else printf("Número %d não é palíndromo.\n", num);

    // Função 3 - Apresente um rotina que dados os seguintes parâmetros: (1) um número inteiro positivo e maior que zero e (2) um número inteiro de um único dígito. Essa rotina deve mostrar quantas vezes uma repetição de 
    // dois números iguais ao segundo parâmetro aparece na sequência de dígitos do primeiro parâmetos.
    int par1;
    short int par2;
    printf("\nFunção 3 - vezes de repetição de número em sequência\n");
    printf("Parâmetro 1: ");
    scanf("%d", &par1);
    printf("Parâmetro 2 (único dígito): ");
    scanf("%hd", &par2);

    printf("repetições de duplas de %hd: %hd\n", par2, func3(par1, par2));


    return 0;    
}