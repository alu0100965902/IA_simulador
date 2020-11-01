#include "entorno.hpp"

using namespace std;

class ejecutar {
  private:
  entorno entorno_;

  public:
    ejecutar() {
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
      cout << entorno_.distancia_linea_recta(0,0) << endl;
    }
};