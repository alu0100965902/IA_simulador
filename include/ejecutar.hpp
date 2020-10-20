#include "entorno.hpp"

using namespace std;

class ejecutar{
  private:
  entorno entorno_;
  public:
    ejecutar() {
    }
    ~ejecutar() {
    }
    void pedir_ocupadas(int x, int y);
    void ocupadas_aleatorias();
};