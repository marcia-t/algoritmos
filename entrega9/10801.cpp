#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;
constexpr int INF = 1000*1000;

vi times;
vii stopping_floors;
graph G;
vii adyacencies;
int k;

/*
n=2 k=30
t1=10 t2=5
p1=0 1 3 5 7 9 11 13 15 20 99
p2=4 13 15 19 20 25 30

n=cant ascensores
k=piso al que quiero llegar
ti=tiempo que tarda el ascensor i entre piso y piso
pi= pisos en los que se detiene el ascensor i
*/




//las aristas son vecino + peso
//enn la cola guardo peso + vecino
int dijkstra(int from) {
    vector<int> dist(G.size(), INF);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0,from});
    while(not q.empty()) {
        auto u = q.top();
        q.pop();
        if(dist[u.second] < INF) continue;
        dist[u.second] = u.first;
        for(auto v : G[u.second]) if(dist[v.first] == INF) {
                q.push({u.first + v.second, v.first});
            }
    }
    int d = INF;
    for (int i = 0; i < 5; ++i) {
        d = min(d, dist[k+(100*i)]);
    }
    return d;
}


int main(){
    string input_line;
    int n;



    while(scanf("%d", &n)!=EOF){
        cin >> k;
        times.resize(n+1);
        for (size_t i = 1; i <= n; i++) {
            int t;
            cin >> t;
            times[i] = t;
        }
        pi start = pi(0,0);
        stopping_floors.assign(n+1, vi());
        adyacencies.assign(100, vi());
        for (size_t i = 0; i <= n; i++){
            std::string line;
            std::getline(std::cin, line);
            string delimiter = " ";
            size_t pos = 0;
            std::string token;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                int nn;
                stringstream(token) >> nn;
                line.erase(0, pos + delimiter.length());
                stopping_floors[i].push_back(nn);
            }
            int mm;
            stringstream(line) >> mm;
            stopping_floors[i].push_back(mm);
        }
        //voy a sumar de a 100 a los pisos x ascensor
        //dejo la posición 500 para el inicio con referencias a todos los que arranquen en 0 (para iniciar Dijkstra desde ahí).
        G.assign(501, vpi());
        for (size_t a = 1; a <= n; a++) {
            //a es el ascensor actual
            int p = 100 * (a-1);
            stopping_floors[a].push_back(1000);
            for (size_t j = 0; j < stopping_floors[a].size(); j++) {
                int pp = stopping_floors[a][j];
                //si estoy en el piso cero, agrego una ref en el que será el inicio de mi grafo
                if (pp == 0) G[500].push_back(pi(pp+p,0));
                //caso: si tengo un ascensor en el mismo piso
                if (adyacencies[pp].size() > 0){
                    for (size_t i = 0; i < adyacencies[pp].size(); i++) {
                        G[pp+p].push_back(pi(adyacencies[pp][i],60));
                        G[adyacencies[pp][i]].push_back(pi(pp+p,60));
                    }
                }
                adyacencies[pp].push_back(pp+p);
                //si llego al final de los pisos, no sigo iterando
                if (stopping_floors[a][j+1] == 1000) break;
                else{
                    int pf = stopping_floors[a][j+1];
                    int w = (pf - pp) * times[a];
                    pp = pp + p;
                    pf = pf + p;
                    G[pp].push_back(pi(pf,w));
                    G[pf].push_back(pi(pp,w));
                }
            }
        }
        auto results = dijkstra(500);
        if (results == INF) cout << "IMPOSSIBLE" << '\n';
        else cout << results << '\n';

    }
}
