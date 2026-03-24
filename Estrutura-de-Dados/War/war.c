#include <stdio.h>
#include <string.h>

// ---- Constantes globais ----
#define NUM_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

// ---- Estrutura para armazenar dados de cada território ----
struct Territorio {
    char Nome[TAM_NOME];
    char Cor[TAM_COR];
    int Tropas;
};

int main() {
    struct Territorio Territorios[NUM_TERRITORIOS];
    int i, opcao;

    printf("Cadastrando os %d territórios do jogo WAR:\n", NUM_TERRITORIOS);
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);

            printf("Nome do Territorio: ");
            scanf("%s", Territorios[i].Nome);

            printf("Cor do Territorio: ");
            scanf("%s", Territorios[i].Cor);

        printf("Numero de Tropas:");
        scanf("%d", &Territorios[i].Tropas);

    }

    printf("\n\n--- Lista de Territorios ---\n");
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf(" - Nome: %s\n", Territorios[i].Nome);
        printf(" - Cor: %s\n", Territorios[i].Cor);
        printf(" - Tropas: %d\n", Territorios[i].Tropas);
    }
    return 0;
}