#include "../include/coche.hpp"

int coche::get_x() {
  return posx_;
}

int coche::get_y() {
  return posy_;
}

void coche::set_x(int x) {
  posx_ = x;
}

void coche::set_y(int y) {
  posy_ = y;
}