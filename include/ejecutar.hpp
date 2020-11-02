#include "entorno.hpp"
#include "coche.hpp"
#include <vector>
#include <utility>

using namespace std;

class ejecutar {
  private:
  entorno entorno_;
  vector < pair <pair <int, int>, pair <int, int>>> vectorPosiblesCaminos;
  public:
    ejecutar() {
      vectorPosiblesCaminos.resize(0);
    }
    ~ejecutar() {
    }
    void crear_entorno(int m, int n);
    void pedir_ocupadas(int x, int y);
    void ocupadas_aleatorias(int num);
    void pos_coche(int x, int y);
    void pos_inicial(int x, int y);
    void pos_final(int x, int y);
    void mostrar_entorno();
    void prueba() {
      cout << entorno_.distancia_linea_recta(0, 0) << endl;
      cout << entorno_.distancia_rectilinea(0, 0) << endl;
      cout << entorno_[2][2] << endl;
    }
    void heuristico();
};