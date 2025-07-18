#include "ListaSequencial.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista* li;

    li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
    {
        li->qtd = 0;
    }
    
    return li;
}

void libera_lista(Lista* lista){
    free(lista);
}

int tamanho_lista(Lista* lista){
    if (lista == NULL)
        return -1;
    else
        return lista->qtd;
}

int lista_cheia(Lista* lista){
    if (lista == NULL)
        return -1;

    return (lista->qtd == MAX);
}

int lista_vazia(Lista* lista){
    if (lista == NULL)
        return -1;
    
    return (lista->qtd == 0);
}

int inserir_lista(Lista* lista, struct aluno aluno){
    if (lista == NULL || lista_cheia(lista))
        return 0;

    lista->dados[lista->qtd] = aluno;
    lista->qtd++;
    
    return 1;
}

int inserir_lista_inicio(Lista* lista, struct aluno aluno){
    if(lista == NULL || lista_cheia(lista))
        return 0;
    
    int i;
    for (i = lista->qtd; i > 0; i--)
        lista->dados[i] = lista->dados[i - 1];
    
    lista->dados[0] = aluno;
    lista->qtd++;
    
    return 1;
}

int inserir_lista_ordenada(Lista* lista, struct aluno aluno){
    if(lista == NULL || lista_cheia(lista))
        return 0;

    int k, i = 0;
    while (i < lista->qtd && lista->dados[i].matricula < aluno.matricula)
        i++;
    
    for (k = lista->qtd; k > i; k--)
        lista->dados[k] = lista->dados[k-1];
    
    lista->dados[i] = aluno;
    lista->qtd++;

    return 1;
}

int remover_primeiro_lista(Lista* lista){
    if(lista == NULL || lista_vazia(lista))
        return 0;
    
    for (int i = 0; i < lista->qtd - 1; i++)
        lista->dados[i] = lista->dados[i+1];
    
    lista->qtd--;
    
    return 1;
}

int remover_ultimo_lista(Lista* lista){
    if(lista == NULL || lista_vazia(lista))
        return 0;
    
    lista->qtd--;

    return 1;
}

int remover_elemento_lista(Lista* lista, int matricula){
    if(lista == NULL || lista_vazia(lista))
        return 0;
    
    int i = 0;
    while(i < lista->qtd && lista->dados[i].matricula != matricula)
        i++;
    
    if(i == lista->qtd)
        return 0;
    
    for(int k = i; k < lista->qtd - 1; k++)
        lista->dados[k] = lista->dados[k + 1];
    
    lista->qtd--;

    return 1;
}

void exibir_lista(Lista* lista){
    if(lista == NULL || lista_vazia(lista)){
        printf("[]\n");
        return;
    }

    printf("[");
    for(int i = 0; i < lista->qtd; i++){
        printf("%d", lista->dados[i].matricula);
        if(i != lista->qtd - 1)
            printf(", ");
    }
    printf("]\n");
}

int consultar_indice_lista(Lista* lista, int indice, Aluno* aluno){
    if(lista == NULL || lista_vazia(lista) || indice > tamanho_lista(lista) - 1 || indice < 0)
        return 0;
    
    *aluno = lista->dados[indice];
    return 1;
}

int consultar_matricula_lista(Lista* lista, int matricula, Aluno* aluno){
    if(lista == NULL || lista_vazia(lista))
        return 0;
    
    for (int i = 0; i < lista->qtd; i++){
        if (lista->dados[i].matricula == matricula){
            *aluno = lista->dados[i];
            return 1;
        }
    }
    
    return 0;
}