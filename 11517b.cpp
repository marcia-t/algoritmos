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
//vector<int> coins;
struct response_t {
    int ptp;
    int c;
};
constexpr int INF = (100*100+1);
response_t p_i = {INF, INF};

int coins[MAX_COINS];
response_t mem[MAX_PRICE][MAX_COINS];
//vector<vector<response_t>> mem;


response_t min2 (response_t v1, response_t v2) {
    if ((v1.ptp < v2.ptp) || (v1.ptp == v2.ptp && v1.c <= v2.c)){
        return v1;
    } else return v2;
}

response_t minp2 (int ptp, int c){
    if (c == 0 && ptp>0) return p_i;
    if (ptp <= 0) return {-ptp,0};x
    if (mem[ptp][c].ptp != INF) {
      return mem[ptp][c];
    }
    response_t first = minp2(ptp, c-1);
    response_t sec = minp2(ptp - coins[c], c-1);
    sec.c++;
    return min2(first, sec);
}



int main (){
    response_t inf_matrix[MAX_PRICE][MAX_COINS];
    for(int i = 0; i < MAX_PRICE; i++) {
        for(int j = 0; j < MAX_COINS; j++) {
            inf_matrix[i][j] = p_i;
        }
    }


    cin >> CASES;
    for (int i = 0; i< CASES; i++){
        int ptp, c;
        cin >> ptp;
        cin >> c;
        int a;
        for (int i = 1; i <= c; i++){
            cin >> a;
            coins[i] = a;
        }


        memcpy ( &mem, &inf_matrix, sizeof(inf_matrix) );

        response_t min_response = minp2(ptp, c);

        //ll co = qcoins(j+ptp, c);
        std::cout << min_response.ptp+ptp << " " << min_response.c << '\n';
        //std::cout << co << '\n';
    }
}
/*
lo que tengo q pagar nunca va a ser más caro que 10000
tengo q buscar el mínimo

*/
