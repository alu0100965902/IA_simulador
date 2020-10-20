#include "../include/entorno.hpp"

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