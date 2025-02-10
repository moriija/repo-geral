#include <stdio.h>
int main(){

    // Entrar com um número inteiro positivo e menor que 10.000 
    int num = -1;

    while(num<0 || num>10000){
        printf("Número: ");
        scanf("%d", &num);
    }

    // informar o valor de sua casa na unidade, na dezena, na centena e no milhar
    int aux;

    aux = num%10;
    printf("unidade: %d\n", aux);

    num = (num - aux)/10;
    aux = num%10;
    printf("dezena: %d\n", aux);

    num = (num - aux)/10;
    aux = num%10;
    printf("centena: %d\n", aux);

    num = (num - aux)/10;
    aux = num%10;
    printf("milhar: %d\n", aux);

}