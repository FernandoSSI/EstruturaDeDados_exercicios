// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

//nó de caixas
typedef struct no{
    int peso;
    struct no * prox;
} NO;

//nó de pilhas
typedef struct no_de_pilhas{
    NO*topo;
    int tam;
    struct no_de_pilhas * prox;
}NO_PILHAS;

NO_PILHAS * A = NULL;


//função para adicionar na pilha
void add(int peso){
    NO * novo = malloc(sizeof(NO));
    novo -> peso = peso;
    novo -> prox = NULL;
    
    // caso todas as pilhas estiverem vazias
    if(A == NULL ){
        A = malloc(sizeof(NO_PILHAS));
        NO_PILHAS * B = malloc(sizeof(NO_PILHAS));
        NO_PILHAS * C = malloc(sizeof(NO_PILHAS));
        A -> prox = B;
        B-> prox = C;
        C ->prox = NULL;
        A -> topo = novo;
        A -> tam ++;

    } else {
        //Quando a nova caixa tiver peso menor ou igual a primeira da pilha A
        if(novo -> peso <= A -> topo -> peso){
            novo -> prox = A -> topo;
            A -> topo = novo;
            A -> tam ++;
            
        //Quando a nova caixa tem peso maior que a primeira da pilha A
        } else if (novo -> peso > A->topo -> peso){
            NO_PILHAS * B = A->prox;
            NO_PILHAS * C = B->prox;
           
        //retirar as caixas enquanto A-> topo existir e for menor que novo->peso
            while(A->topo && A-> topo -> peso < novo -> peso){
                NO * aux = A->topo;
                //verificação do peso da caixa de topo da pilha A
                if(A -> topo -> peso == 3){
                    A -> topo = aux -> prox;
                    aux -> prox = C -> topo;
                    C -> topo = aux;
                } else if(A -> topo -> peso == 5){
                    A -> topo = aux -> prox;
                    aux -> prox = B -> topo;
                    B -> topo = aux;
                }
            }
            novo -> prox = A-> topo;
            A->topo = novo;
            
            //adicionar novamente as caixa retiradas para A
            while(B->topo){
                NO * aux = B-> topo;
                B -> topo = aux -> prox;
                aux -> prox = A->topo;
                A->topo = aux;
            }
            while(C->topo){
                NO * aux = C-> topo;
                C -> topo = aux -> prox;
                aux -> prox = A->topo;
                A->topo = aux;
            }
            A->tam++;
        }
    }
}

//função para imprimir
void imprimir(){
    NO * aux = A -> topo;
    while(aux){
        printf("%d \n", aux -> peso);
        aux = aux-> prox;
    }
}

int main() {
    
    add(5);
    add(3);
    add(7);
    add(3);
    add(5);
    
    imprimir();
    return 0;
}