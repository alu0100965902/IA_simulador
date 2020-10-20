#include <iostream>
#include <vector>
#include "celda.hpp"
using namespace std;

class coche {
  private:
    vector <celda> celdasProximas;
    int posx_;
    int posy_;

  public:
    coche() {
    }
    ~coche() {
    }
    int get_x();
    int get_y();
    int set_x(int x);
    int set_y(int y);
};