#include <stdlib.h>
#include <stdio.h>
#include "ListaEncadeada.h"

struct elemento{
    Aluno dados;
    struct elemento* prox;
} typedef Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    
    if(li != NULL)
        *li = NULL;
    
    return li;
}

void libera_lista(Lista* li){
    if (li != NULL){
        Elemento* no;
        while ((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if (li == NULL) return 0;
    
    int tamanho = 0;
    Elemento* no = *li;
    while (no != NULL){
        tamanho++;
        no = no->prox;
    }
    
    return tamanho;
}

int lista_vazia(Lista* li){
    if (li == NULL || (*li) == NULL) return 1;
    
    return 0;
}

int lista_cheia(Lista* li){
    return 0;
}

int inserir_lista(Lista* li, Aluno aluno){
    if (li == NULL) return 0;
    
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) return 0;
    
    elemento->dados = aluno;
    elemento->prox = NULL;

    if (lista_vazia(li)){
        *li = elemento;
    }else{
        Elemento* no = (*li);

        while (no->prox != NULL){
            no = no->prox;
        }
    
        no->prox = elemento;
    } 
    
    return 1;
}

int inserir_lista_inicio(Lista* li, Aluno aluno){
    if(li == NULL) return 0;

    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    
    if (elemento == NULL) return 0;

    elemento->dados = aluno;
    elemento->prox = *li;

    *li = elemento;
    
    return 1;
}

int inserir_lista_ordenada(Lista* li, Aluno aluno){
    if (li == NULL) return 0;

    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) return 0;
    elemento->dados = aluno;
    
    if ((*li) == NULL){
        elemento->prox = NULL;
        *li = elemento;
    }else{
        Elemento *atual, *anterior = *li;
        
        while (atual != NULL && aluno.matricula > atual->dados.matricula){
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == (*li)){
            elemento->prox = *li;
            *li = elemento;
        }else{
            elemento->prox = atual;
            anterior->prox = elemento;
        }
    }
    
    return 1;
}

int remover_primeiro_lista(Lista* li){
    if (li == NULL || lista_vazia(li)) return 0;

    Elemento* no = *li;
    *li = (*li)->prox;
    free(no);

    return 1;
}

int remover_ultimo_lista(Lista* li){
    if (li == NULL || lista_vazia(li)) return 0;

    Elemento *anterior, *atual = *li;
    
    while (atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == (*li)) *li = NULL;
    else anterior->prox = NULL;
    
    free(atual);

    return 1;
}

int remover_elemento_lista(Lista* li, int matricula){
    if (li == NULL || lista_vazia(li)) return 0;

    Elemento *anterior, *atual = *li;

    while (atual != NULL && atual->dados.matricula != matricula){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return 0;

    if(atual == *li) *li = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
    return 1;
}

void consultar_lista(Lista* li){
    if (li == NULL) return;
    
    Elemento* no = *li;
    printf("[");
    while (no != NULL){
        if (no->prox != NULL) printf("%d, ", no->dados.matricula);
        else printf("%d", no->dados.matricula);
        
        no = no->prox;
    }
    printf("]");

    printf("\n");
}

int consultar_indice_lista(Lista* li, int indice, Aluno* aluno){
    if (li == NULL || lista_vazia(li) || indice < 0) return 0;

    Elemento* no = *li;

    int i = 0;
    while (no != NULL && i < indice){
        no = no->prox;
        i++;
    }

    if (no == NULL) return 0;

    *aluno = no->dados;
    
    return 1;
}

int consultar_matricula_lista(Lista* li, int matricula, Aluno* aluno){
    if (li == NULL || lista_vazia(li)) return 0;

    Elemento* no = *li;

    while (no != NULL && no->dados.matricula != matricula){
        no = no->prox;
    }

    if (no == NULL) return 0;

    *aluno = no->dados;
    
    return 1;
}