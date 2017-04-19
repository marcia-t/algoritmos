#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
using pp = pair<int,int>;
using ull = unsigned long long;



int CASES = 0;
constexpr int MAX_OBJECTS = 1000;
constexpr int MAX_PEOPLE = 100;
constexpr int MAX_WEIGHT = 30;
//int mem[MAX_WEIGHT][MAX_OBJECTS];
vector<vector<ull>> mem;
vector<pp> pw;
constexpr ull INF = ~0;

ull win (int w, int n){
    if (n == 0 || w == 0) return 0;
    if (w<0) return INF;
    pp pair =  pw[n];
    if(mem[w][n] == INF){
        mem[w][n] = max(pair.first+win(w-pair.second, n-1), win(w, n-1));
    }
    return mem[w][n];
}


int main(){
    cin >> CASES;

    for (int  i = 0; i < CASES; i++){
        mem.assign(MAX_WEIGHT+1, vector<ull>(MAX_OBJECTS, INF));
        int max_t = 0;
        int objs, people;
        cin >> objs;
        for (int j = 0; j<objs; j++){
            int p, w;
            cin >> p;
            cin >> w;
            pp pair = make_pair(p,w);
            pw.push_back(pair);
        }
        cin >> people;
        for (int j = 0; j<people; j++){
            int mw;
            cin >> mw;
            ull max = win(mw, objs-1);
            max_t = max_t + max;
        }
        std::cout << max_t << '\n';
    }
}
