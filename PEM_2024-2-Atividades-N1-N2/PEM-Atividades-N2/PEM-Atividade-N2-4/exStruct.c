/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Struct e bubbleSort               *
* Data - 18/10/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

//struc dos produtos
typedef struct {
    int idProduto;
    char nomeProd [50]; 
    char descProduto [100];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto* produto;
    int quantidadeComprada;
} Carrinho;

Produto* SetProduto(int idProduto, char* nomeProd, char* descProduto, float preco, int quantidade) {
    Produto* prod = (Produto*) malloc(sizeof(Produto)); //aloca memória para um Produto
    if (prod != NULL) {
        prod->idProduto = idProduto;
        strcpy(prod->nomeProd, nomeProd);
        strcpy(prod->descProduto, descProduto);
        prod->preco = preco;
        prod->quantidade = quantidade;
    }
    return prod;
}

void imprimeProduto(Produto* prod) {
    printf("\n*--------------------------------*");
    printf("\n * Id: %d", prod->idProduto);
    printf("\n * Nome Produto: %s", prod->nomeProd);
    printf("\n * Descricao do produto: %s", prod->descProduto);
    printf("\n * Preco/Valor: %.2f", prod->preco);
    printf("\n * Quantidade Disponivel: %d", prod->quantidade);
    printf("\n*---------------------------------*");
}

//numero 1
void imprimirListaProdutos(Produto* produtos[], int totalProdutos) {
    for (int i = 0; i < totalProdutos; i++) {
        imprimeProduto(produtos[i]);
    }
}

void bubbleSortProdutos(Produto* produtos[], int totalProdutos) {
    for (int i = 0; i < totalProdutos - 1; i++) {
        for (int j = 0; j < totalProdutos - i - 1; j++) {
            if (strcmp(produtos[j]->nomeProd, produtos[j+1]->nomeProd) > 0) {
                Produto* temp = produtos[j];
                produtos[j] = produtos[j+1];
                produtos[j+1] = temp;
            }
        }
    }
}

//parte do numero 1
void acaoCompra(Produto* produtos[], int totalProdutos, Carrinho carrinho[], int* totalCarrinho) {
    int idProduto, quantidade;
    
    printf("\nDigite o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    // Busca o produto pelo ID
    Produto* produto = NULL;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->idProduto == idProduto) {
            produto = produtos[i];
            break;
        }
    }

    if (produto == NULL) {
        printf("Produto inexistente.\n");
        return;
    }

    // Solicita a quantidade de produtos desejados
    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade > produto->quantidade) {
        printf("Quantidade insuficiente em estoque.\n");
    } else {
        produto->quantidade -= quantidade; // Atualiza o estoque

        // Adiciona o produto ao carrinho
        carrinho[*totalCarrinho].produto = produto;
        carrinho[*totalCarrinho].quantidadeComprada = quantidade;
        (*totalCarrinho)++;  // Incrementa o total de itens no carrinho

        printf("Produto adicionado ao carrinho!\n");
    }
}

//numero 2
void mostrarCarrinho(Carrinho carrinho[], int totalCarrinho) {
    if (totalCarrinho == 0) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("Produtos no carrinho:\n");
    for (int i = 0; i < totalCarrinho; i++) {
        Produto* produto = carrinho[i].produto;
        printf("\n*--------------------------------*");
        printf("\n * Nome Produto: %s", produto->nomeProd);
        printf("\n * Quantidade Comprada: %d", carrinho[i].quantidadeComprada);
        printf("\n * Preco Unitario: %.2f", produto->preco);
        printf("\n * Total: %.2f", produto->preco * carrinho[i].quantidadeComprada);
        printf("\n*---------------------------------*");
    }
}

//Numero 3
void abrirPagamento() {
    char pix[11];
    const char* chars = "AaBbCcDdEeFfGgHhIiJjKkLlMNOoPQRSTUuVWwXxYZ1234567890";
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        pix[i] = chars[rand() % 36];
    }
    pix[10] = '\0'; 
    
    printf("Pagamento gerado por Pix\nCodigo Pix: %s\n", pix);
}

int main() {
    Produto* produtos[10];
    Carrinho carrinho[10]; 
    int totalProdutos = 0, totalCarrinho = 0; 

    produtos[totalProdutos++] = SetProduto(1, "Smartphone X10", "Smartphone com tela de 6.5''", 1299.00, 30);
    produtos[totalProdutos++] = SetProduto(2, "Laptop Ultra 15''", "Laptop com processador i7 e 16GB RAM", 3499.00, 20);
    produtos[totalProdutos++] = SetProduto(3, "TV LED 50'' 4K", "Televisão LED 50'' com resolução 4K", 2199.00, 15);
    produtos[totalProdutos++] = SetProduto(4, "Fone Bluetooth", "Fone de ouvido Bluetooth com cancelamento de ruído", 199.00, 50);
    produtos[totalProdutos++] = SetProduto(5, "Caixa de Som Bluetooth", "Caixa de som portátil com conectividade Bluetooth", 299.00, 25);
    produtos[totalProdutos++] = SetProduto(6, "Câmera Digital 24MP", "Câmera digital com 24 megapixels", 1799.00, 10);
    produtos[totalProdutos++] = SetProduto(7, "Console Game X", "Console de videogame de última geração", 2499.00, 8);
    produtos[totalProdutos++] = SetProduto(8, "Tablet 10''", "Tablet com tela de 10 polegadas e 64GB", 899.00, 20);
    produtos[totalProdutos++] = SetProduto(9, "Impressora Multifuncional", "Impressora que imprime, copia e digitaliza", 499.00, 12);
    produtos[totalProdutos++] = SetProduto(10, "Microfone Condensador", "Microfone condensador para gravações de áudio", 349.00, 15);

    int opcao;
    printf("Seja bem-vindo ao Mercadão Virtual!\n");

    while (true) {
        printf("\nMenu de opções:\n1 - Acessar lista de produtos\n2 - Mostrar carrinho\n3 - Pagar\n4 - Finalizar\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                bubbleSortProdutos(produtos, totalProdutos); 
                imprimirListaProdutos(produtos, totalProdutos);
                acaoCompra(produtos, totalProdutos, carrinho, &totalCarrinho); 
                break;
            case 2:
                mostrarCarrinho(carrinho, totalCarrinho);
                break;
            case 3:
                abrirPagamento();
                break;
            case 4:
                printf("Obrigado por visitar o Mercadão Virtual!\n");
                return 0; 
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}