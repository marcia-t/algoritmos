#include <iostream>

#include <vector>

using namespace std;


vector<pair<int,int>> camino_actual;

bool conecta_f(int n, pair<int, int> p){
  return (n == p.first);
}

bool conecta_s (int n, pair<int, int> p){
  return (n == p.second);
}

bool conecta(int inicio, vector<pair<int,int>> r){

}

int mejor_camino(int inicio, vector<pair<int,int>> r, int cant_rutas_usadas,vector<pair<int,int>> &ca, int total_rutas, int mayor_camino){

      int mejor= 0;
      //int mayor_camino = 0;
        if (cant_rutas_usadas >= total_rutas) return mayor_camino;
        else if (conecta_f(inicio, r[cant_rutas_usadas])){
            ca.push_back(r[cant_rutas_usadas]);
            cant_rutas_usadas++;
            mayor_camino++;
            mejor = mejor_camino(r[cant_rutas_usadas].first, r, cant_rutas_usadas, ca,  total_rutas, mayor_camino);
            ca.pop_back();
        }
        else if (conecta_s(inicio, r[cant_rutas_usadas])){
          ca.push_back(r[cant_rutas_usadas]);
          cant_rutas_usadas++;
          mayor_camino++;
          mejor = mejor_camino(r[cant_rutas_usadas].second, r, cant_rutas_usadas, ca,  total_rutas, mayor_camino);
          ca.pop_back();
        }
        else{
            cant_rutas_usadas++;
            mejor = mejor_camino(inicio, r, cant_rutas_usadas, ca,  total_rutas, mayor_camino);
        }
      return mejor;

}


int main() {
  int n, m;
  int mayor_camino = 0;
  vector<pair<int,int>> rutas;

  while (cin >> n) {

    //ya guardé en n la cantidad de nodos
    //guardo en m la cantidad de rutas
    cin >> m;

    //si llego al final
    if (n == 0 && m == 0) return 0;

    rutas.resize(m);
    //armo el vector de pares (rutas)
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a;
        cin >> b;
        rutas[i] = make_pair(a, b);
    }

    //backtrack sobre cada nodo
    for (int i = 0; i < n; i++){
      //recorro la salida desde cada nodo.
      //i es el nodo por donde empiezo, rutas son las rutas que armé arriba, 0 es la cantidad de pasos que dí, camino_actual
      // son las rutas que usé, m es la cantidad de rutas, 0 es el mejor camino cuando empiezo a recorrer.
      int camino = mejor_camino(i, rutas, 0, camino_actual, m, 0);

      if (camino > mayor_camino) mayor_camino = camino;
    }
    cout << mayor_camino << '\n';

  }
}


/*  //si todavía no agregué ninguna ruta
  if (ca.size() < 1 ||  ca.size() > 0 && ) {
    ca.push_back(r[i]);
    mc++;
    backtracking(vector<pair<int, int> > &ca, int mc, vector<pair<int, int> > r)
    ca.pop_back();
  }
  else return;*/
