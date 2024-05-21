#include <stdio.h>

int main() {
    int dia, mes, ano;
    printf("Digite uma data (DD/MM/AAAA):\n");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (ano >=0 && ano <= 9999) {

        if (mes >= 1 && mes <= 12) {

            if (
                ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))

                || ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))

                || ((dia >= 1 && dia <= 28) && (mes == 2))
            
                // ano bissexto
                || (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))))
            {
                printf("Data é valida.\n");

            } else printf("Dia não é valido.\n");

        } else printf("Mes não é valido.\n");

    } else printf("Ano não é valido.\n");

}