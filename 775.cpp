#include <iostream>

#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
char line[100];

using namespace std;

int main(){
  int n;
  vector <pair<int, int>> rutas;

  while (cin >> n){
    rutas.resize(n *(n-1));
    while(getline(line), strcmp(line, "%")) {
      int a, b;
      cin >> a;
      cin >> b;
      rutas.push_back(make_pair(a, b));
    }

  }

}
