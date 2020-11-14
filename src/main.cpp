#include <iostream>
#include <fstream>
#include<string>
#include "../include/ejecutar.hpp"
using namespace std;

int main (int argc, char** argv) {
  ejecutar simulador;
  int opcion, m, n;
  int x, y;
  
  if (argc == 2) {
    string input_name = argv[1];
    fstream file;

    file.open(input_name);

    if(file.is_open()) {
      vector <char> vAux;
      string aux;

      getline(file, aux);
      
      for (int i = 0; i < aux.size(); i++) {
        if (aux[i] != ' ') {
          vAux.push_back(aux[i]);
        }
      if (vAux.size() > 2) {
        cout << "ERROR" << endl;
        break;
      }
      }
      simulador.crear_entorno(vAux[0] - '0', vAux[1] - '0');

      vector <char> vposiciones;
      string posiciones;
      getline(file, posiciones);
      
      for (int i = 0; i < posiciones.size(); i++) {
        if (posiciones[i] != ' ') {
          vposiciones.push_back(posiciones[i]);
        }
      if (vposiciones.size() > 2) {
        cout << "ERROR" << endl;
        break;
      }
      }
      simulador.pos_inicial(vposiciones[0] - '0', vposiciones[1] - '0');
      
      vector <char> vposiciones_final;
      string posiciones_final;
      getline(file, posiciones_final);
      
      for (int i = 0; i < posiciones_final.size(); i++) {
        if (posiciones_final[i] != ' ') {
          vposiciones_final.push_back(posiciones_final[i]);
        }

      if (vposiciones_final.size() > 2) {
        cout << "ERROR" << endl;
        break;
      }
      }
      simulador.pos_final(vposiciones_final[0] - '0', vposiciones_final[1] - '0');

      while(!file.eof()) {
        vector <char> vposiciones_obs;
        string obs;
        getline(file, obs);
        
        for (int i = 0; i < obs.size(); i++) {
          if (obs[i] != ' ') {
            vposiciones_obs.push_back(obs[i]);
          }

        if (vposiciones_obs.size() > 2) {
          cout << "ERROR" << endl;
          break;
        }
        }
        simulador.pedir_ocupadas(vposiciones_obs[0] - '0', vposiciones_obs[1] - '0');
        } 
    
      simulador.mostrar_entorno();
      cout << "Elija la funcion que quiere utilizar: \n";
      cout << "1. Euclideo\n";
      cout << "2. Manhattan\n";
      int opcion_heu;
      cin >> opcion_heu;
      if (opcion_heu == 1) {
        simulador.heuristico();
      } else if (opcion_heu == 2) {
        simulador.heuristico_manhattan();
      }
    }
        
    else {
      cout <<"\nNo se pudo abrir el fichero";
    }
  }

  else if (argc == 1) {

    cout << "-------Simulador--------" << endl;
    cout << "Indique las dimensiones del entorno MxN" << endl;
    cin >> m;
    cin >> n;
    simulador.crear_entorno(m,n);

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
    cout << "1. Indicar obstaculo.\n";
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
    cout << "Elija la funcion que quiere utilizar: \n";
    cout << "1. Euclideo\n";
    cout << "2. Manhattan\n";
    int opcion_heu;
    cin >> opcion_heu;
    if (opcion_heu == 1) {
      simulador.heuristico();
    } else if (opcion_heu == 2) {
      simulador.heuristico_manhattan();
    }
  }
}