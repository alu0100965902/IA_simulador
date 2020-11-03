#include "../include/celda.hpp"

int celda::get_x() {
  return x_;
}

int celda::get_y() {
  return y_;
}

void celda::set_x(int x) {
  x_ = x;
}

void celda::set_y(int y) {
  y_ = y;
}

void celda::set_pos(int x, int y) {
  x_ = x;
  y_ = y;
}

bool celda::comprobar_ocupada() {
  if(ocupada_) 
    return true;
    
  return false;
}

void celda::ocupar() {
  ocupada_ = true;
}

void celda::pasoCoche() {
  paso_coche = true;
}

bool celda::comprobar_coche() {
  return paso_coche;
}

ostream& operator<< (ostream& os, const celda& celda_) {
  if (celda_.ocupada_)
    os << "|\e[96mX\e[0m|";
  else
    os << "| |";
  return os;
}