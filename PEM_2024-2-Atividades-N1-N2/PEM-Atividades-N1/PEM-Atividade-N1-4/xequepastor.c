/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Recriar o xeque pastor em c       *
* Data - 29/08/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Tamanho do tabuleiro
#define SIZE 8

// Função para inicializar o tabuleiro com as peças iniciais
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE][4]) {
    // Peças brancas
    strcpy(tabuleiro[0][0], "BT1");
    strcpy(tabuleiro[0][1], "BC1");
    strcpy(tabuleiro[0][2], "BB1");
    strcpy(tabuleiro[0][3], "BD");
    strcpy(tabuleiro[0][4], "BR");
    strcpy(tabuleiro[0][5], "BB2");
    strcpy(tabuleiro[0][6], "BC2");
    strcpy(tabuleiro[0][7], "BT2");
    for (int i = 0; i < SIZE; i++) {
        sprintf(tabuleiro[1][i], "BP%d", i+1);
    }

    // Peças pretas
    strcpy(tabuleiro[7][0], "PT1");
    strcpy(tabuleiro[7][1], "PC1");
    strcpy(tabuleiro[7][2], "PB1");
    strcpy(tabuleiro[7][3], "PD");
    strcpy(tabuleiro[7][4], "PR");
    strcpy(tabuleiro[7][5], "PB2");
    strcpy(tabuleiro[7][6], "PC2");
    strcpy(tabuleiro[7][7], "PT2");
    for (int i = 0; i < SIZE; i++) {
        sprintf(tabuleiro[6][i], "PP%d", i+1);
    }

    // Casos vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < SIZE; j++) {
            strcpy(tabuleiro[i][j], "X");
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE][4]) {
    printf("  a   b   c   d   e   f   g   h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%-4s", tabuleiro[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a   b   c   d   e   f   g   h\n\n");
}

// Função para mover uma peça no tabuleiro
void moverPeca(char tabuleiro[SIZE][SIZE][4], int linhaOrigem, int colOrigem, int linhaDestino, int colDestino) {
    strcpy(tabuleiro[linhaDestino][colDestino], tabuleiro[linhaOrigem][colOrigem]);
    strcpy(tabuleiro[linhaOrigem][colOrigem], "...");
}

int main() {
    char tabuleiro[SIZE][SIZE][4];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Exibe o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada #1: Peão do Rei branco (e2 para e4)
    moverPeca(tabuleiro, 1, 4, 3, 4); // BP5 move de e2 para e4
    imprimirTabuleiro(tabuleiro);

    // Jogada #1: Peão do Rei preto (e7 para e5)
    moverPeca(tabuleiro, 6, 4, 4, 4); // PP5 move de e7 para e5
    imprimirTabuleiro(tabuleiro);

    // Jogada #2: Bispo do Rei branco (f1 para c4)
    moverPeca(tabuleiro, 0, 5, 3, 2); // BB2 move de f1 para c4
    imprimirTabuleiro(tabuleiro);

    // Jogada #2: Cavalo da Dama preto (b8 para c6)
    moverPeca(tabuleiro, 7, 1, 5, 2); // PC1 move de b8 para c6
    imprimirTabuleiro(tabuleiro);

    // Jogada #3: Dama branca (d1 para h5)
    moverPeca(tabuleiro, 0, 3, 4, 7); // BD move de d1 para h5
    imprimirTabuleiro(tabuleiro);

    // Jogada #3: Cavalo do Rei preto (g8 para f6)
    moverPeca(tabuleiro, 7, 6, 5, 5); // PC2 move de g8 para f6
    imprimirTabuleiro(tabuleiro);

    // Jogada #4: Xeque Mate - Dama branca captura peão em f7 (h5 para f7)
    moverPeca(tabuleiro, 4, 7, 6, 5); // BD move de h5 para f7 (Xeque Mate)
    imprimirTabuleiro(tabuleiro);

    printf("Xeque Mate! Brancas vencem com o Xeque Pastor.\n");

    return 0;
}
