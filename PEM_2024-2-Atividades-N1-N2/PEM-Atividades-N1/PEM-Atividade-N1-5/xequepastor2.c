/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Refatorando codigo do xeque pastor *
* Data - 29/08/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tamanho do tabuleiro
#define TAMANHO_TABULEIRO 8

// Função para inicializar o tabuleiro com as peças no estado inicial
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4]) {
    // Limpar o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            strcpy(tabuleiro[i][j], "...");
        }
    }

    // Inicializar peças brancas
    strcpy(tabuleiro[0][0], "BT1");
    strcpy(tabuleiro[0][1], "BC1");
    strcpy(tabuleiro[0][2], "BB1");
    strcpy(tabuleiro[0][3], "BD ");
    strcpy(tabuleiro[0][4], "BR ");
    strcpy(tabuleiro[0][5], "BB2");
    strcpy(tabuleiro[0][6], "BC2");
    strcpy(tabuleiro[0][7], "BT2");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        strcpy(tabuleiro[1][i], "BP ");
    }

    // Inicializar peças pretas
    strcpy(tabuleiro[7][0], "PT1");
    strcpy(tabuleiro[7][1], "PC1");
    strcpy(tabuleiro[7][2], "PB1");
    strcpy(tabuleiro[7][3], "PD ");
    strcpy(tabuleiro[7][4], "PR ");
    strcpy(tabuleiro[7][5], "PB2");
    strcpy(tabuleiro[7][6], "PC2");
    strcpy(tabuleiro[7][7], "PT2");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        strcpy(tabuleiro[6][i], "PP ");
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4]) {
    printf("\n   a   b   c   d   e   f   g   h\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf(" %d\n", 8 - i);
    }
    printf("   a   b   c   d   e   f   g   h\n");
}

// Função para movimentar uma peça no tabuleiro
void moverPeca(char tabuleiro[TAMANHO_TABULEIRO][
