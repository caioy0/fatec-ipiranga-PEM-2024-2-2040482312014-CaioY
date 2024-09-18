#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 4

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nOverflow!!\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("\nUnderflow!!\n");
        return 0; // Retorna 0 se a pilha estiver vazia
    } else {
        return stack[top--];
    }
}

void show() {
    if (top == -1) {
        printf("\nPilha vazia!!\n");
    } else {
        printf("\nElementos na pilha:\n");
        for (int i = top; i >= 0; --i) {
            printf("%d\n", stack[i]);
        }
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(int a, int b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; // Divisão por zero
        default: return 0;
    }
}

int validateInput(char *input) {
    int operandCount = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            operandCount++;
        } else if (isOperator(input[i])) {
            if (operandCount < 2) {
                return 0; // Não há operandos suficientes
            }
            operandCount--; // Reduz o número de operandos
        }
    }
    return operandCount == 1; // Deve haver um único resultado final
}

void processRPN(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else if (isOperator(token[0])) {
            int b = pop();
            int a = pop();
            int result = calculate(a, b, token[0]);
            push(result);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[100];
    int continuar;

    do {
        printf("Digite a expressão RPN (max 4 operandos seguidos de um operador): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove a nova linha

        if (!validateInput(input)) {
            printf("Entrada inválida! Verifique a expressão.\n");
            continue;
        }

        processRPN(input);
        printf("Resultado: %d\n", stack[top]);

        printf("Deseja fazer nova entrada? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        getchar(); // Para limpar o buffer do stdin

    } while (continuar);
    return 0;
}
