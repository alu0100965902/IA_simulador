#include <iostream>
#include "../include/ejecutar.hpp"
using namespace std;

int main (void) {
  ejecutar simulador;
  int opcion;

  cout << "-------Simulador--------" << endl;

  do {
    cout << "Ingrese la Opción a ejecutar: 1. Algo , 2.Obstaculo" << endl;
    cin >> opcion;

    switch(opcion) {
      case 1:
        break;
      case 2:{
        int x = 0, y = 0;
        cout << "Indique la posicion X e Y" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        simulador.pedir_ocupadas(x, y);
        break;}
      case 3:
        break;
      default:
        cout << "Usted ha ingresado una opción incorrecta";
        break;
    }
  } while(opcion != 0);
}