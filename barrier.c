#include "barrier.h"

void init_barr( barrier_t *barr, int n ){

  /*  onde: barr deve apontar para a barreira em shared memory
      que deve ser uma struct definida por voce
      com tipo barrier_t (ver ao final, abaixo)
      n deve indicar o numero total de processos
      (lidos da linha de comando)
  */

}

void process_barrier( barrier_t *barr ){
  
  /*  onde: barr deve apontar para a barreira em shared memory 
      Ao chamar process_barrier cada processo deve esperar pelos outros
      em um semaforo do SO colocado na barreira para possibilitar tal espera.
      O último processo a chamar a função process_barrier deve 
      liberar todos os outros da espera no semaforo da barreira.
  */

}