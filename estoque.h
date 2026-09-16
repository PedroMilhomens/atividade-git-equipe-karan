#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_ITENS 50
#define TAXA_PADRAO 0.10
#define TAXA_DESCONTO 0.05

typedef struct {
    int id;
    char nome[30];
    float preco;
    int quantidade;
    char codigo_barras[20];
} Produto;

void exibir_menu(void);
void listar_produtos(Produto lista[], int total);
float calcular_total(Produto lista[], int total);
float aplicar_desconto(float total);

#endifs