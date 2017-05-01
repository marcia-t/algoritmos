#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;
int p, q, r, s, t, u;
constexpr double pres = 0.0000001; //me pide presición de al menos 4 decimales

//resuelvo la ecuación
double solve_eq(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double solve(){
  //defino las cotas
    double min = 0;
    double max = 1;
    //mientras exista una diferencia entre el mínimo y el máximo sigo buscando

    while (min + pres < max){
      //busco el pto medio entre las cotas
        double test = (min + max) / 2;
        //resuelvo la función para ese pto
        double r_test = solve_eq(test);

        //reemplazo la cota correspondiente
        if (r_test > 0) min = test;
        else if (r_test < 0) max = test;
        else return r_test; //caso en el que encontremos la raíz exacta
    }
    //si llego a la mínima diferencia, devuelvo el punto medio
    return (min+max)/2;
}


int main(){
    while(scanf("%d", &p)!=EOF){
        cin >> q >> r >> s >> t >> u;
        if ((solve_eq(0) > 0 && solve_eq(1) > 0) || (solve_eq(0) < 0 && solve_eq(1) < 0)){
            std::cout << "No solution" << '\n';
        }
        else{
            std::cout << setprecision(4) << fixed << solve() << '\n';
        }
    }
}
