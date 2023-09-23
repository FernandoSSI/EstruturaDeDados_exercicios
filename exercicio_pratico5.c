#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //variaveis relacionadas ao problema
    char * nome;
    int numero;
    int senha;
    float saldo;
    struct no * prox; 
    struct no * ant; 
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


void cadastrarConta(char * nome, int numero, int senha, float saldo){
    
        //cria um novo no na memoria e seta seus valores
        NO *novo = malloc(sizeof(NO));
        novo->nome = nome;
        novo -> numero = numero;
        novo -> senha = senha;
        novo -> saldo = saldo;
        novo->prox = NULL;
        novo->ant = NULL;
    
        if(inicio == NULL){ //se a lista esta vazia
            inicio = novo; //constante :D
            fim = novo;
        } else{
           NO *aux = inicio;
           
           if(novo->saldo > aux-> saldo){
               aux->ant = novo;
               novo -> prox = aux;
               novo -> ant = NULL;
               inicio = novo;
           } else{
               while(novo->saldo < aux-> saldo){
                   if(novo->saldo < aux-> saldo && aux->ant==NULL){
                       novo -> prox = aux-> prox;
                       novo -> ant = aux;
                       aux->prox->ant= novo;
                       aux -> prox = novo;
                       aux = novo->prox;
                  }  else if(novo->saldo < aux-> saldo && novo->prox !=NULL) {
                       novo ->ant->prox = aux;
                       novo->prox = aux->prox;
                       aux->ant = novo->ant;
                       novo-> ant = aux;
                       aux->prox = novo;
                       if(novo -> prox !=NULL){
                            aux = novo ->prox;
                       }
                   } else {
                       break;
                   }
               }
           }
           
        
        }
    
}

  



/*
void remover(int pos){
    
    if(pos >= 0 && pos < tam){
        
        if(inicio == NULL){
            printf("vazia! :/\n");
        }else if (pos == 0){ 
            //inicio da lista - constante :D
            NO *lixo = inicio;
            inicio = inicio->prox; 
            inicio->ant = NULL;
            free(lixo);
            tam--;
        
        }else if(pos == tam - 1){//fim - constante! :D

            NO *lixo = fim;
            fim = fim->ant;
            fim->prox = NULL;
            free(lixo);
            tam--;            


        }else{
            // meio! Linear :/
            NO *lixo = inicio;
            for(int i=0; i< pos; i++){
                lixo = lixo->prox;
            }

            lixo->ant->prox = lixo->prox;
            lixo->prox->ant = lixo->ant;
            free(lixo);
            tam--;
        }
        
        
    }
    
}
*/

void visualizar(){
    printf("Imprimindo a lista...\n");
    NO *aux = inicio;
    while(aux != NULL){
        printf("Nome: %s - Saldo:%.2f\n", aux->nome, aux->saldo);
        aux = aux->prox;
    }
}

int main(){
  
    cadastrarConta("Fernando", 1, 1234, 3000.5);
    cadastrarConta("Milena", 2, 2345, 4500.5);
    cadastrarConta("João", 3, 2005, 2000.7);
    cadastrarConta("salazar", 4, 2209, 3000);
   
    visualizar();

  return 0;
}