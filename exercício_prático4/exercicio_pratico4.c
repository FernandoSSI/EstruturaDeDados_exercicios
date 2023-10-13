#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //variaveis relacionadas ao problema
    int valor;
    struct no * prox;
}NO;

NO *inicio = NULL;
int tam = 0;


void add(int valor, int pos){
    
    if(pos >= 0  && pos <= tam){
    
        //cria um novo no na memoria e seta seus valores
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
    
        if(inicio == NULL){ //se a lista esta vazia
            inicio = novo; 
        }else if(pos == 0){
            //adicionar no inicio
            novo->prox = inicio;
            inicio = novo;
        }else{
            //adicionar no fim ou meio
            NO *aux = inicio;
            for(int i=0; i< pos-1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo; 
        }
        tam++;
    }else{
        printf("Posicao invalida! O valor %d nao foi inserido!\n", valor);
    }
}

int len(){
    return tam;
}


void remover(int pos){
    
    if(pos >= 0 && pos < tam){
        
        if(inicio == NULL){
            printf("vazia! :/\n");
        }else if (pos == 0){ //inicio da lista!
            NO *lixo = inicio;
            inicio = inicio->prox; 
            free(lixo);
            tam--;
        
        }else{
            NO * lixo = NULL;
            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                aux = aux -> prox;
            }
            lixo = aux -> prox;
            aux -> prox = aux -> prox -> prox;
            free(lixo);
        
            tam --;
            
        }
    } else {
        printf("Posicao invalida para remoção! A posição %d não existe\n", pos);
    }
    
}

void imprimir(){
    NO *aux = inicio;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
  add(14, 0);
  add(5, 0);
  add(7, 2);
  add(10, 2);
  add(12, 0);
  add(2, 3);
  remover(0);
  //2 - crie aqui 2 chamadas para remover (no meio e no fim)
  //e depois chame a funcao imprimir
  remover(2);
  remover(3);
  printf("o tamanho da lista eh: %d\n", len());

  return 0;
}