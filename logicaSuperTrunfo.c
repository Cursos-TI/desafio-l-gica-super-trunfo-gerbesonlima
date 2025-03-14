#include <stdio.h>

int main() {
    printf ("\n**********Jogo SuperTrunfo*********\n");
    printf ("\n-------------Regras de Comparação:---------\n"); 
    printf("\nA regra geral é: vence a carta com o maior valor no atributo escolhido.\n");
    printf("Para a Densidade Demográfica, a regra inverte: vence a carta com o menor valor.\n");
    printf("\n--------Vamos começar cadastrando as cartas ---------\n");

    // Dados para cadastro carta 01
    char estado1[50], codigocarta1[50], nomedacidade1[50];
    unsigned long int populacao1;
    int numeropontosturistico1;
    float areaemkm1, pib1;

    // Dados para cadastro carta 02
    char estado2[50], codigocarta2[50], nomedacidade2[50];
    unsigned long int populacao2;
    int numeropontosturistico2;
    float areaemkm2, pib2;

    // Solicitando dados para cadastro carta 01
    printf("\nDados carta 01\n");
    printf("\nQual estado: ");
    scanf("%s", estado1);

    printf("Codigo da carta: ");
    scanf("%s", codigocarta1);

    printf("Nome da cidade: ");
    scanf("%s", nomedacidade1);

    printf("Populacao: -Digite apenas numeros sem pontuacao- ");
    scanf("%lu", &populacao1);

    printf("Qual a area em KM²? -Digite apenas numeros sem pontuacao-: ");
    scanf("%f", &areaemkm1);

    printf("Qual o PIB? -Digite apenas numeros sem pontuacao-: ");
    scanf("%f", &pib1);

    printf("Quantos pontos turisticos: ");
    scanf("%d", &numeropontosturistico1);

    // Calculo da densidade populacional, PIB per capita e super poder carta 01
    float densidade1 = populacao1 / areaemkm1;
    float pibpercapita0 = pib1 / populacao1;
    float super_poder1 = populacao1 + areaemkm1 + pib1 + numeropontosturistico1 + pibpercapita0 + densidade1;

    // Solicitando dados para cadastro carta 02
    printf("\nDados carta 02\n");

    printf("Qual estado: ");
    scanf("%s", estado2);

    printf("Codigo da carta: ");
    scanf("%s", codigocarta2);

    printf("Nome da cidade: ");
    scanf("%s", nomedacidade2);

    printf("Populacao: -Digite apenas numeros sem pontuacao- ");
    scanf("%lu", &populacao2);

    printf("Qual a area em KM²? -Digite apenas numeros sem pontuacao-: ");
    scanf("%f", &areaemkm2);

    printf("Qual o PIB? -Digite apenas numeros sem pontuacao-: ");
    scanf("%f", &pib2);

    printf("Quantos pontos turisticos: ");
    scanf("%d", &numeropontosturistico2);

    // Calculo da densidade populacional, PIB per capita e super poder carta 02
    float densidade2 = populacao2 / areaemkm2;
    float pibpercapita = pib2 / populacao2;
    float super_poder2 = populacao2 + areaemkm2 + pib2 + numeropontosturistico2 + pibpercapita + densidade2;

    // Escolha dos atributos
    int carta1, carta2;
    printf("Agora escolha o primeiro atributo de comparacao:\n");
    printf("1. Populacao\n2. Pontos Turisticos\n3. Densidade\n");
    scanf("%d", &carta1);

    // Menu dinâmico para o segundo atributo

    printf("Agora escolha o segundo atributo de comparacao:\n");

    switch (carta1) {
        case 1:
            printf("2. Pontos Turisticos\n3. Densidade\n");
            break;
        case 2:
            printf("1. Populacao\n3. Densidade\n");
            break;
        case 3:
            printf("1. Populacao\n2. Pontos Turisticos\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    scanf("%d", &carta2);

    if (carta1 == carta2) {
        printf("Não pode escolher o mesmo atributo duas vezes, escolha outro atributo:\n");
        scanf("%d", &carta2);
    }

    // Comparação dos atributos
    int resultado1 = 0, resultado2 = 0;
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;

    switch (carta1) {
        case 1:
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            resultado1 = (populacao1 > populacao2) ? 1 : 0;
            break;
        case 2:
            valor1_carta1 = numeropontosturistico1;
            valor1_carta2 = numeropontosturistico2;
            resultado1 = (numeropontosturistico1 > numeropontosturistico2) ? 1 : 0;
            break;
        case 3:
            valor1_carta1 = densidade1;
            valor1_carta2 = densidade2;
            resultado1 = (densidade1 < densidade2) ? 1 : 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    switch (carta2) {
        case 1:
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            resultado2 = (populacao1 > populacao2) ? 1 : 0;
            break;
        case 2: 
            valor2_carta1 = numeropontosturistico1;
            valor2_carta2 = numeropontosturistico2;
            resultado2 = (numeropontosturistico1 > numeropontosturistico2) ? 1 : 0;
            break;
        case 3:
            valor2_carta1 = densidade1;
            valor2_carta2 = densidade2;
            resultado2 = (densidade1 < densidade2) ? 1 : 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    // Soma dos atributos
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Exibição do resultado
    printf("\nResultado da Comparação:\n");
    printf("Carta 1 (Estado: %s, Cidade: %s)\n", estado1, nomedacidade1);
    printf("Atributo %d: %.2f\n", carta1, valor1_carta1);
    printf("Atributo %d: %.2f\n", carta2, valor2_carta1);
    printf("Soma dos atributos: %.2f\n", soma_carta1);
    printf("\nCarta 2 (Estado: %s, Cidade: %s)\n", estado2, nomedacidade2);
    printf("Atributo %d: %.2f\n", carta1, valor1_carta2);
    printf("Atributo %d: %.2f\n", carta2, valor2_carta2);
    printf("Soma dos atributos: %.2f\n", soma_carta2);

    if (soma_carta1 > soma_carta2) {
        printf("\nCarta 1 venceu!\n");
    } else if (soma_carta1 < soma_carta2) {
        printf("\nCarta 2 venceu!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
