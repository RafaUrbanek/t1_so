#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados da barreira
typedef struct barrier_s {
    int shared_memory_addres;       // Endereço da memória compartilhada
    int childrens_processes [];     // Lista com os identificadores dos processos filhos
    
    // definir aqui o que vai na struct
      // podendo usar semaforo do SO
      // e outras variaveis necessarias
      
} barrier_t; 

// Função responsável por incializar a barreira
void init_barrier( barrier_t *barrier, int n );

// Função responsável por processar a barreira
void process_barrier( barrier_t *barrier );
