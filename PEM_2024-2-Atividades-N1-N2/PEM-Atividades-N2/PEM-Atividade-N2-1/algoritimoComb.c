/*--------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*-------------------------------------------------------- *
* Objetivo do Programa: Código alternativo ao bubbleSort  *
* Data - 04/10/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>
//calcular distancia entre um numero e outro
int proximoGap(int gap) {
    gap = (gap * 10) / 13;
    return (gap < 1) ? 1 : gap;
}
//algoritmo
void combSort(float a[], int n) {
    int gap = n;
    int id = 1;
    while (gap != 1 || id == 1) {
        gap = proximoGap(gap);
        id = 0;

        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                float temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                id = 1;
            }
        }
    }
}
//mostra array original
void printArray(float a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}
//entrada de numeros
int insertNum(float a[], int size) {
    printf("Insira um numero: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%f", &a[i]) != 1) { // Verifica se a entrada é válida
            printf("Entrada inválida! Tente novamente, utilize números.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            i--; 
        }
    }
    return 0; 
}
//main
int main() {
    float a[10]; 
    int n = sizeof(a) / sizeof(a[0]);
    insertNum(a, n); 
    printf("Array original: \n");
    printArray(a, n);
    combSort(a, n);
    printf("Array ordenado: \n");
    printArray(a, n);
    return 0;
}


/* diferenca entre os codigos, esse codigo o array suporta gapes do tipo float e o dobro de numeros.
ao inves de bubbleSort utilizei o combSort como algoritmo.
verifica entrada dos numeros.
essas foram as melhorias entre o codigo e outro
*/