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
int mem[MAX_PRICE][MAX_COINS];
int mem_c[MAX_PRICE][MAX_COINS];
constexpr ll INF = (100*100+1);


ll minp (int ptp, int c){
  if (c == 0 && ptp>0) return INF;
  if (ptp <= 0) return -ptp;
  if (mem[ptp][c] == INF){
    int p = ptp - coins[c];
    ll val=  min(minp(ptp, c-1), minp(p,c-1));
    mem[ptp][c] = val;
  }

  return mem[ptp][c];
}

ll qcoins (int ptp, int c){
  std::cout << "entro con "<<ptp <<" y"  <<c << '\n';
  if (c == 0  || ptp == 0)  return 0;
  if (ptp < 0) return -INF;

  if(mem_c[ptp][c] == INF){
    int val = ptp - coins[c];
    mem_c[ptp][c] = max(qcoins(ptp, c-1), 1+qcoins(val, c-1));
  }
  return mem_c[ptp][c];
}

int main (){
  cin >> CASES;
  for (int i = 0; i< CASES; i++){
    int ptp, c;
    cin >> ptp;
    cin>> c;
    coins.resize(c+1);
    for (int i = 1; i <= c; i++){
      int a;
      cin >>a;
      coins[i] = a;
    }
    for(int i = 0; i <= ptp+1; i++) {
      for(int j = 0; j <= c+1; j++) {
        mem[i][j] = INF;
      }
    }
    ll j =minp(ptp, c);
    for(int i = 0; i <= ptp+j+1; i++) {
      for(int j = 0; j <= c+1; j++) {
        mem[i][j] = INF;
      }
    }
    ll co = qcoins(j+ptp, c);
    std::cout << j+ptp << " " << co << '\n';
    //std::cout << co << '\n';
  }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo

*/
