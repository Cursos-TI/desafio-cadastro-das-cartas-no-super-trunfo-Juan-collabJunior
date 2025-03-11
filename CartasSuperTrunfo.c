#include <stdio.h>
#include <string.h>  // Incluído para usar strcspn, eu queria remover a quebra de linha

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    // ---------- Declaração de variáveis para a CARTA 1 ----------
    char estado1[3];  
    char codigoCidade1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;  // PIB em bilhões
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // ---------- Declaração de variáveis para a CARTA 2 ----------
    char estado2[3];   
    char codigoCidade2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;  // PIB em bilhões
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    // Solicitar ao usuário as informações da cidade


    //  Carta 1
    printf("=== Cadastro da CARTA 1 ===\n");
    printf("Digite o estado (ex: SP): ");
    scanf("%2s", estado1);
    getchar();

    printf("Digite o codigo da cidade (Ex: A01, B03, F03, H04): ");
    scanf("%3s", codigoCidade1);
    getchar(); // Limpa o buffer apos ler o codigo
    
    printf("Digite o nome da cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    // Remove quebra de linha lida pelo fgets
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;

    printf("Digite a populacao da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a area da cidade em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade em bilhoes: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

     //  Carta 2
     printf("\n=== Cadastro da CARTA 2 ===\n");
     printf("Digite o estado (ex: RJ): ");
     scanf("%2s", estado2);
     getchar();

     printf("Digite o codigo da cidade (Ex: A02, C04, G01, H03): ");
     scanf("%3s", codigoCidade2);
     getchar();
 
     printf("Digite o nome da cidade: ");
     fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
     nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;
 
     printf("Digite a populacao da cidade: ");
     scanf("%lu", &populacao2);
 
     printf("Digite a area da cidade em km²: ");
     scanf("%f", &area2);
 
     printf("Digite o PIB da cidade em bilhoes: ");
     scanf("%f", &pib2);
 
     printf("Digite o numero de pontos turisticos: ");
     scanf("%d", &pontosTuristicos2);


     //  Calculos para a Carta 1 
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;  // eu não tava conseguindo de outra forma
    // Super Poder = populacao + area + PIB + pontos turisticos + PIB per Capita + inverso da densidade
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidadePopulacional1);

    //  Calculos para a Carta 2 
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;  
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidadePopulacional2);
    

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    // Exibindo os dados da cidade cadastrada

    // ---------- Exibe dados da CARTA 1 ----------
    printf("\n=== CARTA 1 ===\n");
    printf("Codigo da Cidade: %s\n", codigoCidade1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // ---------- Exibe dados da CARTA 2 ----------
    printf("\n=== CARTA 2 ===\n");
    printf("Codigo da Cidade: %s\n", codigoCidade2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);


    // ------------ Comparação: Escolha um atributo (nesse exemplo, População) -------------
    printf("\n=== Comparacao de Cartas (Atributo: Populacao) ===\n");
    printf("Carta 1 - %s (%s - %s): %lu\n", nomeCidade1, estado1, codigoCidade1, populacao1);
    printf("Carta 2 - %s (%s - %s): %lu\n", nomeCidade2, estado2, codigoCidade2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu! [populacao1 (%lu) > populacao2 (%lu)]\n", nomeCidade1, populacao1, populacao2);
    } else if (populacao1 < populacao2) {
        printf("Resultado: Carta 2 (%s) venceu! [populacao1 (%lu) < populacao2 (%lu)]\n", nomeCidade2, populacao1, populacao2);
    } else {  // Caso as populações sejam iguais
        printf("Resultado: Empate! [populacao1 (%lu) == populacao2 (%lu)]\n", populacao1, populacao2);
    }

    return 0;

}
