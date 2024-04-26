#include <stdio.h>
#include <math.h>

int func1(short int N) // quantidade de numero primo
{
    short int primos = 0;
    short int primobool = 1;

    short int num;
    for(int i=0; i<N; i++){
        printf("Número: ");
        scanf("%hd", &num);

        // checar se num é primo
        while (1)
        {
            if (num <= 1) break;
            for(short int j=2; j < sqrt(num); j++)
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


    // analisando numeros repetidos
    short int rep = 0;
    for (int i=0; i<casas; i++)
    {
        if ( par1/pow(10,i)==par2 && par1/pow(10,i+1)==par2 ){
            rep++;
        }
    }

    return rep;
}


int main()
{
    // Função 1 - Escreva uma rotina que receba como parâmetro uma quantidade de números a serem inseridos e que depois peça para que sejam digitados cada um desses números inteiros e positivos.
    // Ao final, deve ser mostrado quantos desses números são primos.
    //    printf("\nFunção 1 - digite números a serem analisados como primos\n");
    //    int qntdPrimos = 3;
    //    func1(qntdPrimos);


    // Função 2 - Elabore uma função que retorne 1 caso o número inteiro passado como parâmetro é palíndromo. Caso o número passado como parâmetro seja 0, negativo ou não ser palíndromo, deve ser retornado 0.
    //    printf("\nFunção 2 - número a ser analisado como palíndromo: ");
    //    int num;
    //    scanf("%d", &num);

    //    if (func2(num)) printf("Número %d é palíndromo.\n", num);
    //    else printf("Número %d não é palíndromo.\n", num);


    printf("rep: %hd\n", func3(344, 4));


    return 0;    
}