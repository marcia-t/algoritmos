#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
constexpr int MAX_WEIGHT = 3000;
constexpr int MAX_LOAD = 3000;
constexpr int MAX_BOXES = 1000;
constexpr int INV = -1;


int mem[MAX_BOXES+1][MAX_WEIGHT+1];
int weights[MAX_WEIGHT];
int loads[MAX_LOAD];
//Guardo la cntidad de cajas que tengo y que voy a tener q recorrer
int a_boxes;


//load representa el resto de capacidad que me queda para llenar
int max_h(int box, int load){
    //si ya recorrí todas las cajas restantes.
    if (box == a_boxes) return 0;
    if (mem[box][load] == INV){
      //calculo el resultado de no usar la caja actual (paso a la siguiente caja con el mismo resto de carga disponible)
        int not_using =  max_h(box + 1, load);
        mem[box][load] = not_using;
        if (load >= weights[box]) //si todavía me queda lugar para apilar la que viene, hago la comparación entre usar y no usar la caja actual
            mem[box][load] = max(not_using, 1 + max_h(box + 1,
                                                      min(load - weights[box], loads[box])));
    }
    return mem[box][load];
}


int main(){
    while(cin >> a_boxes){
        if (a_boxes == 0) return 0;
        for (int i=0; i<a_boxes; i++){
            int w, l;
            cin >> w;
            cin >> l;
            weights[i] = w;
            loads[i] = l;
        }
        for (int i = 0; i <= a_boxes; ++i)
            for (int j = 0; j <= MAX_LOAD; ++j)
                mem[i][j] = INV;
        int highest = 0;
        
        for (int h=0; h<a_boxes;h++){
          //uso la primer caja (todas pueden ser la primera)
            highest = max(highest, max_h(h+1, loads[h])+1);
        }
        std::cout << highest << '\n';
    }
}
