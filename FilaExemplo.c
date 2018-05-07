#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no* prox;
} nod;

nod *criarNo(int conteudo) {

    nod *p;
    p=(nod *) malloc (sizeof (nod));
    p -> num = conteudo;
    p -> prox = NULL;

    return p;
}


void inserir_fila( nod ** inicio, nod ** fim, int conteudo) {

    nod *p;
    p = criarNo(conteudo);

    if (*inicio ==NULL) {
        (*inicio = *fim = p);
    } else {
        (*fim) -> prox = p;
        (*fim) = p;
    }
}

void inserir_fila_no( nod ** inicio, nod ** fim, nod *p) {

    if (*inicio ==NULL) {
        (*inicio = *fim = p);
    } else {
        (*fim) -> prox = p;
        (*fim) = p;
    }
}

nod * remover_fila(nod **inicio) {
    nod* p = NULL;
    if ((*inicio)!=NULL) {
        p = *inicio;
        (*inicio) = (*inicio) -> prox;
        p ->prox = NULL ;
    }

    return p;
}

void imprimir(nod **inicio, nod **fim){
    nod *p = NULL, *temp;
    while(p != inicio){
        temp = remover_fila(&(*inicio);
        if(p == NULL)
            p = temp;
        printf("%d - ", temp->num);
        inserir_fila_no(&(*inicio), &(*fim), temp);

    }
}

int main(){
    nod *inicio, *fim, *temp;
    inicio = fim = NULL;
    inserir_fila(&inicio, &fim, 2);
    inserir_fila(&inicio, &fim, 5);

    temp = remover_fila(&inicio);
    printf("Valor e: %d", temp->num);
    return 0;
}
