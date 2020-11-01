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
  simulador.mostrar_entorno();
  int x, y;
  cout << "Ingrese el punto de partida" << endl;
  cout << "X: ";
  cin >> x;
  cout << "\nY: ";
  cin >> y;
  cout << "\n";
  simulador.pos_inicial(x, y);
  cout << "Ingrese el punto final" << endl;
  cout << "X: ";
  cin >> x;
  cout << "\nY: ";
  cin >> y;
  cout << "\n";
  simulador.pos_final(x, y);

  cout << "Ingrese la Opción a ejecutar:\n";
  cout << "1.Indicar obstaculo.\n";
  cout << "2. Obstaculos aleatorios." << endl;
  cin >> opcion;

  switch(opcion) {
    case 1: {
      int n_obstaculos = 0;
      cout << "Numero de obstaculos" << endl;
      cin >> n_obstaculos;
      for (int i = 0; i < n_obstaculos; i++) {
        cout << "Indique la posicion X e Y" << endl;
        cout << "X: ";
        cin >> x;
        cout << "\nY: ";
        cin >> y;
        cout << "\n";
        simulador.pedir_ocupadas(x, y);
      }     
      }
      break;
    case 2: {
      int num = 0;
      cout << "Indique el porcentaje de obstaculos" << endl;
      cout << "Num:";
      cin >> num;
      simulador.ocupadas_aleatorias(num);
      }
      break;
    default: {
      cout << "Usted ha ingresado una opción incorrecta";
      exit;
      }
      break;
  }
    simulador.mostrar_entorno();
  simulador.prueba();
}