#include <stdio.h>
#include <stdlib.h>

#define TAM 31  // Tamanho da tabela hash

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *begin;
    int size;
} List;

void initializeList(List *l) {
    l->begin = NULL;
    l->size = 0;
}

void insertList(List *l, int value) {
    Node *new = malloc(sizeof(Node));
    if (new) {
        new->value = value;
        new->next = l->begin;
        l->begin = new;
        l->size++;
    } else {
        printf("\nErro ao alocar memória");
    }
}

int findList(List *l, int value) {
    Node *aux = l->begin;
    while (aux) {
        if (aux->value == value) return 1;  // Encontrado
        aux = aux->next;
    }
    return 0;  // Não encontrado
}

void printList(List *l) {
    Node *aux = l->begin;
    while (aux) {
        printf("%d -> ", aux->value);
        aux = aux->next;
    }
    printf("NULL\n");
}

int funcaoHash(int chave) {
    return chave % TAM;
}

void inserir(List t[], int valor) {
    int id = funcaoHash(valor);
    insertList(&t[id], valor);
}

int busca(List t[], int chave) {
    int id = funcaoHash(chave);
    return findList(&t[id], chave);
}

void imprimir(List t[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Posição %d: ", i);
        printList(&t[i]);
    }
}

int main() {
    List tabela[TAM];

    // Inicializando a tabela hash
    for (int i = 0; i < TAM; i++) {
        initializeList(&tabela[i]);
    }

    // Inserindo elementos
    inserir(tabela, 15);
    inserir(tabela, 46);
    inserir(tabela, 31);
    inserir(tabela, 77);
    inserir(tabela, 92);

    // Imprimindo a tabela
    imprimir(tabela);

    // Buscando elementos
    printf("\nBusca pelo 46: %s\n", busca(tabela, 46) ? "Encontrado" : "Não encontrado");
    printf("Busca pelo 100: %s\n", busca(tabela, 100) ? "Encontrado" : "Não encontrado");

    return 0;
}
