#include <stdio.h>
#include "zoologico.h"  // Inclui o arquivo de cabeçalho

// Implementação da função calcular_preco
float calcular_preco(int idade, int quantidade) {
    if (quantidade < 1 || quantidade > 5) {
        printf("Erro: A quantidade de bilhetes deve estar entre 1 e 5. Você inseriu: %d\n", quantidade);
        return -1;  // Retorno indicando erro
    }

    float preco_unitario;

    if (idade <= 12) {
        preco_unitario = 10.0; // Criança
    } else if (idade >= 13 && idade <= 59) {
        preco_unitario = 30.0; // Adulto
    } else {
        preco_unitario = 15.0; // Idoso
    }

    return preco_unitario * quantidade;
}

// Função principal do programa
int main() {
    int idade, quantidade;
    printf("Informe sua idade: ");
    if (scanf("%d", &idade) != 1 || idade <= 0) {
        printf("Erro: Idade inválida. Por favor, insira um número maior que 0.\n");
        return 1; // Código de erro
    }

    printf("Informe a quantidade de bilhetes: ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Erro: Quantidade inválida. Por favor, insira um número maior que 0.\n");
        return 1; // Código de erro
    }

    float preco_total = calcular_preco(idade, quantidade);

    if (preco_total == -1) {
        printf("Não foi possível calcular o preço devido a um erro.\n");
        return 1; // Código de erro
    }

    printf("Preço total: R$ %.2f\n", preco_total);

    return 0;
}
