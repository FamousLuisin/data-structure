#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

int main(){
    Lista* li;

    li = cria_lista();

    int tamanho, vazia;

    tamanho = tamanho_lista(li);
    vazia = lista_vazia(li);

    printf("Lista vazia? %d\n", vazia);
    printf("Tamanho da lista: %d\n", tamanho);
    printf("=================================\n");

    Aluno alunos[5] = {
        {1, "Ana Silva", 8.0, 7.5, 9.0},
        {2, "Bruno Souza", 6.5, 7.0, 8.0},
        {3, "Carla Mendes", 9.0, 8.5, 9.5},
        {4, "Diego Rocha", 5.0, 6.0, 7.0},
        {5, "Elisa Costa", 7.5, 8.0, 8.5}
    };

    inserir_lista(li, alunos[1]);
    inserir_lista_inicio(li, alunos[0]);
    inserir_lista(li, alunos[3]);
    inserir_lista_ordenada(li, alunos[2]);
    inserir_lista_ordenada(li, alunos[4]);

    consultar_lista(li);

    printf("=================================\n");

    remover_primeiro_lista(li);
    remover_ultimo_lista(li);
    int teste = remover_elemento_lista(li, 3);

    tamanho = tamanho_lista(li);
    vazia = lista_vazia(li);
    printf("Lista vazia? %d\n", vazia);
    printf("Tamanho da lista: %d\n", tamanho);
    
    consultar_lista(li);

    printf("=================================\n");

    Aluno a1, a2;

    int t1 = consultar_indice_lista(li, 0, &a1);
    int t2 = consultar_matricula_lista(li, 2, &a2);

    printf("Teste Aluno 1: %d | Teste Aluno 2: %d\n", t1, t2);
    
    if (t1 == 1) printf("Aluno 1: %s\n", a1.nome);
    if (t2 == 1) printf("Aluno 2: %s\n", a2.nome);
    

    return 0;
}