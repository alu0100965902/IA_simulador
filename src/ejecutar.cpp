#include "../include/ejecutar.hpp"

void ejecutar::crear_entorno(int m, int n) {
  entorno tmp(m,n);
  entorno_ = tmp; 
}

void ejecutar::pedir_ocupadas(int x, int y) {
  entorno_.set_ocupada(x, y); 
}

void ejecutar::ocupadas_aleatorias(int num) {
  srand(0);

  for(int i = 0; i < num; i++) {
    int aux_x = rand() % entorno_.numero_col();
    int aux_y = rand() % entorno_.numero_filas();
    if (aux_x != entorno_.get_pos_inicial().first && aux_y != entorno_.get_pos_inicial().second
        || aux_x != entorno_.get_pos_final().first && aux_y != entorno_.get_pos_final().second) {
      entorno_.set_ocupada(aux_x, aux_y);
        }
    else {
      i--;
    }
  }
}

void ejecutar::pos_coche(int x, int y) {
  entorno_.posi_coche(x, y); 
}

void ejecutar::pos_inicial(int x, int y) {
  entorno_.set_pos_inicial(x, y); 
}

void ejecutar::pos_final(int x, int y) {
  entorno_.set_pos_final(x, y);
}

void ejecutar::mostrar_entorno() {
  entorno_.mostrar_malla();
}

void ejecutar::heuristico() {
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();

  int cocheX = entorno_.get_pos_coche().get_x();
  int cocheY = entorno_.get_pos_coche().get_y();
  int indice_actual = 0;
  int distancia_minima = 999999;
  nodo* nodoInicial = new nodo (cocheX, cocheY, NULL);
  int distanciaHeu = entorno_.distancia_linea_recta(cocheX, cocheY) + entorno_.distancia_rectilinea(cocheX, cocheY);
  pair <int, int> distanciaIni(0, distanciaHeu);
  pair <nodo*, pair <int, int>> pairAux (nodoInicial, distanciaIni);
  vectorPosiblesCaminos.push_back(pairAux);

  while (vectorPosiblesCaminos.size() > 0) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((i + j) % 2) {
          int busqX = vectorPosiblesCaminos[indice_actual].first->get_pos().first + i - 1;
          int busqY = vectorPosiblesCaminos[indice_actual].first->get_pos().second + j - 1;
          if (busqX >= 0 && busqY >= 0 && busqX < entorno_.numero_col() && busqY < entorno_.numero_filas()) {
            if (!entorno_[busqX][busqY].comprobar_ocupada()) {
                nodo* auxiliar = vectorPosiblesCaminos[indice_actual].first;
                bool yaEsta = false;
              while (auxiliar->get_anterior() != NULL) {
                auxiliar = auxiliar -> get_anterior();

                if (auxiliar->get_pos().first == busqX && auxiliar->get_pos().second == busqY) {
                  yaEsta = true;
                }                
            
              }              
              if (yaEsta) {
                continue;
              }
              int disHeu = entorno_.distancia_linea_recta(busqX, busqY) + entorno_.distancia_rectilinea(busqX, busqY)
                           + vectorPosiblesCaminos[indice_actual].second.first;
              pair <int, int> disInicial(vectorPosiblesCaminos[indice_actual].second.first + 1, disHeu);
              nodo* nodoActual = new nodo (busqX, busqY, vectorPosiblesCaminos[indice_actual].first);
              pair <nodo*, pair <int, int>> pairNuevo(nodoActual, disInicial);
              vectorPosiblesCaminos.push_back(pairNuevo);
            }
          }
        }
      }
    }
    if (vectorPosiblesCaminos.size() == 1) {
      break;
    }
    int indice_anterior = -1;
    if (!(vectorPosiblesCaminos[indice_actual].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[indice_actual].first->get_pos().second == entorno_.get_pos_final().second)) 
      vectorPosiblesCaminos.erase(vectorPosiblesCaminos.begin() + indice_actual);
    else {
      indice_anterior = indice_actual;
    }
    int posAux = 0;
    int disAux = 9999999;
    for (int i = 0; i < vectorPosiblesCaminos.size(); i++) {
      if (vectorPosiblesCaminos[i].second.second < disAux) {
        disAux = vectorPosiblesCaminos[i].second.second;
        posAux = i;
      }
      if (vectorPosiblesCaminos[i].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[i].first->get_pos().second == entorno_.get_pos_final().second) {
        if (vectorPosiblesCaminos[i].second.second < distancia_minima) {
          distancia_minima = vectorPosiblesCaminos[i].second.first;
        }
    }
    }

    indice_actual = posAux;

    if (indice_actual == indice_anterior)
      break;

  }
  int posFinal = -1;
  int disAux = 9999999;
  for (int i = 0; i < vectorPosiblesCaminos.size(); i++) {
    if (vectorPosiblesCaminos[i].first->get_pos().first == entorno_.get_pos_final().first &&
        vectorPosiblesCaminos[i].first->get_pos().second == entorno_.get_pos_final().second) {
      if (vectorPosiblesCaminos[i].second.second < disAux) {
          disAux = vectorPosiblesCaminos[i].second.second;
          posFinal = i;
      }
    }
  }
  end = chrono::system_clock::now();

  int elapsed_seconds = chrono::duration_cast<chrono::microseconds>
                      (end-start).count();
  vector <nodo*> vectorInvertido;

  if (posFinal != -1) {
    nodo* auxiliar = vectorPosiblesCaminos[posFinal].first;
    while (auxiliar->get_anterior() != NULL) {
      vectorInvertido.push_back(auxiliar);
      auxiliar = auxiliar -> get_anterior();
    }
    for (int i = vectorInvertido.size() - 1; i >= 0 ; i--) {
      entorno_.mover_coche(vectorInvertido[i]->get_pos().first, vectorInvertido[i]->get_pos().second);
      entorno_[vectorInvertido[i]->get_pos().first][vectorInvertido[i]->get_pos().second].pasoCoche();
      entorno_.mostrar_malla();
      cout << endl;
    }
  } else {
    cout << "Camino no encontrado \n" << endl;
  }
  
    cout << "Tamaño camino: " << vectorInvertido.size() << endl;
    cout << "Numero de nodos: " << vectorPosiblesCaminos.size() << endl;
    cout << "Tiempo heuristico: " << elapsed_seconds << "ms\n";
}


void ejecutar::heuristico_manhattan() {
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();

  int cocheX = entorno_.get_pos_coche().get_x();
  int cocheY = entorno_.get_pos_coche().get_y();
  int indice_actual = 0;
  int distancia_minima = 999999;
  nodo* nodoInicial = new nodo (cocheX, cocheY, NULL);
  int distanciaHeu = entorno_.distancia_manhattan(nodoInicial);
  pair <int, int> distanciaIni(0, distanciaHeu);
  pair <nodo*, pair <int, int>> pairAux (nodoInicial, distanciaIni);
  vectorPosiblesCaminos.push_back(pairAux);

  while (vectorPosiblesCaminos.size() > 0) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if ((i + j) % 2) {
          int busqX = vectorPosiblesCaminos[indice_actual].first->get_pos().first + i - 1;
          int busqY = vectorPosiblesCaminos[indice_actual].first->get_pos().second + j - 1;
          if (busqX >= 0 && busqY >= 0 && busqX < entorno_.numero_col() && busqY < entorno_.numero_filas()) {
            if (!entorno_[busqX][busqY].comprobar_ocupada()) {
                nodo* auxiliar = vectorPosiblesCaminos[indice_actual].first;
                bool yaEsta = false;
              while (auxiliar->get_anterior() != NULL) {
                auxiliar = auxiliar -> get_anterior();

                if (auxiliar->get_pos().first == busqX && auxiliar->get_pos().second == busqY) {
                  yaEsta = true;
                }                
              }              
              if (yaEsta) {
                continue;
              }
              nodo* nodoActual = new nodo (busqX, busqY, vectorPosiblesCaminos[indice_actual].first);
              int disHeu = entorno_.distancia_manhattan(nodoActual)
                           + vectorPosiblesCaminos[indice_actual].second.first;
              pair <int, int> disInicial(vectorPosiblesCaminos[indice_actual].second.first + 1, disHeu);
              pair <nodo*, pair <int, int>> pairNuevo(nodoActual, disInicial);
              vectorPosiblesCaminos.push_back(pairNuevo);
            }
          }
        }
      }
    }
    if (vectorPosiblesCaminos.size() == 1) {
      break;
    }
    int indice_anterior = -1;
    if (!(vectorPosiblesCaminos[indice_actual].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[indice_actual].first->get_pos().second == entorno_.get_pos_final().second)) 
      vectorPosiblesCaminos.erase(vectorPosiblesCaminos.begin() + indice_actual);
    else {
      indice_anterior = indice_actual;
    }
    int posAux = 0;
    int disAux = 9999999;

    for (int i = 0; i < vectorPosiblesCaminos.size(); ++i) {
      if (vectorPosiblesCaminos[i].second.second < disAux) {
        disAux = vectorPosiblesCaminos[i].second.second;
        posAux = i;
      }
      if (vectorPosiblesCaminos[i].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[i].first->get_pos().second == entorno_.get_pos_final().second) {
        if (vectorPosiblesCaminos[i].second.second < distancia_minima) {
          distancia_minima = vectorPosiblesCaminos[i].second.first;
        }
    }
    }
    indice_actual = posAux;
    if (indice_actual == indice_anterior)
      break;
  }
  int posFinal = -1;
  int disAux = 9999999;
  for (int i = 0; i < vectorPosiblesCaminos.size(); ++i) {
    if (vectorPosiblesCaminos[i].first->get_pos().first == entorno_.get_pos_final().first &&
        vectorPosiblesCaminos[i].first->get_pos().second == entorno_.get_pos_final().second) {
      if (vectorPosiblesCaminos[i].second.second < disAux) {
          disAux = vectorPosiblesCaminos[i].second.second;
          posFinal = i;
      }
    }
  }
  end = chrono::system_clock::now();

  int elapsed_seconds = chrono::duration_cast<chrono::microseconds>
                      (end-start).count();
  vector <nodo*> vectorInvertido;

  if (posFinal != -1) {
    nodo* auxiliar = vectorPosiblesCaminos[posFinal].first;
    while (auxiliar->get_anterior() != NULL) {
      vectorInvertido.push_back(auxiliar);
      auxiliar = auxiliar -> get_anterior();
    }
    for (int i = vectorInvertido.size() - 1; i >= 0 ; --i) {
      entorno_.mover_coche(vectorInvertido[i]->get_pos().first, vectorInvertido[i]->get_pos().second);
      entorno_[vectorInvertido[i]->get_pos().first][vectorInvertido[i]->get_pos().second].pasoCoche();
      entorno_.mostrar_malla();
      cout << endl;
    }
  } 
  else {
    cout << "Camino no encontrado \n" << endl;
  }
  
    cout << "Tamaño camino: " << vectorInvertido.size() << endl;
    cout << "Numero de nodos: " << vectorPosiblesCaminos.size() << endl;
    cout << "Tiempo heuristico: " << elapsed_seconds << "ms\n";
}