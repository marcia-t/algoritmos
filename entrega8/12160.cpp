#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
#include<list>

using namespace std;
using vi = vector<int>;
using graph = vector<vi>;
constexpr int UNDEFINED = -1;
constexpr int UNVISITED = -1;
constexpr int VISITED = 1;


/*
Complejidad
Los nodos aparecerán solamente una vez en la cola (ya que luego se marcan como visitados).
Como cada vez que saco un nodo de la cola, proceso n veces, el algoritmo tiene O(n²)
En este caso podría ser incluso menos porque cuando encuentro el código de desbloqueo ya termino de ejecutar,
pero calculamos siempre el peor caso.
*/

/*
Usaré una lista como cola
En las variables globales guardo:
L, U, R, BUTTONS: viene por input y son los valores indicados para resolver el problema.
G: grafo representado como lista de adyacencias.
DISTANCE: mantiene la distancia desde la raíz para cada nodo del árbol
V: indica si un nodo fue o no visitado.
MIN: guarda el camino mínimo desde la raiz al código de desbloqueo.
*/

int L, U, R;
vi BUTTONS;
graph G;
vi DISTANCE;
vi V;
int MIN;

void bfs(int r){
  list<int> q;
  q.push_back(r);
  while (!q.empty()){
    int p = q.front();
    q.pop_front();

    for (size_t i = 0; i < BUTTONS.size(); i++) {
      int res;
      res = BUTTONS[i] + p;
      if (res>=10000) res = res-10000;
      //si el nodo no está visitado, lo agrego a las adyacencias
      if (V[res] != VISITED)
        G[p].push_back(res);
    }
    //proceso todos los vecinos
    for (size_t j = 0; j < G[p].size(); j++) {
      int n = G[p][j];
      //agrego a la cola
      q.push_back(n);
      V[n] = VISITED;
      //actualizo su distancia a la raíz
      DISTANCE[n] = DISTANCE[p] +1;
      //si alcanzo el U (código de desbloqueo) guardo el camino minimo
      if (n == U) MIN = DISTANCE[n];
    }



  }

}


int main(){
    for (int i = 1; i <= 100; i++) {
        cin >> L >> U >> R;
        if (L == 0 &&  R == 0 && U == 0) return 0;
        BUTTONS.assign(R, UNDEFINED);
        for (int j = 0; j < R; j++) {
            int a;
            cin >> a;
            BUTTONS[j] = a;
        }
        MIN = UNDEFINED;
        DISTANCE.assign(10000, UNDEFINED);

        V.assign(10000, UNVISITED);
        G.assign(10000, vi());
        std::cout << "Case " << i <<": ";
        DISTANCE[L] = 0;
        V[L] = VISITED;

        bfs(L);
        if (MIN == UNDEFINED) std::cout << "Permanently Locked" << '\n';
        else std::cout << MIN << '\n';
    }
}
