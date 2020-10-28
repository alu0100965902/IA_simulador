#include "../include/entorno.hpp"

void entorno::set_pos_inicial(int x, int y){
  puntoInicial_.first = x;
  puntoInicial_.second = y;
}

void entorno::set_pos_final(int x, int y){
  puntoFinal_.first = x;
  puntoFinal_.second = y;
}

void entorno::posi_coche(int x, int y) {
  coche_.set_x(x);
  coche_.set_y(y);
}

void entorno::set_ocupada(int x, int y) {
  malla_[x][y].ocupar();
}

void entorno::mostrar_malla() {
  for (int i = 0; i < malla_.size(); i++) {
    for (int j = 0; j < malla_[i].size(); j++) {
      cout << malla_[i][j];
    }
    cout << endl;
  }
}