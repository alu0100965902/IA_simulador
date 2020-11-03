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
    cout << "A" << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((i + j) % 2) {
          int busqX = vectorPosiblesCaminos[indice_actual].first->get_pos().first + i - 1;
          int busqY = vectorPosiblesCaminos[indice_actual].first->get_pos().second + j - 1;
         // cout << "HOHO" << endl;
         // cout << busqX << " " << busqY  <<endl;
         // cout << entorno_.numero_filas() << endl;
          if (busqX >= 0 && busqY >= 0 && busqX < entorno_.numero_filas() && busqY < entorno_.numero_col()) {
          //  cout << "JEJE" << endl;
            if (!entorno_[busqX][busqY].comprobar_ocupada()) {
              cout << "X: " << busqX << "Y: " << busqY  <<endl;
              int disHeu = entorno_.distancia_linea_recta(busqX, busqY) + entorno_.distancia_rectilinea(busqX, busqY)
                           + vectorPosiblesCaminos[indice_actual].second.first;
              pair <int, int> disInicial(vectorPosiblesCaminos[indice_actual].second.first + 1, disHeu);
              nodo* nodoActual = new nodo (busqX, busqY, vectorPosiblesCaminos[indice_actual].first);
              pair <nodo*, pair <int, int>> pairNuevo(nodoActual, disInicial);
              vectorPosiblesCaminos.push_back(pairNuevo);
              cout << vectorPosiblesCaminos.size() << endl;
            }
          }
        }
      }
    }
    //bool seguir = true;  
   /* for (int i = 0; i < vectorPosiblesCaminos.size(); i++) {
      if (vectorPosiblesCaminos[i].second.second < distancia_minima)
      seguir = true;
    }*/
   /* if (!seguir)
      break;*/
    int indice_anterior = -1;
    if (!(vectorPosiblesCaminos[indice_actual].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[indice_actual].first->get_pos().second == entorno_.get_pos_final().second)) 
      vectorPosiblesCaminos.erase(vectorPosiblesCaminos.begin() + indice_actual);
    else {
      cout << "AYAYAY" << endl;
      indice_anterior = indice_actual;
    }
    int posAux = 0;
    int disAux = 9999999;
    for (int i = 0; i < vectorPosiblesCaminos.size(); i++) {
          cout << "X= " << vectorPosiblesCaminos[i].first->get_pos().first << " Y= " << vectorPosiblesCaminos[i].first->get_pos().second << endl;

      if (vectorPosiblesCaminos[i].second.second < disAux) {
        disAux = vectorPosiblesCaminos[i].second.second;
        posAux = i;
        cout << "E " << posAux <<  endl;
      }
      if (vectorPosiblesCaminos[i].first->get_pos().first == entorno_.get_pos_final().first &&
           vectorPosiblesCaminos[i].first->get_pos().second == entorno_.get_pos_final().second) {
             cout << "T" << endl;
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
  vector <nodo*> vectorInvertido;
  cout << "tamaño" << vectorPosiblesCaminos.size() << endl;
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
}



/*void ejecutar::heuristico() {

  int indice_actual = 0;
  nodo* nombre = new nodo (0, 0, NULL);

  pair <int, int> posIni(cocheX, cocheY);
  pair <int, int> distanciaIni (0, 0);
  pair <pair <int, int>, pair <int, int>> pairPush (posIni, distanciaIni);
  vectorPosiblesCaminos.push_back(pairPush);
  while (vectorPosiblesCaminos.size() > 0 && 
         !(vectorPosiblesCaminos[indice_actual].first.first == entorno_.get_pos_final().first
           && vectorPosiblesCaminos[indice_actual].first.second == entorno_.get_pos_final().second)) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((i != 1 || j != 1 ) && (i + j) % 2 == 1) {
          int busqX = cocheX + i - 1;
          int busqY = cocheY + j - 1;
          if (busqX >= 0 && busqX < entorno_.numero_col() &&
              busqY >= 0 && busqY < entorno_.numero_filas() &&
              !entorno_[busqX][busqY].comprobar_ocupada()) {
            pair <int, int> posAux(busqX, busqY);
            int distanciaHeu = entorno_.distancia_linea_recta(busqX, busqY) + entorno_.distancia_rectilinea(busqX, busqY)
                              + vectorPosiblesCaminos[indice_actual].second.first;
            int distanciaRecorrida = vectorPosiblesCaminos[indice_actual].second.first + 1;
            pair <int, int> distanciaAux (distanciaRecorrida, distanciaHeu);
            pair < pair <int, int>, pair <int, int> > pairAux (posAux, distanciaAux);
            vectorPosiblesCaminos.push_back(pairAux);
          }
        }
      }
    }
    vectorPosiblesCaminos.erase(vectorPosiblesCaminos.begin() + indice_actual);
    int posAux = 0;
    int disAux = 9999999;
    for (int i = 0; i < vectorPosiblesCaminos.size(); i++) {
      if (vectorPosiblesCaminos[i].second.second < disAux) {
        disAux = vectorPosiblesCaminos[i].second.second;
        posAux = i;
      }
    }
    entorno_.mover_coche(vectorPosiblesCaminos[posAux].first.first, vectorPosiblesCaminos[posAux].first.second);
    cocheX = entorno_.get_pos_coche().get_x();
    cocheY = entorno_.get_pos_coche().get_y();
    cout << "X" <<vectorPosiblesCaminos[posAux].first.first <<endl;
    cout << "Y" <<vectorPosiblesCaminos[posAux].first.second <<endl;

    indice_actual = posAux;
  }

}*/