#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using graph = vector<vi>;
using ii = pair<int,int>;
using vp = vector<ii>;


int n;
graph G;
vi level;
constexpr int UNVISITED = -1;
constexpr int VISITED = 1;

void dfs(int a){
    for (int v : G[a]) {
        if (level[v] == UNVISITED) {
            level[v] = VISITED;
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


        cin >> m; //cant de vértices para buscar;
        for (size_t j = 0; j < m; j++) {
            cin >> a;
            level.assign(n+1, UNVISITED);
            //level[a] = 0;
            dfs(a);
            int c = 0;
            string l = "";
            for(int i= 1; i<=n; i++){

                if (level[i] == UNVISITED){
                    c++;
                    string s = std::to_string(i);
                    l = l+" "+ s;
                }
            }
            cout << c  << l << '\n';
        }
    }
}
