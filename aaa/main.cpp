#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;


int CASES = 0;
constexpr int MAX_PRICE = 10000;
constexpr int MAX_COINS = 100;
vector<int> coins;
int mem[MAX_PRICE][MAX_COINS];
int mem_c[MAX_PRICE];
constexpr int INF = (100*100+1);


int minp (int ptp, int c){
    if (c == 0 && ptp>0) return INF;
    if (ptp <= 0) return -ptp;
    if (mem[ptp][c] == INF){
        int p = ptp - coins[c];
        int val=  min(minp(ptp, c-1), minp(p,c-1));
        mem[ptp][c] = val;
    }

    return mem[ptp][c];
}

int qcoins (int ptp, int c){
    if (c == 0)  return INF;
    if (ptp<= 0) return 0;

    if(mem_c[ptp] == INF){
        int val = ptp - coins[c];
        int no_uso = qcoins(ptp, c-1);
        int uso=1+qcoins(val, c-1);
        mem_c[ptp] = min(no_uso, uso);
    }
    return mem_c[ptp];
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
        for(int i = 0; i <= MAX_PRICE; i++) {
            for(int j = 0; j < MAX_COINS; j++) {
                mem[i][j] = INF;
            }
        }
        int j =minp(ptp, c);
        for(int i = 0; i <= MAX_PRICE; i++) {

            mem_c[i] = INF;

        }
        int co = qcoins(j+ptp, c);
        std::cout << j+ptp << " " << co << '\n';

    }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo
*/
