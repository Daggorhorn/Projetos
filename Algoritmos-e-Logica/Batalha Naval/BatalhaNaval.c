#include <stdio.h>

#define TAM_TAB 10

// Matrizes das habilidades (3x5)
int Cone[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1}
};

int Cruz[3][5] = {
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0}
};

int Octaedro[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};
 
// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[3][5], int origem_linha, int origem_coluna) {
    int centro_linha = 1; // centro da matriz 3x5
    int centro_coluna = 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linha_tab = origem_linha + (i - centro_linha); 
            int coluna_tab = origem_coluna + (j - centro_coluna);
            if (linha_tab >= 0 && linha_tab < TAM_TAB && coluna_tab >= 0 && coluna_tab < TAM_TAB) { // Verifica limites do tabuleiro
                if (habilidade[i][j] == 1) {
                    if (tabuleiro[linha_tab][coluna_tab] == 3) {
                        tabuleiro[linha_tab][coluna_tab] = 5; // Navio na área de habilidade
                    } else {
                        tabuleiro[linha_tab][coluna_tab] = 1; // Marca visualmente (1)
                    }
                }
                
            }
        }
    }
}

int main() {
    // Tabuleiro de Batalha Naval 10x10
    printf("Tabuleiro Batalha Naval\n");
    char coluna[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;// Inicializa o tabuleiro com água (0)
        }
    }
    // Valores: 0 = água, 1 = especial, 3 = navio, 5 = parte do navio dentro da área da habilidade
    // Navio 1: horizontal na linha 1 (B4, C4, D4)
    tabuleiro[3][1] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;
    // Navio 2: vertical na coluna F (G6, G7, G8)
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;
    tabuleiro[8][6] = 3;
    // Navio 3: diagonal cima direita (H3, I2, J1)
    tabuleiro[2][7] = 3;
    tabuleiro[1][8] = 3;
    tabuleiro[0][9] = 3;
    // Navio 4: diagonal cima esquerda (D10, C9, B8)
    tabuleiro[9][3] = 3;
    tabuleiro[8][2] = 3;
    tabuleiro[7][1] = 3;

    // Exemplo de aplicação das habilidades
    aplicarHabilidade(tabuleiro, Cone, 1, 7);      // centro do cone em H2
    aplicarHabilidade(tabuleiro, Cruz, 3, 2);      // centro da cruz em C4
    aplicarHabilidade(tabuleiro, Octaedro, 7, 6);  // centro do octaedro em G8

    // Imprime cabeçalho das colunas (A-J)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c", coluna[j]);
    }
    printf("\n");

    // Imprime linhas numeradas de 1 a 10
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0; 
}