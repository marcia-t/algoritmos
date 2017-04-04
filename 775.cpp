#include <iostream>

#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

void ciclo(int inicio, vector<pair<int,int>> rutas, vector<pair<int,int>> &ca){
  return;
}


int main(){
  int n;
  vector <pair<int, int>> rutas;



  while (cin >> n){
    //rutas.resize(n *(n-1));
    string a, b;
    while(cin >> a) {
      if (a == "%"){
        for (int i = 0; i<n; i++){
          vector<pair<int,int>> camino_actual;
          ciclo(i, rutas, camino_actual);
        }
      }
      else {
        int b;
        cin >> b;
        int c =   std::stoi( a );
        rutas.push_back(make_pair(c, b));
      }
    }

  }

}
