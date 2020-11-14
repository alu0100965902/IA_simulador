#include "coche.hpp"
#include "celda.hpp"
#include "nodo.hpp"
#include <vector>
#include <utility>
#include <stdlib.h> 
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

    entorno(int nFilas, int nColumnas):
            puntoInicial_(-1, -1),
            puntoFinal_(-1, -1) {
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
    int numero_col();
    int numero_filas();
    void set_ocupada(int x, int y);
    void mostrar_malla();
    void posi_coche(int x, int y);
    void set_pos_inicial(int x, int y);
    void set_pos_final(int x, int y);
    pair <int, int> get_pos_inicial();
    pair <int, int> get_pos_final();
    coche get_pos_coche();
    int distancia_linea_recta(int x, int y);
    int distancia_rectilinea(int x, int y);
    void siguiente_posicion();
    int distancia_manhattan(nodo* nodo_coche);
    void mover_coche(int x, int y);

    class CRow {
        friend class entorno;
    public:
        celda& operator[](int col) {
            return parent.malla_[row][col];
        }
    private:
        CRow(entorno &parent_, int row_) : 
            parent(parent_),
            row(row_){
         }

        entorno& parent;
        int row;
    };

    CRow operator[](int row) {
      return CRow(*this, row);
    }

};