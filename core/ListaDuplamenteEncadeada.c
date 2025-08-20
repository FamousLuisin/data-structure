#include "ListaDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct Elemento
{
    Aluno dados;
    struct Elemento *prox;
    struct Elemento *ant;
} typedef Elemento;


Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
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

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if (li == NULL || (*li) == NULL) return 1;

    return 0;
}

int tamanho_lista(Lista* li){
    if (li == NULL) return 0;

    int tamanho = 0;
    Elemento* no = *li;
    while (no != NULL){
        no = no->prox;
        tamanho++;
    }
    
    return tamanho;
}

int inserir_lista(Lista* li, Aluno aluno){
    if (li == NULL) return 0;

    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) return 0;

    elemento->dados = aluno;
    elemento->prox = NULL;

    if (lista_vazia(li))
    {
        elemento->ant = NULL;
        *li = elemento;
    } else {
        Elemento* no = *li;
        while (no->prox != NULL) no = no->prox;
        
        no->prox = elemento;
        elemento->ant = no;
    }
    
    return 1;
}

int inserir_lista_inicio(Lista* li, Aluno aluno){
    if (li == NULL) return 0;

    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) return 0;

    elemento->dados = aluno;
    elemento->prox = (*li);
    elemento->ant = NULL;

    if (!lista_vazia(li))
        (*li)->ant = elemento;

    *li = elemento;

    return 1;
}

int inserir_lista_ordenada(Lista* li, Aluno aluno){
    if (li == NULL) return 0;
    
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) return 0;

    elemento->dados = aluno;

    if(lista_vazia(li)){
        elemento->prox = NULL;
        elemento->ant = NULL;

        *li = elemento;
    } else {
        Elemento *ant, *atual = *li;

        while (atual != NULL && aluno.matricula > atual->dados.matricula){
            ant = atual;
            atual = atual->prox;
        }
        
        if (atual == *li){
            elemento->ant = NULL;
            elemento->prox = atual;
            atual->ant = elemento;
            *li = elemento;
        } else {
            elemento->ant = ant;
            elemento->prox = atual;
            ant->prox = elemento;
            if (atual != NULL)
                atual->ant = elemento;
        }
    }
    
    return 1;
}

int remover_primeiro_lista(Lista* li){
    if (li == NULL || *li == NULL) return 0;

    Elemento* temp = *li;
    *li = (*li)->prox;

    if(*li != NULL)
        (*li)->ant = NULL;

    free(temp);
    return 1;
}

int remover_ultimo_lista(Lista* li){
    if (li == NULL || *li == NULL) return 0;

    Elemento *no = *li;

    while (no->prox != NULL)
        no = no->prox;

    if (no == (*li))
        *li = no->prox;
    else
        no->ant->prox = NULL;
    
    free(no);
    return 1;
}

int remover_elemento_lista(Lista* li, int matricula){
    if (li == NULL || *li == NULL) return 0;

    Elemento *no = *li;

    while (no != NULL && matricula != no->dados.matricula)
        no = no->prox;

    if (no == NULL)
        return 0;
    
    if (no == (*li))
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)
        no->prox->ant = no->ant;
    
    free(no);
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
    if (li == NULL || *li == NULL) return 0;
    
    Elemento* no = *li;
    int i = 0;

    while (no != NULL && i < indice)
    {
        no = no->prox;
        i++;
    }
    
    if (no == NULL) return 0;
    
    *aluno = no->dados;
    return 1;
}

int consultar_matricula_lista(Lista* li, int matricula, Aluno* aluno){
    if (li == NULL || *li == NULL) return 0;

    Elemento* no = *li;

    while (no != NULL && no->dados.matricula != matricula)
        no = no->prox;
    
    if(no == NULL) return 0;

    *aluno = no->dados;
    return 1;
}