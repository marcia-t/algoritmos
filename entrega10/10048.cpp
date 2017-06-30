#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;

/*
COMPLEJIDAD
El algoritmo de Prim implementado con colas de prioridad tiene complejidad O(m log n) con:
n: cantidad de vértices
m: cantidad de aristas
La cantidad de vértices estará acotada por  C (peor caso, ya que si encontramos
el destino antes, finaliza la ejecución), mientras que las aristas estarán acotadas por S (peor caso también).
Vamos a ejecutar el algoritm de Prim Q veces.
Quedando entonces la complejidad: O (Q * S log C)
*/

constexpr int INF = 1000*1000;
int C, S, Q;
graph G;
vector<int> DIST;
vector<bool> VISITED;

int prim(int o, int d){
    int u,w;
    int worst_db = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(pi(0, o));
    DIST[o] = 0;
    while (!pq.empty()) {
        pi front = pq.top(); pq.pop();
        u = front.second, w = front.first;
        if (!VISITED[u]){
            VISITED[u] = true;
            worst_db = max(worst_db, w);
            if (u == d) return worst_db; // termino cuando encuentro d
            for (pi v : G[u]) {
                if (!VISITED[v.second] && DIST[v.second] > v.first){
                    DIST[v.second] = v.first;
                    pq.push(pi(v.first, v.second));
                }
            }
        }
    }
    return 0; // si nunca encuentro d, retorno 0
}

int main(){
    int c = 0;
    while (cin >> C >> S >> Q){
        if (!(C==0 && S==0 && Q==0)){
            c++;
            if (c>1) cout << '\n';
            G.assign(C+1, vpi());
            int n, o, p;
            for (size_t i = 0; i < S; i++) {
                cin >> n >> o >> p;
                G[n].push_back(pi(p,o));
                G[o].push_back(pi(p,n));
            }
            cout << "Case #" << c << '\n';
            for (size_t j = 0; j < Q; j++) {
                DIST.assign(C+1, INF);
                VISITED.assign(C+1, false);
                int o, d;
                cin >> o >> d;
                int r = prim(o,d);
                if (r== 0) cout << "no path" << '\n';
                else std::cout << r << '\n';
            }
        }
        else break;
    }
}
