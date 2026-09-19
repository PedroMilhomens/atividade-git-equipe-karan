#include <stdio.h>
#include <string.h>
#include "estoque.h"

void exibir_menu(void) {
    printf("\n=== CONTROLE DE ESTOQUE ===\n");
    printf("1 - Listar produtos\n");
    printf("2 - Exibir valor total em estoque\n");
    printf("3- Exibir valor com desconto>\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void listar_produtos(Produto lista[], int total) {
    printf("\n--- Produtos Cadastrados ---\n");

    for (int i = 0; i < total; i++) {
        printf("ID: %d \nCategoria: %s \nNome: %s \nPreco: R$ %.2f \nQtd: %d \nCodigo de barras: %s\n",
            lista[i].id, lista[i].categoria, lista[i].nome,
            lista[i].preco, lista[i].quantidade, lista[i].codigo_barras);
    }
}

float calcular_total(Produto lista[], int total) {
    float soma = 0.0;

    for (int i = 0; i < total; i++) {
        soma += lista[i].preco * lista[i].quantidade;
    }

    return soma + (soma * TAXA_PADRAO);
}
float aplicar_desconto(float valor_total) {
    return valor_total * 0.05;
}

int main(void) {
    Produto estoque[MAX_ITENS];
    int total_produtos = 2;

    estoque[0].id = 1;
    strcpy(estoque[0].categoria, "Papelaria");
    strcpy(estoque[0].nome, "Caderno");
    estoque[0].preco = 15.50;
    estoque[0].quantidade = 10;
    strcpy(estoque[0].codigo_barras, "7890001");

    estoque[1].id = 2;
    strcpy(estoque[1].categoria, "Escritorio");
    strcpy(estoque[1].nome, "Caneta");
    estoque[1].preco = 3.00;
    estoque[1].quantidade = 50;
    strcpy(estoque[1].codigo_barras, "7890002");

    int opcao = -1;

    while (opcao != 0) {
        exibir_menu();

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                listar_produtos(estoque, total_produtos);
                break;

            case 2:
                printf("\nTotal em estoque: R$ %.2f\n",
                       calcular_total(estoque, total_produtos));
                break;
            case 3:
                printf("\nValor com Desconto: R$ %2f\n",
                    aplicar_desconto(calcular_total(estoque, total_produtos)));
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    return 0;
}