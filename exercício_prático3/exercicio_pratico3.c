
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //variaveis relacionadas ao problema
    char *tipo_animal;
    int idade;
    float peso;
    struct no * prox;
}NO;

NO *inicio = NULL;

void add_inicio(char *tipo_animal, int idade, float peso){
    
    //cria um novo no na memoria e seta seus valores
    NO *novo = malloc(sizeof(NO));
    novo->tipo_animal = tipo_animal;
    novo->idade = idade;
    novo->peso = peso;
    novo->prox = NULL;
    
    if(inicio == NULL){ //se a lista esta vazia
        inicio = novo; 
    }else{
        //senao eh sempre adicionado no inicio
        novo->prox = inicio;
        inicio = novo;
    }
}

//1 - faca uma funcao add_fim que caso a lista 
//nao esteja vazia sempre adiciona no final da lista
//atencao vc nao deve adicionar novos ponteiros globais
//DICA: a resposta esta no livro! :D

void add_fim(char *tipo_animal, int idade, float peso){
    NO *novo = malloc(sizeof(NO));
    novo->tipo_animal = tipo_animal;
    novo->idade = idade;
    novo->peso = peso;
    novo->prox = NULL;

    NO * aux = inicio;
    while(aux -> prox != NULL ){
        aux = aux->prox;
        if (aux -> prox == NULL){
            aux->prox = novo;
            novo ->prox = NULL;
        }
    }
}


void imprimir(){
    NO *aux = inicio;
    while(aux != NULL){
        printf("%s\n", aux->tipo_animal);
        aux = aux->prox;
    }
}

int main()
{
  add_inicio("cachorro", 6, 7);
  add_inicio("gatinho", 3, 5);
  add_inicio("girafa", 2, 120);
  add_fim("mamute", 8, 800);
  add_fim("baleia", 7, 3000);
  add_fim("dinossauro", 8, 5000);
  add_fim("papagaio", 7, 3);
  add_fim("minhoca", 1, 1);
  imprimir();
  
  //2 - crie aqui 5 chamadas para add_fim
  //e depois chame a funcao imprimir
  return 0;
}