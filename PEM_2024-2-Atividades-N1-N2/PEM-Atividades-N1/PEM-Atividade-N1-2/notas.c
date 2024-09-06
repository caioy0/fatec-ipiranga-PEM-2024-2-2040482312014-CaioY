#include <stdio.h>
#include <stdlib.h>

// Função para ler as notas do candidato
void lerNotas(float *notas, int N) {
    for (int i = 0; i < N; i++) {
        while (1) {
            printf("Insira a nota %d (0.0 a 10.0): ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] >= 0.0 && notas[i] <= 10.0) {
                break;
            } else {
                printf("Nota inválida! Tente novamente.\n");
            }
        }
    }
}

// Função para calcular a nota final de um teste, excluindo a maior e a menor nota
float calcularNotaFinal(float *notas, int N) {
    float min = notas[0], max = notas[0], soma = 0;
    int i;

    // Encontrar a maior e a menor nota
    for (i = 0; i < N; i++) {
        if (notas[i] < min) min = notas[i];
        if (notas[i] > max) max = notas[i];
        soma += notas[i];  // Somar todas as notas
    }

    // Subtrair a menor e a maior nota da soma total
    soma -= min;
    soma -= max;

    return soma;
}

int main() {
    int N;
    float totalGeral = 0;
    int numTestes = 0;

    while (1) {
        printf("\nQuantas notas serão inseridas (N > 2, 0 para encerrar): ");
        scanf("%d", &N);

        if (N == 0) {
            break;
        } else if (N <= 2) {
            printf("O número de notas deve ser maior que 2. Tente novamente.\n");
            continue;
        }

        // Alocar dinamicamente o vetor de notas
        float *notas = (float *)malloc(N * sizeof(float));
        if (notas == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        // Ler as notas
        lerNotas(notas, N);

        // Calcular a nota final do teste
        float notaFinal = calcularNotaFinal(notas, N);
        totalGeral += notaFinal;
        numTestes++;

        // Exibir o resultado do teste
        printf("Nota final do teste %d = %.2f\n", numTestes, notaFinal);

        // Liberar a memória alocada
        free(notas);
    }

    // Exibir a nota final do candidato
    printf("\nNota final do candidato = %.2f\n", totalGeral);

    return 0;
}
