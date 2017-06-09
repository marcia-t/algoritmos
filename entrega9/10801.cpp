#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;
constexpr int INF = 21;

vi times;
vii floors;

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


int main(){
  int n;
  while(scanf("%d", &n)!=EOF){
    int k;
    cin >> k;
    times.resize(n+1);
    for (size_t i = 1; i <= n; i++) {
      int t;
      cin >> t;
      times[i] = t;
    }
    pi start = pi(0,0);
    floors.assign(n+1, vi(21,-INF));
    for (size_t i = 1; i <= n; i++) {
      char f [1000];
      gets (f);
      //std::getline (std::cin,f);
       char * pch;
        pch = strtok (f," ");
          while (pch != NULL)
            {
              std::cout << atoi(pch) << '\n';
              int b = atoi(pch);
              floors[i].push_back(atoi(pch));
              pch = strtok (NULL, " ");
            }

    }

    for (int i=0;i<3;i++)
          {
            for (int j=0;j<20;j++)
            {
              std::cout << "|" << i << ", "<< j << "  "  <<floors[i][j] << "|";

            }
            std::cout << '\n';

          }
  }
}
