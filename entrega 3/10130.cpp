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
constexpr int MAX_OBJECTS = 1000;
constexpr int MAX_PEOPLE = 100;
constexpr int MAX_WEIGHT = 30;
//la memoria guarda valores [w][n]-> para el peso w, el máximo de objetos desde n que puedo llevar (sin repetir)
vector<vector<ll>> mem;
//en pw guardo los pares Precio y Peso de los objetos
vector<pp> pw;
constexpr ll INF = -(10*10+1);

//retorna el mayor valor de dinero a gastar para el peso w(de cierta persona)
// para todos los objetos empezando por n y disminuyendo hasta cero
ll win (int w, int n){
    if (w<0) return INF;
    if (n == 0 || w == 0) return 0;
    pp pair =  pw[n];
    if(mem[w][n] == INF){
      //en mem[w][n] guardo el máximo entre usar el objeto y no usarlo
      //usarlo implica sumarle al precio que ya tengo, el resultado de ejecutar win restando el peso disponible con los
      //objetos desde n-1  hasta 0.
      mem[w][n] = max(pair.first+win(w-pair.second, n-1), win(w, n-1));
    }
    return mem[w][n];
}


int main(){
    cin >> CASES;

    for (int  i = 0; i < CASES; i++){
        mem.assign(MAX_WEIGHT+1, vector<ll>(MAX_OBJECTS, INF));
        int max_t = 0;
        int objs, people;
        cin >> objs;
        pw.resize(objs+1);
        for (int j = 1; j<=objs; j++){
            int p, w;
            cin >> p;
            cin >> w;
            pp pair = make_pair(p,w);
            pw[j]= pair;
        }
        cin >> people;
        for (int j = 0; j<people; j++){
            int mw;
            cin >> mw;
            ll max = win(mw, objs);
            //acumulo los gastos de todas las personas en maX_t
            max_t = max_t + max;
        }
        std::cout << max_t << '\n';
    }
}
