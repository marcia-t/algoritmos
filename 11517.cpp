#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;


constexpr int CASES = 0;
constexpr int MAX_PRICE = 10000;
constexpr int MAX_COINS = 100;
vector<int> coins;


int main (){
  cin >> CASES;
  for (int i = 0; i< CASES; i++){
    int ptp, int c;
    cin >> ptp;
    cin>> c;
    coins.resize(c);
    for (int i = 0; i < c; i++){
      int a;
      cin >>a;
      coins[i] = a;
    }

  }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo

*/
