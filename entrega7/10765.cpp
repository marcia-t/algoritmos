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
                children[u] = children[u]+1;
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
        stations.assign(n, ii());
        for (size_t i = 0; i < articulationVertex.size(); i++) {
            if (articulationVertex[i]){
                if (i==0) stations.push_back(ii(i, children[i]));
                else stations.push_back(ii(i, children[i]+1));
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
