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

vector<pair<int, int>> conecta_con(int inicio, vector<pair<int,int>> r){
  vector<pair<int, int>> rutas;
  for (int i = 0; i < r.size(); i++){
    if (inicio == r[i].first){
      rutas.push_back(r[i]);
    }
    else if (inicio == r[i].second){
      rutas.push_back(make_pair(r[i].second, r[i].first));
    }
  }
  return rutas;
}

bool existe_ruta(pair<int,int> r, vector<pair<int,int>> rutas){
  for (int i =0; i<rutas.size(); i++){
    if ((r.first == rutas[i].first && r.second == rutas[i].second) || (r.first == rutas[i].second && r.second == rutas[i].first )) return true;
  }
  return false;
}

int mejor_camino(int inicio, vector<pair<int,int>> r, vector<pair<int,int>> &ca, int mayor_camino){
  int mejor = 0;
  if (mayor_camino >= r.size()) return mayor_camino;
  vector<pair<int,int>>  rutas_conectadas = conecta_con(inicio,  r);
  for(int i= 0; i<rutas_conectadas.size(); i++){
      if (!existe_ruta(rutas_conectadas[i], ca)){
          ca.push_back(rutas_conectadas[i]);
          mayor_camino++;
          mejor = mejor_camino (rutas_conectadas[i].second, r, ca, mayor_camino);

          ca.pop_back();
      }


  }
return max(mejor, mayor_camino);

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
      int camino = mejor_camino(i, rutas,  camino_actual, 0);

      if (camino > mayor_camino) mayor_camino = camino;

    }
    cout << mayor_camino << '\n';

  }
}
