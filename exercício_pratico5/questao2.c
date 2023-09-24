#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //variaveis relacionadas ao problema
    char * nome;
    char * cantor;
    float tempo;
    struct no * prox; 
    struct no * ant; 
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void add_na_playlist(char * nome, char * cantor, float tempo){
    NO * novo = malloc(sizeof(NO));
    novo->nome = nome;
    novo->cantor = cantor;
    novo->tempo = tempo;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    } else{
        novo->prox = inicio;
        inicio ->ant = novo;
        inicio=novo;
        fim->prox = inicio;
        inicio->ant = fim;
    }
    tam++;
}

void remover_na_playlist(char*nome){
    if(inicio){
        NO*aux = inicio;
        if(nome == inicio-> nome){
            inicio->ant-> prox = inicio->prox;
            inicio->prox->ant = inicio-> ant;
            inicio=inicio->prox;
            free(aux);
        } else if(nome == fim-> nome){
            fim->ant-> prox = fim->prox;
            fim->prox->ant = fim-> ant;
            fim=fim->ant;
            free(aux);
        } else{
            while(nome != aux->nome){
                aux = aux->prox;
            }
            aux -> prox->ant= aux->ant;
            aux ->ant-> prox = aux->prox;
            free(aux);
        }
        tam--;
    } else{
        printf("A lista está vazia");
    }
}



void play(int num_vezes){
    NO *aux = inicio;
    int vezes = num_vezes*tam;
    
    for(int i=0; i<vezes; i++){
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}

int main(){
    add_na_playlist("mulher bandida", "manoel gomes", 3.5);
    add_na_playlist("chico se tu me quiseres", "luiza sonza", 2.5);
    add_na_playlist("minhas marias", "zé felipe", 1.2);
    add_na_playlist("caneta azul", "manoel gomes", 4);
    remover_na_playlist("chico se tu me quiseres");
    play(3);
    
  return 0;
}