#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// nó de consoantes
typedef struct no{
    char cons;
    struct no * prox;
} NO; 

NO * topo = NULL;

//adicionar na pilha de consoantes
void add_cons(char letra){
    NO * novo = malloc(sizeof(NO));
    novo -> cons = letra;
    novo -> prox = NULL;
    if(!topo){
        topo = novo;
    } else {
        novo -> prox = topo;
        topo = novo;
    }
}

void del(){
    if(topo){
        NO*aux = topo;
        topo = topo->prox;
        
        free(aux);
    } else{
        printf("Pilha vazia");
    }
}

// criptografar
void criptografar(char palavra[]){
    char p1[100];
    int i =0;
    int j;
    while(i< strlen(palavra)){
        if(palavra[i] == 'a' 
        || palavra[i] == 'e' 
        || palavra[i] == 'i' 
        || palavra[i] == 'o' 
        || palavra[i] == 'u'){
            p1[i]= palavra[i];
            i++;
        } else if(palavra[i] == ' '){
            p1[i]= ' ';
            i++;
        } else {
            j=i;
            while(palavra[j]!= 'a' 
                &&palavra[j]!= 'e' 
                &&palavra[j]!= 'i' 
                &&palavra[j]!= 'o' 
                &&palavra[j]!= 'u'
                &&palavra[j]!= '\0'
                &&palavra[j]!= ' '){
                add_cons(palavra[j]);
                j++;
            }
            NO * aux= topo ;
            int k=i;
            while(aux){
                p1[k]= aux->cons;
                aux=aux->prox;
                k++;
            }
            while(topo){
                del();
            }
            i=j-1;
            i++;
        }
    }
   
    p1[i] = '\0';
    printf("%s\n",p1);
    
}


int main() {
    
    criptografar("fernando dtfaipq");
    criptografar("python e chato");
    return 0;
}