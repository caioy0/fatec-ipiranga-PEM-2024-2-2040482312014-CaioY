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
void moverPeca(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4], int origemX, int origemY, int destinoX, int destinoY) {
    strcpy(tabuleiro[destinoX][destinoY], tabuleiro[origemX][origemY]);
    strcpy(tabuleiro[origemX][origemY], "...");
}

// Função para pausar a execução até o usuário pressionar Enter
void esperarProximoMovimento() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

// Função principal que controla a execução dos lances do Xeque Pastor
void xequePastor() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Imprimir o tabuleiro inicial
    imprimirTabuleiro(tabuleiro);

    // Jogada 1: Brancas jogam Peão do Rei (e2 -> e4)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 1, 4, 3, 4); // Peão branco do Rei
    imprimirTabuleiro(tabuleiro);

    // Jogada 1: Pretas jogam Peão do Rei (e7 -> e5)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 6, 4, 4, 4); // Peão preto do Rei
    imprimirTabuleiro(tabuleiro);

    // Jogada 2: Brancas jogam Bispo (f1 -> c4)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 0, 5, 3, 2); // Bispo branco
    imprimirTabuleiro(tabuleiro);

    // Jogada 2: Pretas jogam Cavalo (b8 -> c6)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 7, 1, 5, 2); // Cavalo preto
    imprimirTabuleiro(tabuleiro);

    // Jogada 3: Brancas jogam Dama (d1 -> h5)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 0, 3, 4, 7); // Dama branca
    imprimirTabuleiro(tabuleiro);

    // Jogada 3: Pretas jogam Cavalo (g8 -> f6)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 7, 6, 5, 5); // Cavalo preto
    imprimirTabuleiro(tabuleiro);

    // Jogada 4: Brancas jogam Dama e dão Xeque Mate (Dh5 -> f7)
    esperarProximoMovimento();
    moverPeca(tabuleiro, 4, 7, 5, 4); // Dama branca capturando o peão e xeque mate
    imprimirTabuleiro(tabuleiro);
}

int main() {
    xequePastor();
    return 0;
}
