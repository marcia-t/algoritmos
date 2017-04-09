#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <array>


using namespace std;

int n = 7;

bool existe_nodo(int nodo, vector<pair<int, int>> rutas){
  for (int i = 0; i<rutas.size(); i++){
    if (rutas[i].first == nodo || rutas[i].second == nodo){
      return true;
    }
  }
  return false;
}

bool paso_x_todos(vector<pair<int,int>> ca){
  for (int i = 1; i<=n; i++){
    if (!existe_nodo(n, ca)) return false;
  }
  return true;
}


int main()
{

/*bool v[10];
v[2] = 1;

for (int i = 0; i<10; i++){
  if (v[i]) std::cout << v[i] << '\n';*/
/*
  string a = "010";
  int b = 10;
  int c = atoi( a.c_str() );

  std::cout << b << '\n';
  std::cout << c << '\n';
  std::cout << a << '\n';*/
  vector<int> c;
  c.resize(29);

  std::cout << c[31] << '\n';
}

  /*
vector<pair<int,int>> rutas;
rutas.push_back(make_pair(1,2));
rutas.push_back(make_pair(2,3));
rutas.push_back(make_pair(2,4));
rutas.push_back(make_pair(3,4));
rutas.push_back(make_pair(3,1));

bool p = paso_x_todos(rutas);

std::cout << p << '\n';
*/
/*
vector <int> j;
j.resize(8);
j[2] = 1;

for (int i = 0; i<8; i++){
  std::cout << j[i] << '\n';
}*/

/*imprimir una matriz

for (int i=0;i<10;i++)
      {
        for (int j=0;j<10;j++)
        {
          std::cout << "|" << i << j << "  "  <<matrizRutas[i][j] << "|";

        }
        std::cout << '\n';

      }

*/
