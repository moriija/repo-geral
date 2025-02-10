#include <stdio.h>
int main(){

    // qual o maior entrado
    // qual o menor entrado
    // a soma
    // a média

    int N;
    printf("Digite quantos números serão analisados: ");
    scanf("%d", &N);

    int num, maior, menor;
    int soma = 0;
    float media = 0;

    for(int i=0; i<N; i++)
    {
        printf("Número: ");
        scanf("%d", &num);
        if (num < 0){
            break;
        }
        if (i==0){
            maior = num;
            menor = num;
        }

        if (num > maior){
            maior = num;
        }
        if (num < menor){
            menor = num;
        }
        soma = soma + num;
    }

    media = soma;
    media = media / N;
    printf("maior: %d, menor: %d, soma: %d, média: %f\n", maior, menor, soma, media);
}