#include <iostream>
#pragma once
using namespace std;

class celda {
  private:
    int x_;
    int y_;
    bool ocupada_;
    bool paso_coche;
  public:
    celda(){
      ocupada_ = false;
      paso_coche = false;
    }
    celda(int x, int y) {
      x_ = x;
      y_ = y;
      paso_coche = false;
    }
    celda(int x, int y, bool ocupada) {
      x_ = x;
      y_ = y;
      ocupada_ = ocupada;
      paso_coche = false;
    }
    ~celda() {
    }
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    void set_pos(int x, int y);
    bool comprobar_ocupada();
    void ocupar();
    void pasoCoche();
    bool comprobar_coche();
    friend ostream& operator<< (ostream& os, const celda& celda_);
};