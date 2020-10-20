#include <iostream>
#pragma once
using namespace std;

class celda {
  private:
    int x;
    int y;
    bool ocupada;
  public:
    celda(){
      ocupada = false;
    }
    celda(int x_, int y_){
      x = x_;
      y = y_;
    }
    celda(int x_, int y_, bool ocupada_) {
      x = x_;
      y = y_;
      ocupada = ocupada_;
    }
    ~celda(){
    }
    int get_x();
    int get_y();
    int set_x();
    int set_y();
    int set_pos(int x, int y);
    bool comprobar_ocupada();
    void ocupar();
    friend ostream& operator<< (ostream& os, const celda& celda_);
};