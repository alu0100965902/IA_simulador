#include "../include/celda.hpp"

int celda::get_x() {
  return x_;
}

int celda::get_y() {
  return y_;
}

int celda::set_x(int x) {
  x_ = x;
}

int celda::set_y(int y) {
  y_ = y;
}

int celda::set_pos(int x, int y) {
  x_ = x;
  y_ = y;
}

bool celda::comprobar_ocupada() {
  if(ocupada_) 
    return true;
    
  return false;
}

void celda::ocupar() {
}

ostream& operator<< (ostream& os, const celda& celda_) {
  if (celda_.ocupada_)
    os << "|X|";

  else
    os << "| |";
  return os;
}