#include <vector>
#include <utility> 
#pragma once
using namespace std;

class nodo {
  private:
    nodo* nodo_anterior;
    pair <int, int> pos;
  public:
  nodo (int x, int y, nodo* anterior) {
    pos.first = x;
    pos.second = y;
    nodo_anterior = anterior;
  }
  ~nodo(){
  }
  nodo* get_anterior();
  pair <int, int> get_pos();
  friend bool operator==(const nodo& nodo_1, const nodo& nodo_2);
};