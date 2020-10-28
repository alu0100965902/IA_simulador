#include "../include/ejecutar.hpp"

void ejecutar::crear_entorno(int m, int n) {
  entorno tmp(m,n);
  entorno_ = tmp; 
  entorno_.mostrar_malla();
}

void ejecutar::pedir_ocupadas(int x, int y) {
  entorno_.set_ocupada(x, y); 
}

void ejecutar::ocupadas_aleatorias(int num) {
  srand(0);
  int numeroOcupadas = rand() % num;
  for(int i = 0; i < numeroOcupadas; i++) {
    entorno_.set_ocupada(rand(), rand());
  }
}

void ejecutar::pos_coche(int x, int y) {
  entorno_.posi_coche(x, y); 
}

void ejecutar::pos_inicial(int x, int y) {
  entorno_.set_pos_inicial(x, y); 
}

void ejecutar::pos_final(int x, int y) {
  entorno_.set_pos_final(x, y);
}
