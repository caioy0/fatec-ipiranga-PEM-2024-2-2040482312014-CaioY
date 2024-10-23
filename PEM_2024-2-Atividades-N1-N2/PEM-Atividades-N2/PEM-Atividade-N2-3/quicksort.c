/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: QuickSort                         *
* Data - 17/10/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>

// Função que realiza a troca entre dois elementos
void troca(int arr[], int i, int j) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

// Função que realiza a partição e retorna o índice do pivô
int particao(int arr[], int limInf, int limSup) {
    int pivo = arr[limSup]; // O pivô é o último elemento
    int pivo_indice = limInf; // Índice do pivô inicial

    for (int i = limInf; i < limSup; i++) {
        // Verifica se o elemento é <= ao pivô
        if (arr[i] <= pivo) {
            // Realiza a troca
            troca(arr, i, pivo_indice);
            // Incrementa o pivo_indice
            pivo_indice++;
        }
    }

    // Troca o pivô
    troca(arr, pivo_indice, limSup);

    // Retorna o índice do pivô
    return pivo_indice;
}

// Função que implementa o algoritmo QuickSort
void quickSort(int arr[], int limInf, int limSup) {
    if (limInf < limSup) {
        // Realiza a partição e obtém o índice do pivô
        int pivo_indice = particao(arr, limInf, limSup);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, limInf, pivo_indice - 1);
        quickSort(arr, pivo_indice + 1, limSup);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("MEM: 0x%X, arr[%d] : %d\n", (unsigned int)(int *)&arr[i], i, arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf("Array original:\n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}