#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho da tabela hash para associar pistas a suspeitos
#define TAM_HASH 13

// Struct para sala e pista, que contem o nome da sala e ponteiros para as salas à esquerda e à direita.
typedef struct Sala {
    char nome[50];
    char pista[100];
    int pistaColetada;
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Struct para nó da BST de pistas, que contem a pista e ponteiros para os filhos.
typedef struct PistaNode {
    char pista[100];
    struct PistaNode *esquerda;
    struct PistaNode *direita;
} PistaNode;

// Struct para nó da tabela hash, que associa uma pista a um suspeito.
typedef struct HashNode {
    char pista[100];
    char suspeito[50];
    struct HashNode *proximo;
} HashNode;

HashNode* tabelaHash[TAM_HASH];

// Função de hash simples para mapear uma pista a um índice na tabela hash
int funcaoHash(const char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % TAM_HASH;
}

/* Contador de pistas contra um suspeito específico, 
percorrendo a BST de pistas coletadas e consultando a tabela hash
 para verificar as associações pista → suspeito. */
int contarPistasContraSuspeito(PistaNode *raiz, const char *suspeito) {

    if (raiz == NULL)
        return 0;

    int total = 0;

    int indice = funcaoHash(raiz->pista);
    HashNode *atual = tabelaHash[indice];

    while (atual) {
        if (strcmp(atual->pista, raiz->pista) == 0 &&
            strcmp(atual->suspeito, suspeito) == 0) {
            total++;
            break;
        }
        atual = atual->proximo;
    }

    total += contarPistasContraSuspeito(raiz->esquerda, suspeito);
    total += contarPistasContraSuspeito(raiz->direita, suspeito);

    return total;
}

// Insere uma pista na tabela hash associando-a a um suspeito.
void inserirNaHash(const char *pista, const char *suspeito) {

    int indice = funcaoHash(pista);

    HashNode *novo = (HashNode*) malloc(sizeof(HashNode));
    if (!novo) exit(1);

    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);

    novo->proximo = tabelaHash[indice];
    tabelaHash[indice] = novo;
}

// Listagem de todas as associações pista → suspeito presentes na tabela hash.
void mostrarAssociacoes() {

    printf("\n=== ASSOCIACOES PISTA → SUSPEITO ===\n");

    for (int i = 0; i < TAM_HASH; i++) {
        HashNode *atual = tabelaHash[i];
        while (atual) {
            printf("Pista: %-25s -> Suspeito: %s\n",
                   atual->pista, atual->suspeito);
            atual = atual->proximo;
        }
    }
}

// Listagem de pistas por suspeito, mostrando apenas as pistas relacionadas a um suspeito específico.
void listarPistasPorSuspeito(const char *suspeito) {

    int encontrou = 0;

    for (int i = 0; i < TAM_HASH; i++) {
        HashNode *atual = tabelaHash[i];
        while (atual) {
            if (strcmp(atual->suspeito, suspeito) == 0) {
                printf("- %s\n", atual->pista);
                encontrou = 1;
            }
            atual = atual->proximo;
        }
    }

    if (!encontrou)
        printf("Nenhuma pista relacionada.\n");
}

// Julgamento final, onde o jogador pode acusar um suspeito com base nas pistas coletadas.
void julgamentoFinal(PistaNode *raizPistas) {

    if (raizPistas == NULL) {
        printf("\nNenhuma pista foi coletada. Investigacao inconclusiva.\n");
        return;
    }

    char acusado[50];

    printf("\n=== JULGAMENTO FINAL ===\n");
    printf("Digite o nome do suspeito acusado: ");
    scanf(" %[^\n]", acusado);

    int total = contarPistasContraSuspeito(raizPistas, acusado);

    printf("\nPistas contra %s: %d\n", acusado, total);

    if (total >= 2) {
        printf(">>> ACUSACAO CONFIRMADA!\n");
        printf("%s eh considerado o culpado com base nas evidencias.\n", acusado);
    } else {
        printf(">>> PROVAS INSUFICIENTES!\n");
        printf("Nao ha evidencias suficientes contra %s.\n", acusado);
    }
}

// Cria dinamicamente uma nova sala com o nome informado, inicializando os ponteiros para NULL.
Sala* criarSala(const char *nome, const char *pista) {

    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (!nova) exit(1);

    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->pistaColetada = 0;
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

// Insere uma pista na BST de pistas coletadas pelo jogador.
PistaNode* inserirPista(PistaNode *raiz, const char *pista) {

    if (!raiz) {
        PistaNode *novo = (PistaNode*) malloc(sizeof(PistaNode));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }

    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (strcmp(pista, raiz->pista) > 0)
        raiz->direita = inserirPista(raiz->direita, pista);

    return raiz;
}

// Exibe as pistas coletadas em ordem alfabética (BST)
void exibirPistas(PistaNode *raiz) {
    if (raiz) {
        exibirPistas(raiz->esquerda);
        printf("- %s\n", raiz->pista);
        exibirPistas(raiz->direita);
    }
}

// Liberação de memória para o mapa da mansão, a BST de pistas e a tabela hash.
void liberarMapa(Sala *raiz) {
    if (raiz) {
        liberarMapa(raiz->esquerda);
        liberarMapa(raiz->direita);
        free(raiz);
    }
}

void liberarBST(PistaNode *raiz) {
    if (raiz) {
        liberarBST(raiz->esquerda);
        liberarBST(raiz->direita);
        free(raiz);
    }
}

void liberarHash() {
    for (int i = 0; i < TAM_HASH; i++) {
        HashNode *atual = tabelaHash[i];
        while (atual) {
            HashNode *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

// Função principal de exploração, que combina navegação, coleta de pistas e acesso à tabela hash.
void explorar(Sala *hall, PistaNode **raizPistas) {

    Sala *atual = hall;
    char op;

    while (1) {

        printf("\n=== DETECTIVE QUEST ===\n");
        printf("1 - Escolher Caminho\n");
        printf("2 - Lista de Suspeitos\n");
        printf("3 - Pistas Encontradas\n");
        printf("0 - Concluir Investigacao\n");
        printf("Opcao: ");
        scanf(" %c", &op);

        if (op == '1') {

            while (1) {

                printf("\nVoce esta em: %s\n", atual->nome);

                if (!atual->pistaColetada && strlen(atual->pista) > 0) {
                    printf(">>> PISTA ENCONTRADA: %s\n", atual->pista);
                    *raizPistas = inserirPista(*raizPistas, atual->pista);
                    atual->pistaColetada = 1;
                }

                printf("e - Esquerda | d - Direita | s - Voltar\n");
                scanf(" %c", &op);

                // NULL em "e" e "d" indicando que é uma sala folha (sem filhos)
                if (op == 'e') {
                    if (atual->esquerda != NULL)
                    atual = atual->esquerda;
                else
                    printf("Nao ha sala a esquerda!\n");
                }
                else if (op == 'd') {
                    if (atual->direita != NULL)
                    atual = atual->direita;
                else
                    printf("Nao ha sala a direita!\n");
                }
                else if (op == 's')
                    break;
                else
                    printf("Caminho invalido!\n");
            }
        }
        // Opção para mostrar a lista de suspeitos e suas pistas associadas
        else if (op == '2') {
            mostrarAssociacoes();
        }
        // Opção para mostrar as pistas coletadas até o momento
        else if (op == '3') {
            printf("\n=== PISTAS COLETADAS ===\n");
            exibirPistas(*raizPistas);
        }

        else if (op == '0') {
            printf("\nEncerrando exploracao...\n");

            printf("\n=== PISTAS COLETADAS ===\n");
            exibirPistas(*raizPistas);

            julgamentoFinal(*raizPistas);

            break;
        }

        else {
            printf("Opcao invalida!\n");
        }
    }
}

// MAIN – Monta o mapa fixo da mansao e inicia a exploração
int main() {

    // Inicializa a tabela hash com NULL
    for (int i = 0; i < TAM_HASH; i++)
        tabelaHash[i] = NULL;
    // Criacao das salas com pistas estrategicas
    Sala *hall = criarSala("Hall", "");
    Sala *sala = criarSala("Sala", "Pegadas na lareira");
    Sala *cozinha = criarSala("Cozinha", "Faca ensanguentada");
    Sala *biblioteca = criarSala("Biblioteca", "Livro rasgado");
    Sala *jardim = criarSala("Jardim", "Luvas sujas");
    Sala *quarto = criarSala("Quarto", "Carta ameacadora");
    Sala *porao = criarSala("Porao", "Corda escondida");

    /* Montagem da arvore (mapa da mansao) que será assim:
                  Hall de Entrada
                  /             \
           Sala de Estar       Cozinha
             /        \        /       \
        Biblioteca  Jardim   Quarto   Porao
    */

    hall->esquerda = sala;
    hall->direita = cozinha;
    sala->esquerda = biblioteca;
    sala->direita = jardim;
    cozinha->esquerda = quarto;
    cozinha->direita = porao;

    inserirNaHash("Pegadas na lareira", "Carlos");
    inserirNaHash("Livro rasgado", "Carlos");
    inserirNaHash("Corda escondida", "Carlos");
    inserirNaHash("Faca ensanguentada", "Marina");
    inserirNaHash("Carta ameacadora", "Marina");
    inserirNaHash("Luvas sujas", "Ana");

    PistaNode *raizPistas = NULL;

    explorar(hall, &raizPistas);

    liberarMapa(hall);
    liberarBST(raizPistas);
    liberarHash();

    return 0;
}