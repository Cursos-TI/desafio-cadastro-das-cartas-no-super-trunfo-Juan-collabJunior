#include <stdio.h>
#include <string.h>  // Incluído para usar strcspn

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    char codigoCidade[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    // Solicitar ao usuário as informações da cidade
    printf("O código da cidade pode ser de A até H, mas tem um limite de quatro cidades por letra, ou seja, A05 não existe portanto é inválido\n");
    printf("Digite o código da cidade (Exp: A01, B03, F03, H04): ");
    scanf("%s", codigoCidade);
    getchar(); // Limpa o buffer após ler o código da cidade


    printf("Digite o nome da cidade: ");
    fgets(nomeCidade, sizeof(nomeCidade), stdin);
    // Remove a nova linha lida por fgets
    nomeCidade[strcspn(nomeCidade, "\n")] = 0;

    printf("Digite a população da cidade: ");
    scanf("%d", &populacao);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade em bilhões: ");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos);

    // Calcular Densidade Populacional e PIB per Capita
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / (float)populacao;
    
    

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    // Exibindo os dados da cidade cadastrada
    printf("\nDados da Cidade Cadastrada:\n");
    printf("Código da Cidade: %s\n", codigoCidade);
    printf("Nome da Cidade: %s\n", nomeCidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.2f\n", pibPerCapita);
    return 0;
}
