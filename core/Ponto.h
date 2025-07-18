typedef struct ponto Ponto;

Ponto* criar_pto(float x, float y);
void liberar_pto(Ponto* p);
void acessar_pto(Ponto* p, float* x, float* y);
void atribuir_pto(Ponto* p, float x, float y);
float distancia_pto(Ponto* p1, Ponto* p2);