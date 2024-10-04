/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Calculadora baseada em formula RPN *
* Data - 20/09/2024                                       * 
* Autores: Caio Yugo Saeda Uemura                         *
*--------------------------------------------------------*/

#include <stdio.h>     
#include <stdlib.h>    // funções de alocação de memória e conversões (atoi)
#include <string.h>    // manipulação de strings
#include <ctype.h>     // funções de verificação de caracteres (isdigit)

#define TAMANHO_PILHA 4 // Tamanho da pilha, representando a memória da HP12C (X, Y, Z, T)

int stack[TAMANHO_PILHA], top = -1; // Declaração da pilha e do índice do topo

// Função para adicionar um valor no topo da pilha
void push(int value) { 
    stack[++top] = value; 
}

// Função para remover e retornar o valor do topo da pilha
int pop() { 
    return stack[top--]; 
}

// Função que verifica se um caractere é um operador aritmético
int isOperator(char c) { 
    return c == '+' || c == '-' || c == '*' || c == '/'; 
}
//Retorna 1 se c for um operador; 0 caso contrário.

//função para realizar cálculos
int calcular(int a, int b, char op) {
    if (op == '/' && b == 0) { 
        printf("Erro: Divisão por zero!\n"); //especialmente -> erro para divisão por zero
        return 0; 
    }
    // Retorna o resultado da operação conforme o operador
    return op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : a / b; 
}

//função para validar expressões em RPN
int validarRPN(char *input) { 
    int contarNumeros = 0; // Inicializa contador de números
    for (int i = 0; input[i]; i++) { // Loop para verificar cada caractere
        if (isdigit(input[i])) 
            contarNumeros++; // Incrementa ao encontrar um número
        
        // Verifica se há números suficientes para o operador
        else if (isOperator(input[i]) && --contarNumeros < 1) 
            return 0; // Retorna 0 se não houver operandos suficientes
    }
    return contarNumeros == 1; // Retorna 1 se for válida (apenas um resultado final)
}
/*
Percorre a string, incrementando o contador para números e decrementando para operadores.
A função valida a expressão conforme as regras da RPN.
*/

void processRPN(char *input) { // Função para processar a expressão RPN
    for (char *token = strtok(input, " "); // Divide a string em tokens
         token; token = strtok(NULL, " ")) { // Loop enquanto houver tokens
        // Usa operador ternário para empilhar números ou calcular com operadores
        isdigit(token[0]) ? push(atoi(token)) : 
        push(calcular(pop(), pop(), token[0]));  
    }
    printf("Resultado: %d\n", stack[top]); // Mostra o resultado
}
//O loop usa strtok para separar a entrada em partes e decide o que fazer com cada token.

int main() { 
    char input[100]; 
    int continuar; //variável de controle do loop
    do {
        memset(input, 0, sizeof(input)); //Limpar o array inteiro com 0 --> esse aqui muito bom.
        printf("Digite a expressão RPN (max 4 operandos): ");
        fgets(input, sizeof(input), stdin); //lê a linha de entrada
        input[strcspn(input, "\n")] = 0; //remove a nova linha do final
        //validar a entrada 
        if (!validarRPN(input)) //chama o validarRPN
            printf("Entrada inválida! Verifique a expressão.\n");
        else 
            processRPN(input); //vai ao calculo
        
        printf("Deseja fazer nova entrada? (1 - Sim, 0 - Não): "); 
        scanf("%d", &continuar); // Lê a resposta do usuário
        getchar(); // Limpa o buffer
    } while (continuar); // Continua enquanto o usuário desejar
    printf("Obrigado por usar nossa Calculador Fatec-HP12c"); 
    return 0; // Retorna 0 ao final da execução
}

/*
fgets(input, sizeof(input), stdin):
Lê uma linha de texto da entrada padrão e a armazena em input.
Garante que não haja estouro de buffer, limitando a leitura ao tamanho do array.

A função strcspn calcula o índice do primeiro caractere em input que coincide com qualquer caractere presente na string fornecida como segundo argumento, 
que neste caso é "\n".

O operador ! é usado para inverter o valor retornado pela função.
Portanto, se validarRPN(input) retornar 1 (verdadeiro), !validarRPN(input) se tornará 0 (falso).
E se validarRPN(input) retornar 0 (falso), !validarRPN(input) se tornará 1 (verdadeiro).
*/
