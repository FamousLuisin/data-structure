struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} typedef Aluno;

typedef struct Elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);

int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);

int inserir_lista(Lista* lista, Aluno aluno);
int inserir_lista_inicio(Lista* lista, Aluno aluno);
int inserir_lista_ordenada(Lista* lista, Aluno aluno);

int remover_primeiro_lista(Lista* lista);
int remover_ultimo_lista(Lista* lista);
int remover_elemento_lista(Lista* lista, int matricula);

void consultar_lista(Lista* li);
int consultar_indice_lista(Lista* lista, int indice, Aluno* aluno);
int consultar_matricula_lista(Lista* lista, int matricula, Aluno* aluno);