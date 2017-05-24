#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>


/**
Complejidad
La complejidad del algoritmo será lineal en relación a los vértices que se procesen.
En este caso se procesan todos los vértices una vez.
Asumimos que procesar un vértice es O(1)

*/


using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using graph = vector<vi>;
using ii = pair<int,int>;
using vp = vector<ii>;

/*
En las variables globales guardo:
level: nivel en el árbol DFS para cada nodo
articulationVertex:  guarda para cada vértice si es o no PC.
minReach: el mínimo alcanzable en el árbol DFS para cada vértice
G: lista de adyacencias
rc: cantidad de componentes conexas que genera un vértice al ser removido del grafo
stations: vector auxiliar para ordenar los resultados
rootChildren: contempla el caso base de que la raíz del árbol DFS sea PC (tenga más de 1 hijo)
*/

constexpr int UNVISITED = -1;
vi level;
vb articulationVertex;
vi minReach;
graph G;
vi rc;
vp stations;
int n, m, rootChildren;

/*Ordeno los pares del resultado: primero por la mayor cantidad de cc causadas
y después por los vértices (orden ascendente)*/
bool sortpair(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if (a.second == b.second){
        return (a.first < b.first);
    }else
        return (a.second > b.second);
}



void dfs(int u) {
    minReach[u] = level[u];
    for (int v : G[u]) {
        if (level[v] == UNVISITED) {
            level[v] = level[u]+1;

            if (level[u] == 0) rootChildren++;
            dfs(v);
            if (minReach[v] >= level[u]){
                articulationVertex[u] = true;
                rc[u] = rc[u]+1;
            }
            minReach[u] = min(minReach[u], minReach[v]);
        }
        else minReach[u] = min(minReach[u], level[v]);
    }
}


int main(){
    while (cin >> n){
        cin >> m;
        G.assign(n, vi());
        if (n == 0 & m == 0) break;
        int a,b;
        while (cin >> a >> b){
            if (a == -1 & b == -1){
                level.assign(n, UNVISITED);
                articulationVertex.assign(n, false);
                minReach.assign(n,n+1);
                rc.assign(n, 0);
                int root = 0;
                level[root] = 0;
                rootChildren = 0;
                dfs(root);
                articulationVertex[root] = (rootChildren > 1); //raìz es pto de corte
                break;
            }
            else{ //bidireccional
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }


        stations.assign(n, ii());
        for (size_t i = 0; i < articulationVertex.size(); i++) {
            if (articulationVertex[i]){
                if (i==0) stations.push_back(ii(i, rc[i]));
                else stations.push_back(ii(i, rc[i]+1));
            }
            else stations.push_back(ii(i, 1));
        }

        std::sort(stations.begin(), stations.end(), sortpair);

        for (size_t i = 0; i < m; i++) {
            std::cout << stations[i].first << " " << stations[i].second << '\n';
        }
        std::cout << '\n';

    }
}
