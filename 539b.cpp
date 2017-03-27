#include <iostream>

#include <vector>

using namespace std;



int backtracking(vector<pair<int,int>> rutas, vector<pair<int,int>> camino_actual, int pasos_actuales){
  for (int i = 0; i < rutas.size(); i++){
    if (pasos_actuales )
    if (camino_actual.size() < 1 ||  camino_actual.size() > 0 && ) {
      camino_actual.push_back(rutas[pasos_actuales]);
      pasos_actuales++;
      backtracking(rutas, camino_actual,pasos_actuales);
      camino_actual.pop_back();
    }
  }
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
    if (n == 0 && m == 0) return;

    rutas.resize(m);
    //armo el vector de pares (rutas)
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a;
        cin >> b;
        rutas[i] = make_pair(a, b);
    }
    vector<pair<int,int>> ca;

    int mejor = backtracking (rutas, ca, 0);
    std::cout << mejor << '\n';

  }
}
