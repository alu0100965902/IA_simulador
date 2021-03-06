#include "entorno.hpp"
#include "coche.hpp"
#include "nodo.hpp"
#include <vector>
#include <utility>
#include <chrono>

using namespace std;

class ejecutar {
  private:
  entorno entorno_;
  vector < pair <nodo*, pair <int, int>>> vectorPosiblesCaminos;
  public:
    ejecutar() {
      vectorPosiblesCaminos.resize(0);
    }
    ~ejecutar() {}
    void crear_entorno(int m, int n);
    void pedir_ocupadas(int x, int y);
    void ocupadas_aleatorias(int num);
    void pos_coche(int x, int y);
    void pos_inicial(int x, int y);
    void pos_final(int x, int y);
    void mostrar_entorno();
    void heuristico();
    void heuristico_manhattan();
};