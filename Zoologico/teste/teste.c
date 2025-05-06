#include <stdio.h>
#include "zoologico.h"

// Definição do MinUnit
#define mu_assert(message, test) if (!(test)) { printf("Erro: %s\n", message); return 1; }
#define mu_run_test(test) do { \
    printf("Testando %s...\n", #test); \
    if (test()) return 1; \
} while(0)

// Testes
int test_validos() {
    mu_assert("Erro no teste 1: Criança com 1 bilhete", calcular_preco(10, 1) == 10.0);
    mu_assert("Erro no teste 2: Adulto com 1 bilhete", calcular_preco(30, 1) == 30.0);
    mu_assert("Erro no teste 3: Idoso com 1 bilhete", calcular_preco(65, 1) == 15.0);
    mu_assert("Erro no teste 4: Adulto com 5 bilhetes", calcular_preco(40, 5) == 150.0);
    return 0;
}

int test_invalidos() {
    mu_assert("Erro no teste 1: Quantidade de bilhetes menor que 1", calcular_preco(30, 0) == -1);
    mu_assert("Erro no teste 2: Quantidade de bilhetes maior que 5", calcular_preco(30, 6) == -1);
    mu_assert("Erro no teste 3: Idade negativa", calcular_preco(-1, 1) == -1);
    mu_assert("Erro no teste 4: Idade zero", calcular_preco(0, 1) == -1);
    return 0;
}

// Função para rodar os testes
int main() {
    mu_run_test(test_validos);
    mu_run_test(test_invalidos);
    printf("Todos os testes passaram!\n");
    return 0;
}
