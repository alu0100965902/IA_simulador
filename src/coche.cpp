#include "../include/coche.hpp"

int coche::get_x() {
  return posx_;
}

int coche::get_y() {
  return posy_;
}

int coche::set_x(int x) {
  posx_ = x;
}

int coche::set_y(int y) {
  posy_ = y;
}