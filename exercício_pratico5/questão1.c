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
            }else if(novo ->saldo < fim-> saldo){
                fim -> prox = novo;
                novo ->prox = NULL;
                novo->ant = fim;
                fim = novo;
           }else{
                while(novo->saldo < aux-> saldo){
                    if(aux == inicio){
                        novo -> prox = aux-> prox;
                        novo -> ant = aux;
                        aux->prox->ant= novo;
                        aux -> prox = novo;
                        aux = novo->prox;
                    } else{
                        if(novo ->prox ->saldo > novo->saldo){
                            novo ->ant->prox = aux;
                            novo->prox = aux->prox;
                            aux ->prox ->ant = novo;
                            aux->ant = novo->ant;
                            novo-> ant = aux;
                            aux->prox = novo;
                            aux = novo ->prox;
                        }
                    } 
                    if(novo == fim){
                        break;
                    }
                }
            }
        }
}

  
void removerConta(int numero){
        
    if(inicio == NULL){
        printf("vazia! :/\n");
    } else{
        if(numero == inicio->numero){
            NO* lixo = inicio;
            inicio->prox->ant = NULL;
            inicio = inicio->prox;
            free(lixo);
        } else if(numero == fim->numero){
            NO*lixo = fim;
            fim -> ant->prox = NULL;
            fim = fim->ant;
            free(lixo);
        }else{
            NO *lixo = inicio;
            while(numero != lixo ->numero){
                lixo = lixo->prox;
            }
            lixo -> ant->prox = lixo->prox;
            lixo ->prox ->ant = lixo -> ant;
            
            free(lixo);
        }
    }
}


void depositar(int numero, int senha, float valor){
    if(inicio == NULL){
        printf("vazia! :/\n");
    } else{
        if(numero == inicio->numero && senha == inicio->senha){
            NO*aux = inicio;
            aux -> saldo += valor;
            aux -> prox -> ant = NULL;
            inicio= aux->prox;
            aux -> prox = NULL;
            
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
            
        } else if(numero == fim->numero && senha == fim->senha){
            NO* aux = fim;
            aux -> saldo += valor;
            aux->ant->prox= NULL;
            fim = aux->ant;
            aux -> ant = NULL;
            
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
        } else {
            NO*aux= inicio;
            while(numero != aux->numero && senha != aux->senha){
                aux= aux->prox;
            }
            if(aux){
                aux -> saldo += valor;
                aux -> ant->prox = aux->prox;
                aux -> prox ->ant = aux ->ant;
                aux->prox = NULL;
                aux->ant= NULL;
                
                cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
            }else{
                printf("Os dados não foram encontrados");
            }
        }
    }
}

void sacar(int numero, int senha, float valor){
    if(inicio == NULL){
        printf("vazia! :/\n");
    } else{
        if(numero == inicio->numero && senha == inicio->senha){
            NO*aux = inicio;
            aux -> saldo -= valor;
            aux -> prox -> ant = NULL;
            inicio= aux->prox;
            aux -> prox = NULL;
            
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
            
        } else if(numero == fim->numero && senha == fim->senha){
            NO* aux = fim;
            aux -> saldo -= valor;
            aux->ant->prox= NULL;
            fim = aux->ant;
            aux -> ant = NULL;
            
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
        } else {
            NO*aux= inicio;
            while(numero != aux->numero && senha != aux->senha){
                aux= aux->prox;
            }
            if(aux){
                aux -> saldo -= valor;
                aux -> ant->prox = aux->prox;
                aux -> prox ->ant = aux ->ant;
                aux->prox = NULL;
                aux->ant= NULL;
                
                cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);
            }else{
                printf("Os dados não foram encontrados");
            }
        }
    }
}





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
    cadastrarConta("jhonas", 5, 3672, 2000);
    cadastrarConta("tuco", 6, 3090, 3000 );
    visualizar();
    printf(" \n");

    removerConta(4);
    removerConta(3);
    removerConta(5);
    visualizar();
    printf(" \n");
    
    depositar(2, 2345, 20);
    depositar(1, 1234, 3200);
    depositar(6, 3090, 17.5);
    visualizar();
    printf(" \n");
    
    sacar(2, 2345, 10);
    sacar(1, 1234, 1000);
    sacar(6, 3090, 15.5);
    visualizar();
    

  return 0;
}