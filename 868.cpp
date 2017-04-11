#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
int cases = 0;
constexpr int filas;
constexpr int cols;

int maze[filas][cols];
bool visitados[filas][cols];


int main(){
  while (cin >> cases){
    cin >> filas;
    cin >> cols;

    int maze[filas][cols];

    for (int i = 0; i < filas; i++){
      for (int j = 0; j < cols; j++){
        int a;
        cin >> a;
        maze[i][j] = a;
        visitados[i][j] = false;
      }
    }





  }
}
