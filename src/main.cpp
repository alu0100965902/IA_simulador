#include <iostream>
#include "../include/ejecutar.hpp"
using namespace std;

int main (void) {
  ejecutar simulador;
  int opcion, m, n;

  cout << "-------Simulador--------" << endl;
  cout << "Indique las dimensiones del entorno MxN" << endl;
  cin >> m;
  cin >> n;
  simulador.crear_entorno(m,n);

  do {
    cout << "Ingrese la Opción a ejecutar: 1.Punto partida, 2.Punto final, 3.Posición del coche, 4.Indicar obstaculo, 5.Obstaculos aleatorios." << endl;
    cin >> opcion;

    switch(opcion) {
      case 1: {
        int x = 0, y = 0;
        cout << "Indicar la posicion inicial" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        simulador.pos_inicial(x, y);
        }
        break;
      case 2: {
        int x = 0, y = 0;
        cout << "Indicar la posicion final" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        simulador.pos_final(x, y);
        }
        break;
      case 3: {
        int x = 0, y = 0;
        cout << "Indique la posicion X e Y del coche" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        simulador.pos_coche(x, y);
        }
        break;
      case 4: {
        int x = 0, y = 0, n_obstaculos = 0;
        cout << "Numero de obstaculos" << endl;
        cin >> n_obstaculos;
        for (int i = 0; i < n_obstaculos; i++) {
          cout << "Indique la posicion X e Y" << endl;
          cout << "X: ";
          cin >> x;
          cout << "\nY: ";
          cin >> y;
          cout << "\n";
          // simulador.pedir_ocupadas(x, y);
        }
        }
        break;
      case 5: {
        int num = 0;
        cout << "Indique el porcentaje de obstaculos" << endl;
        cout << "Num:";
        cin >> num;
        simulador.ocupadas_aleatorias(num);
        }
        break;
      default:
        cout << "Usted ha ingresado una opción incorrecta";
        break;
    }
  } while(opcion != 0);
}