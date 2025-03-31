#include <stdio.h>
#include <stdlib.h>

// Tamanho = 2 * valor da tabela e pega o primo mais proxmo
// 2 * 15 = 30, pega o 31
// Como tem
#define TAM 31
void inicializarTabela(int t[]){
    // Passar os valores que servirao como inicializacao, nesse caso o 0
    int i;
    for (i = 0; i< TAM; i++)
        t[i] = 0;
}
int funcaoHash(int chave){
    return chave % TAM;
}
void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while (t[id] != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHas(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            return (t[id]);
        }else{
            id = funcaoHash(id + 1);
        }
    }
}
void imprimir(int t[]){
    int i;
    for (i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}
int main (){
    int tabela[TAM];
    return 0;
}