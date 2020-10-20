#include <iostream>
#include "../include/ejecutar.hpp"
using namespace std;

int main (void) {
  ejecutar noseq;
  int opcion;
  do {
    cout << "noseq" << endl;
    switch(opcion) {
      case 1:
        break;
      case 2:
        int x, y;
        cout << "Indique la posicion X e Y" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        noseq.pedir_ocupadas(x, y);
        break;
      case 3:
        break;
      default:
        break;
    }
  } while(opcion != 0);
}