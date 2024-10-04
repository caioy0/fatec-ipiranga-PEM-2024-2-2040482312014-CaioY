/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Exercicio do bubbleSort           *
* Data - 04/10/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>

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

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertNum(int arr[], int size){
    int i;
    printf("Digite os numeros: ");
        for (i=0; i <5; i++){
        scanf("%d",&arr[i]);
    }
}

int main() {
    int arr[] = {0, 0, 0, 0, 0}; //5, 3, 8, 4, 2
    int n = sizeof(arr)/sizeof(arr[0]);
    insertNum(arr, n);
    printf("Array original: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
