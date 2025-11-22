#include<stdio.h>

int main() {

    int n;

    printf("Digite o numero de processos: ");
    scanf("%d", &n);


    int processo[n], execucao[n], espera[n], chegada[n];

    // Entrada dos tempos de execucao de cada processo
    for (int i = 0; i < n; i++) {
        processo[i] = i + 1;  // define o número do processo
        printf("Digite o tempo de execucao do processo P%d: ", i + 1);
        scanf("%d", &execucao[i]);
    }

    // Ordenação pelo menor execucao
    // Implementação do SJF
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            // Se a execucao atual for maior que a próxima, troca a ordem
            if (execucao[j] > execucao[j + 1]) {

                // Troca os tempos de execucao
                int temp = execucao[j];
                execucao[j] = execucao[j + 1];
                execucao[j + 1] = temp;

                // Troca também a ordem dos processos para acompanhar a execucao
                temp = processo[j];
                processo[j] = processo[j + 1];
                processo[j + 1] = temp;
            }
        }
    }

    // Cálculo do tempo de espera
    // Primeiro processo nunca espera → sempre 0
    espera[0] = 0;

    // Cada processo seguinte espera pelo tempo total dos anteriores
    for (int i = 1; i < n; i++) {
        espera[i] = espera[i - 1] + execucao[i - 1];
        // espera[1] = execucao[0]
        // espera[2] = execucao[0] + execucao[1]
    }

    // Cálculo do tempo de chegada:
    // chegada = espera + execucao
    for (int i = 0; i < n; i++) {
        chegada[i] = espera[i] + execucao[i];
    }
    // Exibe os valores já ordenados pelo SJF
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\n",processo[i], execucao[i], espera[i], chegada[i]);
    }

    return 0;
}
