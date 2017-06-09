#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
#include<list>

using namespace std;
using vi = vector<int>;
using graph = vector<vi>;

vi times;

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
    for (size_t i = 1; i <= n; i++) {
      /* code */
    }
  }
}
