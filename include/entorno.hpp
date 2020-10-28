#include "coche.hpp"
#include "celda.hpp"
#include <vector>
#include <utility> 
using namespace std;

class entorno {
  private:
    pair <int, int> puntoInicial_;
    pair <int, int> puntoFinal_;
    vector <vector <celda>> malla_;
    coche coche_;

  public:
    entorno() { 
    }

    entorno(int nFilas, int nColumnas) {
      malla_.resize(nFilas);
      cout<< nFilas << endl;
      for (int i = 0; i < nFilas; i++) {
        malla_[i].resize(nColumnas);
        for (int j = 0; j < malla_[i].size(); j++) {
          malla_[i][j].set_pos(i, j);
        }
      }
    }

    ~entorno() {
    }
    void set_ocupada(int x, int y);
    void mostrar_malla();
    void posi_coche(int x, int y);
    void set_pos_inicial(int x, int y);
    void set_pos_final(int x, int y);
};