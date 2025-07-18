#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

int main(){
    Lista* li;

    li = cria_lista();

    int tamanho = tamanho_lista(li);
    int cheia = lista_cheia(li);
    int vazia = lista_vazia(li);

    printf("Tamanho da Lista: %d\n", tamanho);
    printf("Lista cheia: %d\n", cheia);
    printf("Lista vazia: %d\n", vazia);

    printf("================================\n");

    Aluno al1;
    al1.matricula = 5;
    strcpy(al1.nome, "Noc");

    Aluno al2;
    al2.matricula = 2;
    strcpy(al2.nome, "Jhonson");

    Aluno al3;
    al3.matricula = 3;
    strcpy(al3.nome, "Luis Filipe");

    inserir_lista(li, al1);
    inserir_lista_inicio(li, al2);
    inserir_lista_ordenada(li, al3);
    
    tamanho = tamanho_lista(li);
    cheia = lista_cheia(li);
    vazia = lista_vazia(li);

    exibir_lista(li);
    printf("Tamanho da Lista: %d\n", tamanho);
    printf("Lista cheia: %d\n", cheia);
    printf("Lista vazia: %d\n", vazia);

    printf("================================\n");

    Aluno consulta1;
    Aluno consulta2;

    int err = consultar_indice_lista(li, 2, &consulta1);

    if (!err)
        printf("aluno1: NULL\n");
    else
        printf("aluno1: %s\n", consulta1.nome);

    err = consultar_matricula_lista(li, 5, &consulta2);
    
    if (!err)
        printf("aluno2: NULL\n");
    else
        printf("aluno2: %s\n", consulta2.nome);
    
    printf("================================\n");

    remover_primeiro_lista(li);
    exibir_lista(li);
    remover_ultimo_lista(li);
    exibir_lista(li);
    remover_elemento_lista(li, al3.matricula);
    exibir_lista(li);

    tamanho = tamanho_lista(li);
    cheia = lista_cheia(li);
    vazia = lista_vazia(li);

    printf("Tamanho da Lista: %d\n", tamanho);
    printf("Lista cheia: %d\n", cheia);
    printf("Lista vazia: %d\n", vazia);
    
    libera_lista(li);
    return 0;
}