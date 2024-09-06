#include <stdio.h>

#include <stdio.h>

#define TAMANHO 8

// Função para inicializar o tabuleiro com peças e espaços
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO][4]) {
    // Inicializar as peças brancas
    tabuleiro[0][0][0] = 'B'; tabuleiro[0][0][1] = 'T'; tabuleiro[0][0][2] = '1'; tabuleiro[0][0][3] = '\0'; // Torre esquerda
    tabuleiro[0][1][0] = 'B'; tabuleiro[0][1][1] = 'C'; tabuleiro[0][1][2] = '1'; tabuleiro[0][1][3] = '\0'; // Cavalo
    tabuleiro[0][2][0] = 'B'; tabuleiro[0][2][1] = 'B'; tabuleiro[0][2][2] = '1'; tabuleiro[0][2][3] = '\0'; // Bispo
    tabuleiro[0][3][0] = 'B'; tabuleiro[0][3][1] = 'D'; tabuleiro[0][3][2] = '\0';  // Dama
    tabuleiro[0][4][0] = 'B'; tabuleiro[0][4][1] = 'R'; tabuleiro[0][4][2] = '\0';  // Rei
    tabuleiro[0][5][0] = 'B'; tabuleiro[0][5][1] = 'B'; tabuleiro[0][5][2] = '2'; tabuleiro[0][5][3] = '\0'; // Bispo
    tabuleiro[0][6][0] = 'B'; tabuleiro[0][6][1] = 'C'; tabuleiro[0][6][2] = '2'; tabuleiro[0][6][3] = '\0'; // Cavalo
    tabuleiro[0][7][0] = 'B'; tabuleiro[0][7][1] = 'T'; tabuleiro[0][7][2] = '2'; tabuleiro[0][7][3] = '\0'; // Torre direita

    // Inicializar os peões brancos
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[1][i][0] = 'B'; tabuleiro[1][i][1] = 'P'; tabuleiro[1][i][2] = '1' + i; tabuleiro[1][i][3] = '\0';
    }

    // Inicializar os espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j][0] = 'X'; tabuleiro[i][j][1] = '\0';
        }
    }

    // Inicializar os peões pretos
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[6][i][0] = 'P'; tabuleiro[6][i][1] = 'P'; tabuleiro[6][i][2] = '1' + i; tabuleiro[6][i][3] = '\0';
    }

    // Inicializar as peças pretas
    tabuleiro[7][0][0] = 'P'; tabuleiro[7][0][1] = 'T'; tabuleiro[7][0][2] = '1'; tabuleiro[7][0][3] = '\0'; // Torre esquerda
    tabuleiro[7][1][0] = 'P'; tabuleiro[7][1][1] = 'C'; tabuleiro[7][1][2] = '1'; tabuleiro[7][1][3] = '\0'; // Cavalo
    tabuleiro[7][2][0] = 'P'; tabuleiro[7][2][1] = 'B'; tabuleiro[7][2][2] = '1'; tabuleiro[7][2][3] = '\0'; // Bispo
    tabuleiro[7][3][0] = 'P'; tabuleiro[7][3][1] = 'D'; tabuleiro[7][3][2] = '\0';  // Dama
    tabuleiro[7][4][0] = 'P'; tabuleiro[7][4][1] = 'R'; tabuleiro[7][4][2] = '\0';  // Rei
    tabuleiro[7][5][0] = 'P'; tabuleiro[7][5][1] = 'B'; tabuleiro[7][5][2] = '2'; tabuleiro[7][5][3] = '\0'; // Bispo
    tabuleiro[7][6][0] = 'P'; tabuleiro[7][6][1] = 'C'; tabuleiro[7][6][2] = '2'; tabuleiro[7][6][3] = '\0'; // Cavalo
    tabuleiro[7][7][0] = 'P'; tabuleiro[7][7][1] = 'T'; tabuleiro[7][7][2] = '2'; tabuleiro[7][7][3] = '\0'; // Torre direita
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO][4]) {
    printf("   a    b    c    d    e    f    g    h\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", 8 - i);  // Exibir número da fileira
        for (int j = 0; j < TAMANHO; j++) {
            printf("%-4s ", tabuleiro[i][j]);
        }
        printf("%d\n", 8 - i);  // Exibir número da fileira no final
    }
    printf("   a    b    c    d    e    f    g    h\n");
}

int main() {
    // Definir o tabuleiro
    char tabuleiro[TAMANHO][TAMANHO][4];

    // Inicializar o tabuleiro com as peças
    inicializarTabuleiro(tabuleiro);

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
