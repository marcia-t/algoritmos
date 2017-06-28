x|#include <iostream>
#include <vector>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;
using minmax = vector<vector<int>>;

int C, S, Q;
graph G;
minmax RES;


void prim(){

}

int main(){
  while (cin >> C >> S >> Q){
    if (!(C==0 && S==0 && Q==0)){
      G.assign(C+1, vpi());
      int n, o, p;
      RES.assign(C+1, vector<int>(C+1, 0));
      for (size_t i = 0; i < S; i++) {
          cin >> n >> o >> p;
          G[n].push_back(pi(p,o));
          G[o].push_back(pi(p,n));
          prim();
      }
    }
    else break;
  }
}
