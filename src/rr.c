#include <stdio.h>

int main() {
    int n, quantum;

    printf("Quantidade de processos: ");
    scanf("%d", &n);

    int bt[n], rem_bt[n], wt[n], tat[n];

    // Entrada dos tempos de execução
    for (int i = 0; i < n; i++) {
        printf("Tempo de execucao do processo P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Tempo restante inicialmente é o burst time
    }

    printf("Informe o quantum: ");
    scanf("%d", &quantum);

    int tempo = 0; // tempo atual do sistema

    printf("\nOrdem de Execucao (Round Robin):\n");

    // Round Robin
    while (1) {
        int processos_finalizados = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                processos_finalizados = 0; // ainda há processos a executar

                printf("P%d executa de %d ate %d\n", i + 1, tempo, tempo + (rem_bt[i] < quantum ? rem_bt[i] : quantum));

                if (rem_bt[i] > quantum) {
                    tempo += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    tempo += rem_bt[i];
                    wt[i] = tempo - bt[i]; // tempo de espera
                    rem_bt[i] = 0;
                }
            }
        }

        if (processos_finalizados == 1)
            break;
    }

    // Cálculo do Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nResultados Finais:\n");
    printf("Processo   Burst   Espera   Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t   %d\t   %d\t      %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
