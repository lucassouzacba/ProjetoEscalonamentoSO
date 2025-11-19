#include <stdio.h>

int main() {
    int n;

    printf("Quantidade de processos: ");
    scanf("%d", &n);

    int execucao[50];      // tempos de execução (burst)
    int espera[50];    // tempos de espera
    int retorno[50]; // tempos de retorno

    // Entrada dos tempos de execução
    for (int i = 0; i < n; i++) {
        printf("Tempo de execução do processo %d: ", i + 1);
        scanf("%d", &execucao[i]);
    }

    // Cálculo do tempo de espera
    espera[0] = 0; // primeiro processo não espera
    for (int i = 1; i < n; i++) {
        espera[i] = espera[i - 1] + execucao[i - 1];
    }

    // Cálculo do tempo de retorno
    for (int i = 0; i < n; i++) {
        retorno[i] = espera[i] + execucao[i];
    }

    // Resultado
    printf("\n--- Algoritmo FCFS ---\n");
    printf("Proc | Execução | Espera | Retorno\n");

    for (int i = 0; i < n; i++) {
        printf(" %3d |  %4d |   %4d |   %4d\n",
               i + 1, execucao[i], espera[i], retorno[i]);
    }

    return 0;
}