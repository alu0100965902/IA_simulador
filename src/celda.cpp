#include "../include/celda.hpp"

ostream& operator<< (ostream& os, const celda& celda_) {
  if (celda_.ocupada)
    os << "|X|";
  else
    os << "| |";
  return os;
}