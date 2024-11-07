/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Ponteiros e struct                *
* Data - 01/11/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura do produto
typedef struct {
    int ID;
    char nomeProd[50];
    int qntdEstoque;
    double valorProduto;
} Produto;

// Função para criar um produto
Produto* SetProduto(int ID, char* nomeProd, int qntdEstoque, double valorProduto) {
    Produto* prod = (Produto*)malloc(sizeof(Produto));
    if (prod != NULL) {
        prod->ID = ID;
        strcpy(prod->nomeProd, nomeProd);
        prod->qntdEstoque = qntdEstoque;
        prod->valorProduto = valorProduto;
    }
    return prod;
}

// Função para imprimir os detalhes de um produto
void imprimeProduto(Produto* prod) {
    if (prod != NULL) {
        printf("\n*--------------------------------*");
        printf("\n * Id: %d", prod->ID);
        printf("\n * Nome Produto: %s", prod->nomeProd);
        printf("\n * Quantidade Disponível: %d", prod->qntdEstoque);
        printf("\n * Preço/Valor: %.2f", prod->valorProduto);
        printf("\n*---------------------------------*");
    }
}

// Função para incluir um novo produto
void incluirProduto(Produto* produtos[], int* totalProdutos) {
    int id, quantidade;
    double preco;
    char nome[50];
    
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", nome); // lê até o enter
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &quantidade);
    printf("Digite o valor do produto: ");
    scanf("%lf", &preco);

    produtos[*totalProdutos] = SetProduto(id, nome, quantidade, preco);
    (*totalProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}

// Função para alterar um produto existente por ID
void alterarProduto(Produto* produtos[], int totalProdutos) {
    int id, novaQuantidade;
    double novoPreco;
    char novoNome[50];
    bool encontrado = false;

    printf("Digite o ID do produto que deseja alterar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]s", novoNome);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &novaQuantidade);
            printf("Digite o novo valor do produto: ");
            scanf("%lf", &novoPreco);

            strcpy(produtos[i]->nomeProd, novoNome);
            produtos[i]->qntdEstoque = novaQuantidade;
            produtos[i]->valorProduto = novoPreco;
            printf("Produto alterado com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para consultar um produto por ID
void consultarProduto(Produto* produtos[], int totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja consultar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            imprimeProduto(produtos[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para excluir um produto por ID
void excluirProduto(Produto* produtos[], int* totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            free(produtos[i]); // libera memória do produto
            for (int j = i; j < *totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*totalProdutos)--;
            printf("Produto excluído com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para imprimir todos os produtos
void imprimirDadosProd(Produto* produtos[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        for (int i = 0; i < totalProdutos; i++) {
            imprimeProduto(produtos[i]);
        }
    }
}

// Função para aplicar desconto ao produto
void aplicarDesconto(Produto* produtos[], int totalProdutos) {
    int id;
    double desconto;
    bool encontrado = false;

    printf("Digite o ID do produto para aplicar o desconto: ");
    scanf("%d", &id);
    printf("Digite o percentual de desconto (exemplo, para 10%%, digite 10): ");
    scanf("%lf", &desconto);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            produtos[i]->valorProduto *= (1 - desconto / 100.0);
            printf("Desconto aplicado com sucesso! Novo valor: %.2f\n", produtos[i]->valorProduto);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

int main() {
    Produto* produtos[10];
    int totalProdutos = 0;
    int opcao;

    printf("Seja bem-vindo à loja de produtos eletrônicos!\n");

    while (true) {
        printf("\nMenu de opções:\n1 - Incluir produto\n2 - Alterar produto por ID\n3 - Consultar produto por ID\n4 - Excluir produto\n");
        printf("5 - Imprimir todos os produtos\n6 - Aplicar desconto em produto\n7 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &totalProdutos);
                break;
            case 2:
                alterarProduto(produtos, totalProdutos);
                break;
            case 3:
                consultarProduto(produtos, totalProdutos);
                break;
            case 4:
                excluirProduto(produtos, &totalProdutos);
                break;
            case 5:
                imprimirDadosProd(produtos, totalProdutos);
                break;
            case 6:
                aplicarDesconto(produtos, totalProdutos);
                break;
            case 7:
                printf("Obrigado por usar o sistema da loja!\n");
                for (int i = 0; i < totalProdutos; i++) {
                    free(produtos[i]); // liberar memória dos produtos ao sair
                }
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}
