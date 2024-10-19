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

#include <produtos.h>

typedef struct {
    int idProduto;
    char nomeProd [50]; 
    char descProduto [100];
    float preco;
    int quantidade;
} Produto;

Produto SetProduto(int idProduto, char nomeProd [50], char descProduto [100], float preco, int quantidade){
    Produto prod;
    prod.idProduto = idProduto;
    strcpy(prod.nomeProd, nomeProd);
    strcpy(prod.descProduto, descProduto);
    prod.preco = preco;
    prod.quantidade = quantidade;
    return prod;
}

struct carrinhoCompras{
    idCompras;
}

void imprimeProduto(Produto prod){
    printf("\n*--------------------------------*");
    printf("\n * Id: %d :", prod.idProduto);
    printf("\n * Nome Produto: %s :", prod.nomeProd);
    printf("\n * Descricao do produto: %s :", prod.nomeProd);
    printf("\n * Preco/Valor: %.2f :", prod.preco);
    printf("\n * Quantidade Disponivel: %.2f :", prod.quantidade);
    printf("\n*---------------------------------*");
}

void mostrarCarrinho(){
    //
}

void pagarCredito(){
    //
}

void pagarDebito(){
    //
}

void pagarPix(){
    //
}

void abrirPagamento(int metodo){
    mostrarCarrinho();
    printf("Qual metodo para o pagamento? \n1-Credito \n2-Debito \n3-Pix");
    scanf("%d", metodo);
    switch (metodo) {
        case 1:
            pagarCredito();
            break;
        case 2:
            pagarDebito();
            break;
        case 3:
            pagarPix();
            break;
        default:
            printf("Selecione uma opcao valida!");
            abrirPagamento(metodo);
            break;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int x = 0;
    printf("Seja bem vindo ao mercadao virtual! \n");
    while (true){
        printf("Menu de opcoes \n1- Acessar lista de compras \n2-Acessar lista de compras \n3-Pagar \n4-Cancelar e sair");
        scanf("%d",x);
        switch (x)
        {
        case 1:
            imprimeProduto(p1); // Imprime todos os produtos
            break;
        case 2:
           mostrarCarrinho(); 
        case 3:
            abrirPagamento(0);
        case 4:
            printf("Obrigado por visitar o mercado!");
            return 0;
        default:
            printf("Escolha invalida");
            break;
        }
    }
    return 0;
}
