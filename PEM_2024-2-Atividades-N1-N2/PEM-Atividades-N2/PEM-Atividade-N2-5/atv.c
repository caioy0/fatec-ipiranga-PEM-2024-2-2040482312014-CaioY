/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Ponteiros e struct                *
* Data - 01/11/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

//struc dos produtos
typedef struct {
    int ID;
    char nomeProd [50]; 
    int qntdEstoque;
    double valorProduto;
} Produto;


Produto* SetProduto(int ID, char* nomeProd, int qntdEstoque, double valorProduto) {
    Produto* prod = (Produto*) malloc(sizeof(Produto)); //aloca memória para um Produto
    if (prod != NULL) {
        prod->ID = ID;
        strcpy(prod->nomeProd, nomeProd);
        prod->qntdEstoque = qntdEstoque;
        prod->valorProduto = valorProduto;
    }
    return prod;
}

void imprimeProduto(Produto* prod) {
    printf("\n*--------------------------------*");
    printf("\n * Id: %d", prod->ID);
    printf("\n * Nome Produto: %s", prod->nomeProd);
    printf("\n * Quantidade Disponivel: %d", prod->qntdEstoque);
    printf("\n * Preco/Valor: %.2f", prod->valorProduto);
    printf("\n*---------------------------------*");
}

//numero 1

void incluirProduto() {
    
}
//numero 2
void alterarProduto() {
    
}

//Numero 3
void consultarProduto() {

}

//N4
void excluirProduto(){
    
}

void imprimirDadosProd(Produto* produtos[], int totalProdutos){
    for (int i = 0; i < totalProdutos; i++) {
        imprimeProduto(produtos[i]);
    }
}

int main() {
    Produto* produtos[10];
    int totalProdutos = 0;
    int opcao;
    printf("Seja bem-vindo ao Mercadão Virtual!\n");

    while (true) {
        printf("\nMenu de opções:\n1 - Incluir produto\n2 - Alterar produtos por ID\n3 - Consultar produto\n4 - excluir produto");
        printf("\n5 - Imprimir dados do produtos produtos\n6 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // incluir produto
                incluirProduto();
                break;
            case 2: // alterar produto por id
                alterarProduto();
                break;
            case 3: // consultar produto
                consultarProduto();
                break;
            case 4: // excluir produto
                excluirProduto();
                break;
            case 5: // imprimir dados do produto
                imprimirDadosProd(produtos, totalProdutos);
                break;
            case 6:
                printf("Obrigado por visitar o Mercadão Virtual!\n");
                return 0; 
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}