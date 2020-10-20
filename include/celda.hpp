#include <iostream>
#pragma once
using namespace std;

class celda {
  private:
    int x_;
    int y_;
    bool ocupada_;

  public:
    celda(){
      ocupada_ = false;
    }
    celda(int x, int y) {
      x_ = x;
      y_ = y;
    }
    celda(int x, int y, bool ocupada) {
      x_ = x;
      y_ = y;
      ocupada_ = ocupada;
    }
    ~celda() {
    }
    int get_x();
    int get_y();
    int set_x(int x);
    int set_y(int y);
    int set_pos(int x, int y);
    bool comprobar_ocupada();
    void ocupar();
    friend ostream& operator<< (ostream& os, const celda& celda_);
};