#include <stdio.h>

int main() {
    
// 1ª Carta
    char Estado[4] = "RS"; // Usamos char para armazenar o nome do estado, pois é uma string curta
    unsigned long int Populacao; // 1332000 População é um número grande, então usamos unsigned long int para garantir que não haja overflow
    float Area; // 496.8 Área em km², usando float para permitir casas decimais
    double PIB; // 81560000000.0 PIB usando double para maior precisão
    int Pontos; // 32 Número de pontos turísticos, usando int já que é um número inteiro
    float Densidade_Populacional = (float)Populacao / Area; // Densidade populacional é a população dividida pela área
    double PIBPerCapita = (PIB * 1000000000.0) / Populacao;
    
// 2ª Carta
    char Estado2[4] = "CE";
    unsigned long int Populacao2; // 2627000
    float Area2; // 313.8
    double PIB2; // 73000000000.0
    int Pontos2; // 32
    float Densidade_Populacional2 = (float)Populacao2 / Area2;
    double PIBPerCapita2 = (PIB2 * 1000000000.0) / Populacao2;

    int opcao; // Variável para armazenar a escolha do usuário

    printf("Escolha o atributo para comparar:\n"); // Menu de opções para o usuário escolher qual atributo comparar
    printf("1 - População\n"); // Opção 1: População
    printf("2 - Área\n"); // Opção 2: Área
    printf("3 - PIB\n"); // Opção 3: PIB
    printf("4 - Pontos turísticos\n"); // Opção 4: Pontos turísticos
    printf("5 - Densidade demográfica\n"); // Opção 5: Densidade demográfica
    printf("6 - PIB per capita\n"); // Opção 6: PIB per capita
    printf("Digite o número da opção: "); // Solicita ao usuário que insira sua escolha
    scanf("%d", &opcao); // Lê a escolha do usuário

    printf("\nEstados: %s e %s\n", Estado, Estado2); // Exibe os estados que estão sendo comparados

    switch (opcao) { // Estrutura switch para comparar os atributos com base na escolha do usuário
        case 1: // Caso o usuário escolheu comparar a população
            printf("Atributo: População\n"); // Exibe o atributo que está sendo comparado
            printf("Digite o valor da População da Carta 1: ");
            scanf("%lu", &Populacao);
            printf("Digite o valor da População da Carta 2: ");
            scanf("%lu", &Populacao2);
            printf("Carta 1: %s = %lu\n", Estado, Populacao); // Exibe o Estado e a população da primeira carta
            printf("Carta 2: %s = %lu\n", Estado2, Populacao2); // Exibe o Estado e a população da segunda carta
            
            if (Populacao > Populacao2) // Estrutura if para determinar se a população primeira carta é maior
                printf("Carta 1 venceu!\n"); // Exibe que a primeira carta venceu
            else if (Populacao < Populacao2) // Estrutura else if para se a população da segunda carta for maior
                printf("Carta 2 venceu!\n"); // Exibe que a segunda carta venceu
            else // Caso as populações sejam iguais
                printf("Empate!\n"); // Exibe que houve um empate
            break; // Encerra o case 1
        case 2:
            printf("Atributo: Área\n");
            printf("Digite o valor da Área da Carta 1: ");
            scanf("%f", &Area);
            printf("Digite o valor da Área da Carta 2: ");
            scanf("%f", &Area2);
            printf("Carta 1: %s = %.2f\n", Estado, Area);
            printf("Carta 2: %s = %.2f\n", Estado2, Area2);

            if (Area > Area2)
                printf("Carta 1 venceu!\n");
            else if (Area < Area2)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("Digite o valor do PIB da Carta 1: ");
            scanf("%lf", &PIB);
            printf("Digite o valor do PIB da Carta 2: ");
            scanf("%lf", &PIB2);
            printf("Carta 1: %s = %.2f\n", Estado, PIB);
            printf("Carta 2: %s = %.2f\n", Estado2, PIB2);

            if (PIB > PIB2)
                printf("Carta 1 venceu!\n");
            else if (PIB < PIB2)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("Digite o valor dos Pontos turísticos da Carta 1: ");
            scanf("%d", &Pontos);
            printf("Digite o valor dos Pontos turísticos da Carta 2: ");
            scanf("%d", &Pontos2);
            printf("Carta 1: %s = %d\n", Estado, Pontos);
            printf("Carta 2: %s = %d\n", Estado2, Pontos2);

            if (Pontos > Pontos2)
                printf("Carta 1 venceu!\n");
            else if (Pontos < Pontos2)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Atributo: Densidade demográfica\n");
            printf("Digite o valor da População da Carta 1: ");
            scanf("%lu", &Populacao);
            printf("Digite o valor da Área da Carta 1: ");
            scanf("%f", &Area);
            Densidade_Populacional = (float)Populacao / Area;
            if (Populacao == 0 || Area == 0) {
                printf("População ou Área não podem ser zero para calcular a densidade populacional.\n");
                return 1; // Encerra o programa se População ou Área forem zero
            }
            
            printf("Digite o valor da População da Carta 2: ");
            scanf("%lu", &Populacao2);
            printf("Digite o valor da Área da Carta 2: ");
            scanf("%f", &Area2);
            Densidade_Populacional2 = (float)Populacao2 / Area2;
            if (Populacao2 == 0 || Area2 == 0) {
                printf("População ou Área não podem ser zero para calcular a densidade populacional.\n");
                return 1; // Encerra o programa se População ou Área forem zero
            }
            printf("Carta 1: %s = %.2f\n", Estado, Densidade_Populacional);
            printf("Carta 2: %s = %.2f\n", Estado2, Densidade_Populacional2);

            if (Densidade_Populacional < Densidade_Populacional2) // Menor densidade populacional vence
                printf("Carta 1 venceu!\n");
            else if (Densidade_Populacional > Densidade_Populacional2) // Maior densidade populacional perde
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 6:
            printf("Atributo: PIB per capita\n");
            printf("Digite o valor do PIB da Carta 1: ");
            scanf("%lf", &PIB);
            printf("Digite o valor da População da Carta 1: ");
            scanf("%lu", &Populacao);
            PIBPerCapita = (PIB * 1000000000.0) / Populacao;
            if (Populacao == 0) {
                printf("População não pode ser zero para calcular o PIB per capita.\n");
                return 1; // Encerra o programa se População for zero
            }
            printf("Digite o valor do PIB da Carta 2: ");
            scanf("%lf", &PIB2);
            printf("Digite o valor da População da Carta 2: ");
            scanf("%lu", &Populacao2);
            PIBPerCapita2 = (PIB2 * 1000000000.0) / Populacao2;
            if (Populacao2 == 0) {
                printf("População não pode ser zero para calcular o PIB per capita.\n");
                return 1; // Encerra o programa se População for zero
            }
            printf("Carta 1: %s = %.2f\n", Estado, PIBPerCapita);
            printf("Carta 2: %s = %.2f\n", Estado2, PIBPerCapita2);

            if (PIBPerCapita > PIBPerCapita2)
                printf("Carta 1 venceu!\n");
            else if (PIBPerCapita < PIBPerCapita2)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        default: // Caso o usuário insira uma opção inválida
            printf("Opção inválida!\n"); // Exibe mensagem de erro
    }
}