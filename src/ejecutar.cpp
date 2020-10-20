#include "../include/ejecutar.hpp"

void ejecutar::pedir_ocupadas(int x, int y) {
  entorno_.set_ocupada(x, y); 
}

void ejecutar::ocupadas_aleatorias() {
  srand(0);
  int numeroOcupadas = rand();
  for(int i = 0; i < numeroOcupadas; i++) {
    entorno_.set_ocupada(rand(), rand());
  }
}
