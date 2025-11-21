#include <stdio.h>

// Estrutura que armazena os dados de cada processo
struct Process {
    int id;        // Número identificador do processo
    int burst;     // Tempo necessário para execução completa
    int priority;  // Prioridade do processo (valores menores indicam maior prioridade)
};

// Função responsável por ordenar os processos com base na prioridade
// O processo com menor valor de prioridade é posicionado primeiro
void sortByPriority(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].priority < p[i].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Quantos processos deseja inserir? ");
    scanf("%d", &n);

    struct Process p[n];  // Vetor que armazena todos os processos

    // Coleta das informações de cada processo
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;  // Define o identificador do processo

        printf("Digite o Burst Time do processo %d: ", p[i].id);
        scanf("%d", &p[i].burst);

        printf("Digite a prioridade do processo %d (menor = maior prioridade): ", p[i].id);
        scanf("%d", &p[i].priority);
    }

    // Ordenação dos processos conforme a prioridade informada
    sortByPriority(p, n);

    int waitingTime = 0;       // Tempo de espera individual do processo atual
    int turnaroundTime = 0;    // Tempo total até a finalização do processo
    int totalWT = 0;           // Acumulador para cálculo da média de espera
    int totalTAT = 0;          // Acumulador para cálculo da média de turnaround

    printf("\n=== Resultado do Priority Scheduling ===\n");
    printf("Processo\tBurst\tPrioridade\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        waitingTime = totalWT;                 // O tempo de espera corresponde ao tempo já utilizado pelos anteriores
        turnaroundTime = waitingTime + p[i].burst; // Soma do tempo de espera com o burst do processo

        totalWT += p[i].burst;                 // Atualiza o acumulador do tempo total de execução já realizado
        totalTAT += turnaroundTime;            // Soma o turnaround atual ao total

        printf("P%d\t\t%d\t%d\t\t%d\t%d\n",
               p[i].id, p[i].burst, p[i].priority, waitingTime, turnaroundTime);
    }

    // Cálculo e exibição das médias dos tempos
    printf("\nTempo médio de espera: %.2f\n", (float)totalWT / n);
    printf("Tempo médio de turnaround: %.2f\n", (float)totalTAT / n);

    return 0;
}
