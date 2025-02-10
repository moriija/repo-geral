// Isabella Cremonezi Morija - 14579951

#include <stdio.h>
#include <string.h>

// Função para comparar duas strings caracter a caracter
int compareStrings(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    char str1[100], str2[100];

    // Lendo as duas strings
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remover o caractere de nova linha '\n' se presente
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Comparar as strings
    int result = compareStrings(str1, str2);

    // Exibir as strings em ordem alfabética
    if (result < 0) {
        printf("Strings em ordem alfabética:\n%s\n%s\n", str1, str2);
    } else if (result > 0) {
        printf("Strings em ordem alfabética:\n%s\n%s\n", str2, str1);
    } else {
        printf("As strings são iguais:\n%s\n%s\n", str1, str2);
    }

    return 0;
}