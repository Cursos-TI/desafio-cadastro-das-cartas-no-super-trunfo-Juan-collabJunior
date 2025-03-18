#include <stdio.h>
#include <string.h>  // Incluído para usar strcspn, eu queria remover a quebra de linha

//Eu não consegui fazer com que seja possível usar as cartas pré-cadastradas
// sem que eu colocasse valores fixos nas variáveis 





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
    

    // ----------- Menu de escolhas dos atributos -----------

    int escolha1, escolha2;

    printf("\n=== Menu de Comparacao - Primeiro Atributo ===\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &escolha1);

    printf("\n=== Menu de Comparacao - Segundo Atributo ===\n");
    printf("Escolha um segundo atributo (diferente do primeiro):\n");
    if(escolha1 != 1) printf("1 - Populacao\n");
    if(escolha1 != 2) printf("2 - Area\n");
    if(escolha1 != 3) printf("3 - PIB\n");
    if(escolha1 != 4) printf("4 - Pontos Turisticos\n");
    if(escolha1 != 5) printf("5 - Densidade Demografica\n");
    if(escolha1 != 6) printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &escolha2);

    if(escolha1 == escolha2) {
        printf("\nErro: Voce nao pode escolher o mesmo atributo duas vezes.\n");
        return 1;
    }

    // ------- Coomparação dos atributos --------
    float attr1Card1, attr1Card2, attr2Card1, attr2Card2;

    // Primeiro atributo
    switch(escolha1) {
        case 1:
            attr1Card1 = (float)populacao1;
            attr1Card2 = (float)populacao2;
            break;
        case 2:
            attr1Card1 = area1;
            attr1Card2 = area2;
            break;
        case 3:
            attr1Card1 = pib1;
            attr1Card2 = pib2;
            break;
        case 4:
            attr1Card1 = (float)pontosTuristicos1;
            attr1Card2 = (float)pontosTuristicos2;
            break;
        case 5:
            attr1Card1 = densidadePopulacional1;
            attr1Card2 = densidadePopulacional2;
            break;
        case 6:
            attr1Card1 = pibPerCapita1;
            attr1Card2 = pibPerCapita2;
            break;
        default:
            printf("Opcao invalida para o primeiro atributo!\n");
            return 1;
    }

    // Segundo atributo
    switch(escolha2) {
        case 1: // População
            attr2Card1 = (float)populacao1;
            attr2Card2 = (float)populacao2;
            break;
        case 2: // Área
            attr2Card1 = area1;
            attr2Card2 = area2;
            break;
        case 3: // PIB
            attr2Card1 = pib1;
            attr2Card2 = pib2;
            break;
        case 4: // Pontos Turísticos
            attr2Card1 = (float)pontosTuristicos1;
            attr2Card2 = (float)pontosTuristicos2;
            break;
        case 5: // Densidade Demográfica
            attr2Card1 = densidadePopulacional1;
            attr2Card2 = densidadePopulacional2;
            break;
        case 6: // PIB per Capita
            attr2Card1 = pibPerCapita1;
            attr2Card2 = pibPerCapita2;
            break;
        default:
            printf("Opcao invalida para o segundo atributo!\n");
            return 1;
    }


    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    // Exibindo os dados da cidade cadastrada

    // ---------- Exibe dados da CARTA 1 ----------
    printf("\n=== CARTA 1 ===\n");
    printf("Estado: %s\n", estado1);
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
    printf("Estado: %s\n", estado2);
    printf("Codigo da Cidade: %s\n", codigoCidade2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // --------- Exibição dos resultados individuais-------

    printf("\n=== Comparacao Individual do Primeiro Atributo ===\n");
    if(escolha1 == 5) { // Densidade: menor vence
        printf("Carta 1: %.2f hab/km²\n", attr1Card1);
        printf("Carta 2: %.2f hab/km²\n", attr1Card2);
        printf("Resultado: %s venceu!\n", (attr1Card1 < attr1Card2) ? nomeCidade1 : (attr1Card1 > attr1Card2) ? nomeCidade2 : "Empate");
    } else {
        // Para os demais, maior vence
        printf("Carta 1: %.2f\n", attr1Card1);
        printf("Carta 2: %.2f\n", attr1Card2);
        printf("Resultado: %s venceu!\n", (attr1Card1 > attr1Card2) ? nomeCidade1 : (attr1Card1 < attr1Card2) ? nomeCidade2 : "Empate");
    }    

    // Comparação do segundo atributo:
    printf("\n=== Comparacao Individual do Segundo Atributo ===\n");
    if(escolha2 == 5) { // Densidade: menor vence
        printf("Carta 1: %.2f hab/km²\n", attr2Card1);
        printf("Carta 2: %.2f hab/km²\n", attr2Card2);
        printf("Resultado: %s venceu!\n", (attr2Card1 < attr2Card2) ? nomeCidade1 : (attr2Card1 > attr2Card2) ? nomeCidade2 : "Empate");
    } else {
        printf("Carta 1: %.2f\n", attr2Card1);
        printf("Carta 2: %.2f\n", attr2Card2);
        printf("Resultado: %s venceu!\n", (attr2Card1 > attr2Card2) ? nomeCidade1 : (attr2Card1 < attr2Card2) ? nomeCidade2 : "Empate");
    }



    // ------------- Soma dos atributos e resultado final -------------
    float somaCarta1 = attr1Card1 + attr2Card1;
    float somaCarta2 = attr1Card2 + attr2Card2;

    printf("\n=== Resultado Final da Rodada ===\n");
    printf("Soma dos atributos para %s: %.2f\n", nomeCidade1, somaCarta1);
    printf("Soma dos atributos para %s: %.2f\n", nomeCidade2, somaCarta2);
    printf("Comparacao final: %s\n", (somaCarta1 > somaCarta2) ? nomeCidade1 : (somaCarta1 < somaCarta2) ? nomeCidade2 : "Empate");




//     // ===================== Menu Interativo =====================
//     int opcao;
//     printf("\n=== Menu de Comparacao ===\n");
//     printf("Escolha o atributo para comparar as cartas:\n");
//     printf("1 - Populacao\n");
//     printf("2 - Area\n");
//     printf("3 - PIB\n");
//     printf("4 - Pontos Turisticos\n");
//     printf("5 - Densidade Demografica\n");
//     printf("6 - PIB per Capita\n");
//     printf("Opcao: ");
//     scanf("%d", &opcao);

//     // ------------ Comparação: Escolha um atributo (nesse exemplo, População) -------------
//     switch (opcao) {
//         case 1:
//     printf("\n=== Comparacao de Cartas (Atributo: Populacao) ===\n");
//     printf("Carta 1 - %s (%s - %s): %lu\n", nomeCidade1, estado1, codigoCidade1, populacao1);
//     printf("Carta 2 - %s (%s - %s): %lu\n", nomeCidade2, estado2, codigoCidade2, populacao2);

//     if (populacao1 > populacao2) {
//         printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
//     } else { 
//         if (populacao1 < populacao2) {
//             printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//         } else {  // Caso as populações sejam iguais
//             printf("Resultado: Empate!\n");
//                }
//            }
//           break;
//        case 2:
//        printf("\n--- Comparacao de Area ---\n");
//        printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
//        printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
//        if (area1 > area2) {
//         printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
//     } else {
//         if (area1 < area2) {
//             printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//         } else {
//             printf("Resultado: Empate!\n");
//                }
//            }
//           break;
//        case 3:
//        printf("\n--- Comparacao de PIB ---\n");
//        printf("Carta 1 - %s: %.2f bilhoes\n", nomeCidade1, pib1);
//        printf("Carta 2 - %s: %.2f bilhoes\n", nomeCidade2, pib2);
//        if (pib1 > pib2) {
//         printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
//     } else {
//         if (pib1 < pib2) {
//             printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//         } else {
//             printf("Resultado: Empate!\n");
//         }
//     }
//     break;
//     case 4:
//     printf("\n--- Comparacao de Pontos Turisticos ---\n");
//     printf("Carta 1 - %s: %d pontos\n", nomeCidade1, pontosTuristicos1);
//     printf("Carta 2 - %s: %d pontos\n", nomeCidade2, pontosTuristicos2);
//     if (pontosTuristicos1 > pontosTuristicos2) {
//         printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
//     } else {
//         if (pontosTuristicos1 < pontosTuristicos2) {
//             printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//         } else {
//             printf("Resultado: Empate!\n");
//         }
//     }
//     break;
//     case 5:
//     printf("\n--- Comparacao de Densidade Demografica ---\n");
//     printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
//     printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
//     if (densidadePopulacional1 < densidadePopulacional2) {
//         printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
//     } else {
//         if (densidadePopulacional1 > densidadePopulacional2) {
//             printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//         } else {
//             printf("Resultado: Empate!\n");
//         }
//     }
// break;
// case 6:
// printf("\n--- Comparacao de PIB per Capita ---\n");
// printf("Carta 1 - %s: %.2f\n", nomeCidade1, pibPerCapita1);
// printf("Carta 2 - %s: %.2f\n", nomeCidade2, pibPerCapita2);
// if (pibPerCapita1 > pibPerCapita2) {
//     printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
// } else {
//     if (pibPerCapita1 < pibPerCapita2) {
//         printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
//     } else {
//         printf("Resultado: Empate!\n");
//     }
// }
// break;
// default:
// printf("\nOpcao invalida! Por favor, escolha uma opcao de 1 a 6.\n");
// break;
//     }

     return 0;

 }
