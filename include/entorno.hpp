#include "coche.hpp"
#include "celda.hpp"
#include <vector>
#include <utility> 
using namespace std;

class entorno {
  private:
    pair <int, int> puntoInicial;
    pair <int, int> puntoFinal;
    vector <vector <celda>> malla;
    coche coche_;
  public:
    entorno() { 
    }
    entorno(int nFilas, int nColumnas) {
      malla.resize(nFilas);
      for (int i = 0; i <= nFilas; i++) {
        malla[i].resize(nColumnas);
        for (int j = 0; j < malla[i].size(); j++) {
          malla[i][j].set_pos(i, j);
        }
      }
    }
    ~entorno() {
    }
    void set_ocupada(int x, int y);
    void mostrar_malla();
};