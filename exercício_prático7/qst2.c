// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct fila{
    int ficha;
    struct fila * prox;
    struct fila * ant;
}fila;
fila * inicio = NULL;
fila * fim = NULL;

void add(int ficha){
    fila * novo = malloc (sizeof(fila));
    novo->ficha = ficha;
    novo -> prox = NULL;
    novo -> ant = NULL;
    if (inicio == NULL){
        inicio = novo;
        fim = novo;
    }else if(novo->ficha < inicio->ficha){
        novo-> prox = inicio;
        inicio -> ant = novo;
        inicio = novo;
        
    }else if(novo->ficha >= fim->ficha){
        fim -> prox = novo;
        novo->ant = fim;
        fim = novo;
    }else if (novo->ficha >= inicio->ficha && novo->ficha < fim->ficha){
        fila *aux = inicio;
        while(novo->ficha >= aux->ficha){
            aux= aux->prox;
        }
        aux = aux->ant;
        aux -> prox->ant = novo;
        novo->prox = aux -> prox;
        novo -> ant = aux;
        aux->prox = novo;
        
    }
    
}
void remover(){
    fila * aux = inicio;
    inicio = inicio->prox;
    free(aux);
    
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
   remover();
   imprimir();
    return 0;
}