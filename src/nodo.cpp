#include "../include/nodo.hpp"

nodo* nodo::get_anterior() {
  return nodo_anterior;
}

pair <int, int> nodo::get_pos() {
  return pos;
}