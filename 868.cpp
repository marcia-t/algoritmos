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
int COLUMNA_SALIDA;
bool ENCONTRE =false;
int maze[1000][1000];
//bool visitados[1000][1000];


void   go(/*int maze[FILAS+1][COLS+1],*/ bool visitados[1000][1000],int fila, int columna, int proximo, int limite){
    if (maze[fila][columna] != proximo || visitados[fila][columna] || fila<1 || columna <1 || fila > FILAS || columna > COLS || ENCONTRE){
        return;
    }
    if (fila == FILAS){
        ENCONTRE = true;
        COLUMNA_SALIDA = columna;
        return;
    }
    proximo++;
    if(proximo > limite) {
        proximo = 1;
        limite++;
    }
    visitados[fila][columna] = true;
    go(/*maze, */visitados,fila, columna-1, proximo, limite);
    go(/*maze, */visitados, fila+1, columna, proximo, limite);
    go(/*maze, */visitados, fila, columna+1, proximo, limite);
    visitados[fila][columna] = false;

}


int main(){
    while (cin >> CASES){


        for (int c = 0; c<CASES; c++) {
            cin >> FILAS;
            cin >> COLS;
            ENCONTRE = false;
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
                go(/*maze,*/ visitados, 1, i, 1, 1);
                if (ENCONTRE) {
                    cout << "1 " << i << '\n';
                    std::cout << FILAS << " " << COLUMNA_SALIDA << '\n';
                    cout << '\n';
                    break;
                }
            }
        }

    }
}
