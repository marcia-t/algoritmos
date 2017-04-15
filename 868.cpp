#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
int CASES;
int FILAS;
int COLS;
int maze[1000][1000];
pair<int,int> MEJORES = make_pair(1000, 1000);

/*
visitados es una matriz que mantiene registro de los puntos visitados en el laberinto
fila y columna son las actuales en las que me encuentro
proximo es el próximo número de la secuencia y límite es dónde debe termina la secuencia actual
en inicio guardo por qué columna empiezo a recorrer para guardar el valor
*/
void   go(bool visitados[1000][1000],int fila, int columna, int proximo, int limite, int inicio){
    //si el nro actual no condice con el próximo a visitar, si ya pasé por este punto, o si fila o columna no son válidas (se salen
  //del rango por ejemplo), salgo.
    if (maze[fila][columna] != proximo || visitados[fila][columna] || fila<1 || columna <1 || fila > FILAS || columna > COLS){
        return;
    }
    //si la fila actual es igual al total de filas del caso, guardo los valores de entrada y
    //salida (sólo si son más pequeños que los anteriores que se
  //hayan guardado) y salgo
    if (fila == FILAS){
        if (inicio<MEJORES.first){
            MEJORES.first = inicio;
            MEJORES.second = columna;
        }
        else if (inicio==MEJORES.first && columna<MEJORES.second){
            MEJORES.second = columna;
        }
        return;
    }

    /*si no salí antes, muevo todos los valores (ya que estoy en la posición correcta)*/
    proximo++;
    if(proximo > limite) {
        proximo = 1;
        limite++;
    }
    /*marco el  pto actual como visitado y veo si puedo seguir hacia algún pto adyacente*/
    visitados[fila][columna] = true;
    go(visitados,fila-1, columna, proximo, limite, inicio);
    go(visitados,fila, columna-1, proximo, limite, inicio);
    go(visitados, fila+1, columna, proximo, limite, inicio);
    go(visitados, fila, columna+1, proximo, limite, inicio);
    visitados[fila][columna] = false;

}

/*
No sabía cuál era el tamaño mayor del laberinto, y asumí que no habría uno mayor a 1000x1000
*/
int main(){
    while (cin >> CASES){


        for (int c = 0; c<CASES; c++) {
            cin >> FILAS;
            cin >> COLS;
            MEJORES.first = 1000;
            MEJORES.second = 1000;
            bool visitados[1000][1000];
            for (int i = 1; i <= FILAS; i++) {
                for (int j = 1; j <= COLS; j++) {
                    int a;
                    cin >> a;
                    maze[i][j] = a;
                    visitados[i][j] = false;
                }
            }

            for (int i = 1; i <= COLS; i++) {
                go(visitados, 1, i, 1, 1, i);
            }

            if (c!=0) cout << '\n';
            cout << "1 " << MEJORES.first << '\n';
            cout << FILAS << " " << MEJORES.second << '\n';

        }

    }
}
