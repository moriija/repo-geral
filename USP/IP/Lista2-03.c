#include <stdio.h>
int main(){
    
    int N;
    printf("Digite quantos números serão analisados: ");
    scanf("%d", &N);

    int num;
    int div4 = 0;
    int div7 = 0;
    int div13 = 0;

    for(int i=0; i<N; i++)
    {
        printf("Número: ");
        scanf("%d", &num);

        if(num%4 == 0){
            div4++;
        }
        if(num%7 == 0){
            div7++;
        }
        if(num%13 == 0){
            div13++;
        }
    }
    printf("\nDivisíveis por \n4: %d números.\n7: %d números.\n13: %d números.\n", div4, div7, div13);
}