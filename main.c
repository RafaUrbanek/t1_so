#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include "barrier.h"

// Função main que cria os N processos filhos passados na linha de execução
int main (int argc, char *argv[]) {
    int nChildrenProcs, nProc;
    pid_t pid;

    if (argc != 2) {
        printf("Argumentos incorretos, modo de uso: ./main <n° processos filhos>\n");
        exit(0);
    } else if (atoi(argv[1]) <= 0) {
        printf("Número de processos filhos deve ser maior que 0\n");
        exit(0);
    }

    nChildrenProcs = atoi(argv[1]);     // Número de processos filhos
    nProc = 0;                          // Número lógico do processo pai

    for (int i = 1; i <= nChildrenProcs; i++) {
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Erro ao criar processo\n");
            return 1;
        }

        if (pid == 0) {
            // Este bloco só é executado pelos FILHOS
            nProc = i; // Define o número lógico do filho
            break;
        }
    }

    printf("Sou o processo lógico %d (PID: %d, Pai: %d)\n", nProc, getpid(), getppid());

    if (nProc == 0) {
        // Apenas o PAI deve esperar os filhos terminarem
        for (int i = 1; i <= nChildrenProcs; i++) {
            int status;
            pid_t child_pid = wait(&status);
            printf("+++ Filho de número lógico (precisa mapear) e pid %d terminou!\n", child_pid);
        }
    }

    return 0;
}