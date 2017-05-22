#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
/**
Sabemos que el grafo de entrada es Conexo
*/


using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using graph = vector<vi>;
using ii = pair<int,int>;
using vp = vector<ii>;


constexpr int UNVISITED = -1;
vi level;
vb articulationVertex;
vi minReach;
graph G;
vi children;
vp stations;
int n, m, rootChildren;



void dfs(int u) {
    minReach[u] = level[u];
    for (int v : G[u]) {
        if (level[v] == UNVISITED) {
            level[v] = level[u]+1;
            children[u] = children[u]+1;
            if (level[u] == 0) rootChildren++;
            dfs(v);
            if (minReach[v] >= level[u])
                articulationVertex[u] = true;
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
                children.assign(n, 0);
                int root = 0;
                level[root] = 0;
                rootChildren = 0;
                dfs(root);
                articulationVertex[root] = (rootChildren > 1);
                break;
            }
            else{
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }

        for (size_t i = 0; i < articulationVertex.size(); i++) {
          if (articulationVertex[i]){
            vp.push_back(ii(i, children[i]+1));
          }
        }

    }
}
