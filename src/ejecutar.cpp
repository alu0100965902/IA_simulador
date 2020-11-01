#include "../include/ejecutar.hpp"

void ejecutar::crear_entorno(int m, int n) {
  entorno tmp(m,n);
  entorno_ = tmp; 
}

void ejecutar::pedir_ocupadas(int x, int y) {
  entorno_.set_ocupada(x, y); 
}

void ejecutar::ocupadas_aleatorias(int num) {
  srand(0);

  for(int i = 0; i < num; i++) {
    int aux_x = rand() % entorno_.numero_col();
    int aux_y = rand() % entorno_.numero_filas();
    if (aux_x != entorno_.get_pos_inicial().first && aux_y != entorno_.get_pos_inicial().second
        || aux_x != entorno_.get_pos_final().first && aux_y != entorno_.get_pos_final().second) {
      entorno_.set_ocupada(aux_x, aux_y);
        }
    else {
      i--;
    }
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

void ejecutar::mostrar_entorno() {
  entorno_.mostrar_malla();
}