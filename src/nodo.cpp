#include "../include/nodo.hpp"

nodo* nodo::get_anterior() {
  return nodo_anterior;
}

pair <int, int> nodo::get_pos() {
  return pos;
}

bool operator==(const nodo& nodo_1, const nodo& nodo_2) {
  if (nodo_1.pos.first == nodo_2.pos.first && nodo_1.pos.second == nodo_2.pos.second) {
    return true;
  } 
  else {
    return false;  
  }
}
