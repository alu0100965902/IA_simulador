#include <iostream>
#include <vector>
#include "celda.hpp"
using namespace std;

class coche {
  private:
    vector <celda> celdasProximas;
    int posx;
    int posy;
  public:
    coche(){
    }
    ~coche(){
    }
    int get_x();
    int get_y();
    int set_x();
    int set_y();
};