// Isabella Cremonezi Morija - 14579951

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
} node;

void printLista(node* head){
    printf("Lista: ");
    node* p = head;
    while( p != NULL ){
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

void freeLista(node* head){
    node* tmp;
    while( head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

node* inserirInicio(int el, node* head){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->info = el;
    tmp->next = head;

    return tmp;
}

void inserirFim(int el, node* head){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->info = el;

    node* p = head;
    while( p->next != NULL ){
        p = p->next;
    }
    p->next = tmp;
}

node* excluirInicio(node* head){
    node* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

void excluirFim(node* head){
    node* p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

short int procurarEl(int el, node* head){
    node* p = head;
    while(p != NULL){
        if ( p->info == el ) return 1;
        p = p->next;
    }
    return 0;
}

void ordenarLista(node* head){
    // definir tamanho da lista
    int len = 0;
    node* p = head;
    while( p != NULL ){
        len++;
        p = p->next;
    }

    // Bubble sort
    for(int i=0; i<len-1; i++){
        p = head;
        for(int j=0; j<len-1-i; j++){
            if( p->info > p->next->info ){
                int tmp = p->info;
                p->info = p->next->info;
                p->next->info = tmp;
            }
            p = p->next;
        }
    }
}

node* inserirOrdenado(int el, node* head){
    node* tmp = (node*)malloc(sizeof(node*));
    tmp->info = el;
    tmp->next = NULL;

    // el será primeiro
    if( el < (head->info) ){
        tmp->next = head;
        return tmp; // vira nova head
    }

    node* p = head;
    while(p->next != NULL){
        if( el < (p->next->info) ){
            tmp->next = p->next;
            p->next = tmp;
            return head;
        }
        p = p->next;
    }

    // el será ultimo da lista
    p->next = tmp;
    return head;
}

node* excluirEl(int el, node* head){
    node* p = head;
    if( head->info == el ){
        head = head->next;
        free(p);
        return head;
    }
    
    while( p->next != NULL ){
        if( p->next->info == el )
        {
            if( p->next->next != NULL ){
                node* tmp = p->next->next;
                free(p->next);
                p->next = tmp;
                return head;
            }
            else // p->next é ultimo
            {
                free(p->next);
                p->next = NULL;
                return head;
            }  
        }
        p = p->next;
    }

    printf("%d não foi encontrado.\n", el);
    return head;
}

int main()
{
    // a) criar lista
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    // só pra ter alguma coisa de lista
    head->info = 0; 
    head->next = (node*)malloc(sizeof(node));
    head->next->info = 3;
    head->next->next = (node*)malloc(sizeof(node));
    head->next->next->info = 2;
    head->next->next->next = NULL;
    printLista(head);

    // b) Inserir um elemento no início da lista
    printf("Insira um elemento para o início da lista\n");
    int x;
    scanf("%d", &x);
    head = inserirInicio(x, head);

    // c) Inserir um elemento no fim da lista
    printf("Insira um elemento para o fim da lista\n");
    scanf("%d", &x);
    inserirFim(x, head);
    printLista(head);

    // d) Excluir um elemento no início da lista
    printf("\nExcluindo elemento no inicio da lista...\n");
    head = excluirInicio(head);
    printLista(head);

    // e) Excluir um elemento do fim da lista
    printf("Excluindo elemento no fim da lista...\n");
    excluirFim(head);
    printLista(head);

    // f) Procure por um elemento (valor do inteiro) na lista - retorne 1 se achou e 0 caso contrário
    printf("\nProcurar elemento na lista: ");
    scanf("%d", &x);
    if ( procurarEl(x, head) == 1 ) printf("%d é presente.\n", x);
    else printf("%d não é presente.\n", x);


    // bonus
    // g) ordenar os elementos (de forma crescente) da lista
    printf("\nOrdenando de forma crescente...\n");
    ordenarLista(head);
    printLista(head);

    // h) inserir um elemento no meio da lista de forma a mantê-la ordenada (podem haver repetições de valores na lista)
    printf("\nInserir elemento na lista ordenada: ");
    scanf("%d", &x);
    head = inserirOrdenado(x, head);
    printLista(head);

    // g) Excluir um elemento do meio da lista - nesse caso considere que não ocorrem repetições de valores dos elementos da lista
    printf("\nExcluir elemento da lista: ");
    scanf("%d", &x);
    head = excluirEl(x, head);
    printLista(head);

   freeLista(head);
}