#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
using namespace std;
using vi = vector<int>;
using graph = vector<vi>;
constexpr int UNDEFINED = -1;
constexpr int UNVISITED = -1;
constexpr int VISITED = 1;


int L, U, R;
vi BUTTONS;
graph G;
vi DISTANCE;
vi PARENT;
vi V;

void dfs(int r){

  for (size_t i = 0; i < BUTTONS.size(); i++) {
    /* code */
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
        DISTANCE.assign(10000, UNDEFINED);
        PARENT.assign(10000, UNDEFINED);
        G.assign(10000, vi());
        std::cout << "Case " << i <<": ";
        DISTANCE[L] = 0;
        V[L] = VISITED;
        bfs(L);
    }
}
