#include <stdio.h>

int main() {
    
// 1ª Carta
    char Carta[4]; //"B01" Código da carta, utilizando a inicial B para definir o país.
    char Estado[20]; //"Rio Grande do Sul" Nome do estado.
    char Cidade[20]; //"Porto Alegre" Nome da cidade.
    unsigned long int Populacao; //1332000 População de 1 milhão e 332 mil habitantes.
    float Area; //496.8 Área em km².
    double PIB; // 81560000000.0 PIB em reais.
    int Pontos; //32 Número de pontos turísticos.

// 2ª Carta
    char Carta2[4]; //"B02" Código da carta, utilizando a inicial B para definir o país.
    char Estado2[20]; //"Ceará" Nome do estado.
    char Cidade2[20]; //"Fortaleza" Nome da cidade.
    unsigned long int Populacao2; //2627000 População de 2 milhões e 627 mil habitantes.
    float Area2; //313.8 Área em km².
    double PIB2; // PIB em reais.
    int Pontos2; //28 Número de pontos turísticos.

    printf("Digite o Codigo da Carta: ");
    scanf(" %4s", Carta); // O %4s limita a leitura a 4 caracteres, evitando overflow.

    printf("Digite o nome do estado: "); 
    scanf(" %[^\n]", Estado); // %[^\n] permite ler uma string com espaços até encontrar uma nova linha.
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", Cidade); 

    printf("Digite a população: ");
    scanf("%lu", &Populacao); // %lu para ler um unsigned long int.
    
    printf("Digite a área (km²): ");
    scanf("%f", &Area); // %f para ler um float.
   
    printf("Digite o PIB: ");
    scanf("%lf", &PIB); // %lf para ler um double.
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &Pontos); // %d para ler um inteiro.

    float Densidade_Populacional = (float)Populacao / Area; // Cálculo da densidade populacional.
    double PIBPerCapita = (PIB * 1000000000.0) / Populacao; // Cálculo do PIB per capita.
    double DPI = (1.0 / Densidade_Populacional); // Cálculo do DPI (Densidade Populacional Inversa).
    double SuperPoder = Populacao + Area + PIB + Pontos + PIBPerCapita + Densidade_Populacional + DPI; // Super poder da primeira carta.
    
    printf("Densidade Populacional da primeira carta: %.2f habitantes/km²\n", Densidade_Populacional);
    printf("PIB Per Capita da primeira carta: %.2f reais\n", PIBPerCapita);
    printf("DPI da primeira carta: %.6f\n", DPI);
    printf("Super Poder da primeira carta: %.2f\n", SuperPoder);

    printf("\n"); // Linha em branco para separar as cartas.

    printf("Digite o código da segunda carta: ");
    scanf(" %4s", Carta2); // O %4s limita a leitura a 4 caracteres, evitando overflow.
   
    printf("Digite o nome do estado da segunda carta: ");
    scanf(" %[^\n]", Estado2); // %[^\n] permite ler uma string com espaços até encontrar uma nova linha.
    
    printf("Digite o nome da cidade da segunda carta: ");
    scanf(" %[^\n]", Cidade2);
    
    printf("Digite a população da segunda carta: ");
    scanf("%lu", &Populacao2); // %lu para ler um unsigned long int.
  
    printf("Digite a área (km²) da segunda carta: ");
    scanf("%f", &Area2); // %f para ler um float.
  
    printf("Digite o PIB da segunda carta: ");
    scanf("%lf", &PIB2); // %lf para ler um double.
  
    printf("Digite o número de pontos turísticos da segunda carta: ");
    scanf("%d", &Pontos2); // %d para ler um inteiro.

    float Densidade_Populacional2 = (float)Populacao2 / Area2; // Cálculo da densidade populacional.
    double PIBPerCapita2 = (PIB2 * 1000000000.0) / Populacao2; // Cálculo do PIB per capita
    double DPI2 = (1.0 / Densidade_Populacional2); // Cálculo do DPI (Densidade Populacional Inversa).
    double SuperPoder2 = Populacao2 + Area2 + PIB2 + Pontos2 + PIBPerCapita2 + Densidade_Populacional2 + DPI2; // Super poder da segunda carta.
    
    printf("Densidade Populacional da segunda carta: %.2f habitantes/km²\n", Densidade_Populacional2);
    printf("PIB Per Capita da segunda carta: %.2f reais\n", PIBPerCapita2);
    printf("DPI da segunda carta: %.6f\n", DPI2);
    printf("Super Poder da segunda carta: %.2f\n", SuperPoder2);

    printf("\n");

    // Comparação das cartas
    printf("População da carta 1 (%lu) é maior que a da carta 2 (%lu) = %d\n", Populacao, Populacao2, (Populacao > Populacao2));
    printf("Área da carta 1 (%.1f) é maior que a da carta 2 (%.1f) = %d\n", Area, Area2, (Area > Area2));
    printf("PIB da carta 1 (%.0f) é maior que o da carta 2 (%.0f) = %d\n", PIB, PIB2, (PIB > PIB2));
    printf("Pontos Turísticos da carta 1 (%d) é maior que o da carta 2 (%d) = %d\n", Pontos, Pontos2, (Pontos > Pontos2));
    printf("Densidade Populacional da carta 1 (%.2f) é menor que a da carta 2 (%.2f) = %d\n", Densidade_Populacional, Densidade_Populacional2, (Densidade_Populacional < Densidade_Populacional2));
    printf("PIB Per Capita da carta 1 (%.2f) é maior que o da carta 2 (%.2f) = %d\n", PIBPerCapita, PIBPerCapita2, (PIBPerCapita > PIBPerCapita2));
    printf("Super Poder da carta 1 (%.2f) é maior que o da carta 2 (%.2f) = %d\n", SuperPoder, SuperPoder2, (SuperPoder > SuperPoder2));

    return 0;

}