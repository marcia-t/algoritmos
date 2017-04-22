#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
using pp = pair<int,int>;
//using ll = long long;


int CASES = 0;
constexpr int MAX_PRICE = 10000;
constexpr int MAX_COINS = 100;
vector<int> coins;
vector<vector<pp>> mem;
constexpr int INF = (100*100+1);


pp minp (int ptp, int c){
  pp p_i = make_pair(INF, INF);
  if (c == 0 && ptp>0) return p_i;
  if (ptp <= 0) return pp(-ptp,0);
  if (mem[ptp][c] == p_i){
    int p = ptp - coins[c];
    pp sec = minp(p, c-1);
    pp val=  min(minp(ptp, c-1), pp(sec.first, sec.second+1));
    mem[ptp][c] = val;
  }

  return mem[ptp][c];
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
    mem.assign(ptp+1, vector<pp>(c+1, pp(INF, INF)));
    pp j =minp(ptp, c);

    std::cout << j.first+ptp << " "<< j.second<< '\n';
  }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo

*/
