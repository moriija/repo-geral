#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}node;

node* criarLista(int lin, int col, int matriz[lin][col])
{
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for(int l=0; l < lin; l++){
        for(int c=0; c<col; c++)
        {
            // malloc retorna ponteiro void*; (node*) faz typecast.
            temp = (node*)malloc(sizeof(node));
            temp->info = matriz[l][c];

            if(head == NULL){
                head = temp;
            }
            else{
                p = head;
                while(p->next != NULL){
                    p = p->next;
                }
                p->next = temp;
            }
        }
    }
    return head;
}

void printLista(node* p){
    while ( p != NULL ){
        printf("%d, ", p->info);
        p = p->next;
    }
    printf("\n");
    return;
}

int main(){

    // criando Matriz
    int matriz[5][5] = {
                {1,        2,        3,       4,     5},
                {6,        7,        8,       9,     10},
                {11,       12,      13,       14,     15},
                {16,       17,       18,      19,     20},
                {21,       22,       23,      24,     25}
                };

    node* head = criarLista(5, 5, matriz);
    
    printLista(head);
    
    // excluir lista da memoria
    while (head != NULL){
        node* temp = head;
        head = head->next;
        free(temp);
    }
    }