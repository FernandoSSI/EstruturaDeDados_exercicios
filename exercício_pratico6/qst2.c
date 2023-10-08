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

// função para empilhar os operadores
void empilharOp(char digit){
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
}

//função para empilhar numeros
void empilharResult(float valor){
    NO_RESULT * novo = malloc(sizeof(NO_RESULT));
    novo -> valor = valor;
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

// função para calcular e imprimir
void calcular(char exp[]){
    for (int i =0; exp[i] != '\0'; i++){
        if(!isdigit(exp[i])){
            empilharOp(exp[i]);
        } else {
            empilharResult(exp[i]-'0');
        }
    }
    
    float a, b;
    char op;
    float result;
    NO * auxop = topo;

    while(auxop){
        NO_RESULT * aux = topo_result;
        a = aux -> valor;
        b = aux -> prox -> valor;
        op = auxop -> digit;
        result = operacao(a, b, op);
        
        empilharResult(result);
        
        topo_result = aux -> prox -> prox;
        topo_result -> ant = NULL;
        aux->prox -> prox = NULL;
        aux->prox -> ant = NULL;
        free(aux->prox);
        free(aux);
        
        auxop = auxop -> prox;
    }
    
    printf("%s: %.2f\n",exp, topo_result-> valor);  
}

int main() {
    
    calcular("12-45+*");
    return 0;
}