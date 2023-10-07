#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// nó de operadores
typedef struct no{
    char digit;
    struct no * prox;
    struct no * ant;
} NO;

// nó de resultados
typedef struct no_result{
    float valor;
    struct no_result * prox;
    struct no_result * ant;
} NO_RESULT;

NO * topo = NULL;
NO_RESULT * topo_result= NULL;
NO * fim = NULL;
NO_RESULT * fim_result= NULL;

void empilhar(char digit){
    if(!isdigit(digit)){
        NO * novo = malloc(sizeof(NO));
        novo -> digit = digit;
        novo -> prox = NULL;
        novo -> ant = NULL;
        if(!fim){
            topo = novo;
            fim = novo;
        } else {
            fim -> prox = novo;
            novo -> ant = fim;
            fim = novo;
        }
    } else {
        NO_RESULT * novo = malloc(sizeof(NO_RESULT));
        novo -> valor = digit - '0';
        novo -> prox = NULL;
        novo -> ant = NULL;
        if(!fim_result){
            topo_result = novo;
            fim_result = novo;
        } else {
            fim_result -> prox = novo;
            novo -> ant = fim_result;
            fim_result = novo;
        }
    }
}

NO * pop (NO * fim){
    if(fim){
        NO * aux = fim;
        fim = fim -> prox;
        aux -> prox = NULL;
    }
    return fim;
}

NO * push (NO * novo){
    novo -> prox = fim;
    fim = novo;
    return novo;
}

// função para calcular baseado na operação
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

void calcular(char exp[]){
    for (int i =0; exp[i] != '\0'; i++){
        empilhar(exp[i]);
    }

/*
    float a, b;
    char op;
    float result;
    NO * aux = topo;
    

    while(aux){
        if(!isdigit(aux -> digit) && isdigit(aux -> prox -> digit) && isdigit(aux -> prox -> prox -> digit) ){
            op = aux-> digit;
            b = atof(aux ->prox-> digit);
            a = atof(aux ->prox-> prox-> digit);
            result = operacao(a, b, op);
            
        
            
        }
    }*/
    
}





void imprimir(){
    NO_RESULT* aux = topo_result;
    while(aux){
        printf("%.2f\n", aux-> valor);
        aux = aux->prox;
    }
    
    NO * auxr = topo;
    while(auxr){
        printf("%c\n", auxr-> digit);
        auxr = auxr->prox;
    }
}

int main() {
    
    calcular("42+56-*");
    
    
    imprimir();
    return 0;
}