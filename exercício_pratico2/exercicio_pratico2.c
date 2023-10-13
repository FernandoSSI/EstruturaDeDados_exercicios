#include<stdio.h>
#include<stdlib.h>




//EXERCICIOS//
/*1 - Escolha um conjunto de dados que represente algo que você goste 
muito e apresente uma struct para sua representacao. 
Exemplos: struct jogo, struct comida, struct esporte, struct filme
struct serie, etc.
ATENCAO sua struct deve conter pelo menos 5 dados que represente o objeto em estudo*/
typedef struct Livros{
    char *nome;
    char *autor;
    int ano_de_lancamento;
    float avaliacao;
    float preco;
} livros;

/* 2 - Faca uma funcao que crie variavel do tipo escolhido com alocacao dinâmica 
e retorne o endereco de memoria dessa variavel
ATENÇÃO: voce deve definir valores padroes iniciais para cada dado . */
livros * cria_livros(){
    livros *a = malloc(sizeof(livros));
    a -> nome = "Desconhecido";
    a->autor = "Desconhecido";
    a ->ano_de_lancamento = 0;
    a ->avaliacao = 0.0;
    a->preco = 0.0;
    return a;
}

/*3 -  Faca uma funcao que receba dados do terminal de 5 objetos em estudo
crie um vetor, armazene os 5 objetos neste vetor e 
retorne o seu endereco. */

livros * cria_vetor_livros(){
    livros * vet = malloc(sizeof(livros)*5);

    for(int i =0; i <5 ; i++){
        livros * a = cria_livros(); 

        printf("Qual nome do livro %d? ", i+1);
        a ->nome = malloc(sizeof(char)*100);
        scanf("%s", a->nome);
        printf("Qual nome do autor do livro %d? ", i+1);
        a ->autor = malloc(sizeof(char)*100);
        scanf("%s", a->autor);
        printf("Qual ano de lançamento do livro %d? ", i+1);
        scanf("%d", &a->ano_de_lancamento);
        printf("Qual a avaliação do livro %d (0-5)? ", i+1);
        scanf("%f", &a->avaliacao);
        printf("Qual preço do livro %d? ", i+1);
        scanf("%f", &a->preco);
        vet[i] = *a;
    }
    return vet;
}

/*4 -  DESAFIO: Faca uma funcao que receba uma posicao do vetor, apresente os dados do objeto em estudo que esta nesta posicao 
e altere cada um dos dados deste objeto por valores recebidos do terminal.
Exemplo: o usuário informa que deseja alterar a posicao 2 do vetor de animais, 
Qual posicao deseja alterar: 2
*/

void troca_de_dados(livros * v){
    int livro;

    printf("Qual livro você deseja alterar?");
    scanf("%d", &livro);
    livros * a = cria_livros();

    printf("Qual nome do livro %d? ", livro);
    a-> nome = malloc(sizeof(char)*100);
    scanf("%s", a->nome);
    printf("Qual nome do autor do livro %d? ", livro);
    a->autor = malloc(sizeof(char)*100);
    scanf("%s", a->autor);
    printf("Qual ano de lançamento do livro %d? ", livro);
    scanf("%d", &a->ano_de_lancamento);
    printf("Qual a avaliação do livro %d (0-5)? ", livro);
    scanf("%f", &a->ano_de_lancamento);
    printf("Qual preço do livro %d? ", livro);
    scanf("%d", &a->ano_de_lancamento);
    v[livro] = *a;

        livros p = v[livro];
        printf("novo Nome: %s.\n", p.nome);
        printf("novo autor : %s.\n", p.autor);
        printf("novo ano de lançamento: %d.\n", p.ano_de_lancamento);
        printf("novo avaliação: %f.\n", p.avaliacao);
        printf("novo preço: %f.\n", p.preco);
    
}


//impressão
void imprimir_vetor_livros(livros * v){
    for (int i=0; i < 5; i++){
        livros a = v[i];
        printf("Nome: %s.\n", a.nome);
        printf("autor: %s.\n", a.autor);
        printf("ano de lançamento: %d.\n", a.ano_de_lancamento);
        printf("avaliação: %f.\n", a.avaliacao);
        printf("preço: %f.\n", a.preco);
    }
}

int main(){

   livros * end = cria_vetor_livros();
   imprimir_vetor_livros(end);
   troca_de_dados(end);
    return 0;
}

