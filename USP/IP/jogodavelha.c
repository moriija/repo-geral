// EP 2
// Isabella Cremonezi Morija - 14579951


#include <stdio.h>

void printTab(char tab[3][3])
{
    printf("   A B C\n   -------");
    printf("\n1 |");
    for(int i=0; i<3; i++) printf("%c ", tab[0][i]);
    printf("\n2 |");
    for(int i=0; i<3; i++) printf("%c ", tab[1][i]);
    printf("\n3 |");
    for(int i=0; i<3; i++) printf("%c ", tab[2][i]);
    printf("\n");
}

void limparBuffer() // scanf ficou doido
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void jogar(char XO, char tab[3][3])
{
    int casa[2];
    char col;

    printf("Jogador %c: ", XO);
    scanf("%c%d", &col, &casa[1]);

    // Transformar no formato certo
    casa[1] = casa[1] - 1;
    // casa = {int linha, int coluna}
    char letras[3] = {'A', 'B', 'C'};

    for(int i = 0; i < 3; i++){
        if (col == letras[i]) casa[0] = i;
    }

    // Inserir no tabuleiro (se já não ocupado)
    if (tab[casa[1]][casa[0]] == ' '){
        tab[casa[1]][casa[0]] = XO;
        limparBuffer();
    }
    else {
        printf("! Casa já ocupada !\n");
        limparBuffer();
        jogar(XO, tab);
    }
}

short int checkEnd(char tab[3][3])
{
    // linhas e colunas
    for (int i = 0; i < 3; i++)
    {
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2] && tab[i][0] != ' ')
        {
            printf("VITORIA do Jogador %c.\n", tab[i][0]);
            return 1;
        }

        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i] && tab[0][i] != ' ')
        {
            printf("VITORIA do Jogador %c.\n", tab[0][i]);
            return 1;
        }
    }

    // diagonais
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] != ' '){
        printf("VITORIA do Jogador %c.\n", tab[0][0]);
        return 1;
    }

    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] != ' '){
        printf("VITORIA do Jogador %c.\n", tab[0][2]);
        return 1;
    }

    
    // não é empate
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tab[i][j] == ' ')
                return 0;
        }
    }

    printf("EMPATE.\n");
    return 1;
}

int main()
{
    printf("Jogo da Velha\nDigite a casa (ex: A2).\n");

    char tab[3][3] = 
    //    A    B    C
        {{' ', ' ', ' '}, // 1
         {' ', ' ', ' '}, // 2
         {' ', ' ', ' '}}; // 3

    printTab(tab);

    while (1)
    {
        jogar('X', tab);
        printTab(tab);
        if (checkEnd(tab) == 1 ) break; 
        
        jogar('O', tab);
        printTab(tab);
        if (checkEnd(tab) == 1 ) break;
    }

    return 0;
}