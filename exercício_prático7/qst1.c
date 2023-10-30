// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct fila{
    int ficha;
    struct fila * prox;
}fila;
fila * inicio = NULL;
fila * fim = NULL;

void add(int ficha){
    fila * novo = malloc (sizeof(fila));
    novo->ficha = ficha;
    novo -> prox = NULL;
    
    if (inicio == NULL){
        inicio = novo;
        fim = novo;
    }else{
        fim -> prox = novo;
        fim = novo;
    }
}

void imprimir(){
    printf("imprimindo...\n");
    fila *aux = inicio;
    while(aux != NULL){
        printf("%d\n", aux->ficha);
        aux = aux->prox;
    }
}



int main() {
   add(16);
   add(2);
   add(58);
   imprimir();
    return 0;
}