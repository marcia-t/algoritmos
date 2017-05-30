#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
using namespace std;

/**
Complejidad:
La complejidad del algoritmo será lineal en relación a los vértices del grafo.
En este caso se procesan todos los vértices como mucho una vez.
Asumo que procesar un vértice es O(1)
n es la cantidad de vértices y m la cantidad de aristas (direccionales), la complejidad es O(n + m)
*/

using vi = vector<int>;
using graph = vector<vi>;

/*
En las variables globales guardo:
n: cantidad de vértices
G: lista de adyacencias del grafo de entrada
v: vector que guarda los nodos visitados
*/
int n;
graph G;
vi v;
constexpr int UNVISITED = -1;
constexpr int VISITED = 1;

void dfs(int a){
  //marco todos los vecinos de a y chequeo cuáles son los vecinos de sus vecinos
    for (int v : G[a]) {
        if (v[v] == UNVISITED) {
            v[v] = VISITED;
            dfs(v);
        }
    }
}


int main(){
    int a, m;
    while (cin >> n){
        if (n == 0) return 0;
        G.assign(n+1, vi());
        while (cin >> a) {
            if (a != 0) {
                int b;
                while (cin >> b) {
                    if (b == 0) break;
                    G[a].push_back(b);
                }
            }
            else if (a == 0) break;
        }


        cin >> m; //cant de vértices de los que quiero saber;
        for (size_t j = 0; j < m; j++) {
            cin >> a;
            v.assign(n+1, UNVISITED);
            //no marco el pto de partida como visitado.
            //como es un digrafo, de esta manera puedo ver si vuelvo al nodo raíz para marcarlo visitado.
            dfs(a);
            int c = 0;
            string l = "";
            for(int i= 1; i<=n; i++){

                if (v[i] == UNVISITED){
                    c++;
                    string s = std::to_string(i);
                    l = l+" "+ s;
                }
            }
            cout << c  << l << '\n';
        }
    }
}
