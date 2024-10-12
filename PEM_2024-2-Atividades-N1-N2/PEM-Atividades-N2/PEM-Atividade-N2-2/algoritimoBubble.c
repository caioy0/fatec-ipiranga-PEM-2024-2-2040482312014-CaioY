/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Exercicio do bubbleSort           *
* Data - 04/10/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

// Função para o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array fornecido para a medição
    int arr[] = {5, 3, 8, 4, 2,
                 115, 113, 118, 114, 112,
                 125, 123, 128, 124, 122,
                 35, 33, 38, 34, 32,
                 45, 43, 48, 44, 42,
                 55, 53, 58, 54, 52,
                 65, 63, 68, 64, 62,
                 75, 73, 78, 74, 72,
                 85, 83, 88, 84, 82,
                 95, 93, 98, 94, 92,
                 15, 13, 18, 14, 12,
                 25, 23, 28, 24, 22};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Início da medição de tempo

    // Ordena o array usando Bubble Sort
    bubbleSort(arr, n);

    end = clock(); // Fim da medição de tempo

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado:\n");
    printArray(arr, n);

    // Exibe o tempo de execução
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
