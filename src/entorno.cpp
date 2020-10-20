#include "../include/entorno.hpp"

void entorno::set_ocupada(int x, int y) {
  malla[x][y].ocupar();
}
void entorno::mostrar_malla() {
  for (int i = 0; i < malla.size(); i++) {
    for (int j = 0; j < malla[i].size(); j++) {
      cout << malla[i][j];
    }
    cout << endl;
  }
}