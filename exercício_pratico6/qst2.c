#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//nó de valores
typedef struct no{
    float valor;
    struct no * prox;
    struct no * ant;
}NO;

NO * final = NULL;
NO * inicio = NULL;

// func para add na fila
void add(float valor){
    NO * novo = malloc(sizeof(NO));
    novo -> valor = valor;
    if(!final){
        final = novo;
        inicio = novo;
    } else {
        final -> prox = novo;
        novo -> ant = final;
        final= novo;
    }
}

//func para remover no fim da fila
void remover(){
    if(final){
        NO * aux = final;
        final = aux->ant;
        
        free(aux);
    }else{
        printf("A lista está vazia, não consigo remover");
    }
}

// func de operações
float operacao (float a, float b, char operador){
    switch(operador){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break; 
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
        default:
            return 0.0;
    }
}

//func para calcular
void calc(char palavra[]){
    char p1[100];
    int tam = strlen(palavra);
    char *pt;
    
    for(int i=0; i<tam; i++){
        p1[i] = palavra[i];
    }
    p1[tam] = '\0';
    
    
    pt = strtok(p1, " ");
    while(pt){
        printf("%s ", pt);
        float num;
        
        if(pt[0] >= '0' && pt[0] <= '9'){
            num = atof(pt);
            add(num);
        } else{
            
            float result=operacao(final->ant->valor, final->valor,pt[0]);
            
            if(final){
                remover();
                if(final){
                    remover();
                    add(result);
                }
                
            }
        }
        pt = strtok(NULL, " ");
    }
   
    printf(" = %.2f \n", inicio-> valor);
    
    free(inicio);
    inicio = NULL;
    final = NULL;
}

int main(){

    calc("1 2 - 4 5 + *");
    calc("12 6 - 10 1 + *");
    calc("15 6 * 6 /");

    return 0;
}