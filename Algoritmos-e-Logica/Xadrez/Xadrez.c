#include <stdio.h>
// void para declarar funções de recursividade (sem valor de retorno)
void Torre(int Casas) { // Função recursiva para simular o movimento da Torre
    if(Casas > 0) { 
        printf("Direita\n");
        Torre(Casas - 1); // Chamada recursiva para continuar o movimento
    }
}

void Bispo(int Casas) {  // Simula o movimento do Bispo com loops aninhados
    for(int i = 0; i < Casas; i++) {
        for(int j = 0; j < Casas; j++) { 
            if(i == j) {
                printf("Cima Direita\n"); // Movimento do Bispo na diagonal
            }
        }
    }
}

void Rainha(int Casas) {  // Função para simular o movimento da Rainha
    for(int R = 0; R < Casas; R++) {
        printf("Esquerda\n");
    }
}

void Cavalo(int Casas) { // Função para simular o movimento do Cavalo em L
    while (Casas--) { // Controla o número de movimentos
        for (int i = 0; i < 2; i++) {
            printf("Cima\n");
        }
        printf("Esquerda\n");
    }
} 

int main() {
    printf("Torre:\n");
    Torre(5); // Define o número de movimentos
    printf("\n");

    printf("Bispo:\n");
    Bispo(5);
    printf("\n");

    printf("Rainha:\n");
    Rainha(8);
    printf("\n");

    printf("Cavalo:\n");
    Cavalo(1); // Apenas um numero de execuções por se tratar de um movimento em L

  return 0;
}