#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
using pp = pair<int,int>;
using ll = long long;


int CASES = 0;
constexpr int MAX_PRICE = 10000;
constexpr int MAX_COINS = 100;
vector<int> coins;
vector<vector<pp>> mem;
constexpr ll INF = (100*100+1);


ll minp (int ptp, int c){
  
}

int main (){
  cin >> CASES;
  for (int i = 0; i< CASES; i++){

    mem.assign(MAX_PRICE+1, vector<pp>(MAX_COINS+1, make_pair(-INF, -INF)));

    int ptp, c;
    cin >> ptp;
    cin>> c;
    coins.resize(c+1);
    for (int i = 1; i <= c; i++){
      int a;
      cin >>a;
      coins[i] = a;
    }
    minp(ptp, c);
  }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo

*/
