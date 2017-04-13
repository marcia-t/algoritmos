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
pair<int,int> MEJORES = make_pair(1000, 1000);
//bool visitados[1000][1000];


void   go(/*int maze[FILAS+1][COLS+1],*/ bool visitados[1000][1000],int fila, int columna, int proximo, int limite, int inicio){
    if (maze[fila][columna] != proximo || visitados[fila][columna] || fila<1 || columna <1 || fila > FILAS || columna > COLS || ENCONTRE){
        return;
    }
    if (fila == FILAS){
        if (inicio<MEJORES.first){
            MEJORES.first = inicio;
            MEJORES.second = columna;
        }
        else if (inicio==MEJORES.first && columna<MEJORES.second){
            MEJORES.second = columna;
        }
        return;
        /*ENCONTRE = true;
        COLUMNA_SALIDA = columna;
        return;*/
    }
    proximo++;
    if(proximo > limite) {
        proximo = 1;
        limite++;
    }
        visitados[fila][columna] = true;
        go(/*maze, */visitados,fila-1, columna, proximo, limite, inicio);
    go(/*maze, */visitados,fila, columna-1, proximo, limite, inicio);
    go(/*maze, */visitados, fila+1, columna, proximo, limite, inicio);
    go(/*maze, */visitados, fila, columna+1, proximo, limite, inicio);
    visitados[fila][columna] = false;

}


int main(){
    while (cin >> CASES){


        for (int c = 0; c<CASES; c++) {
            cin >> FILAS;
            cin >> COLS;
            MEJORES.first = 1000;
            MEJORES.second = 1000;
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
                go(/*maze,*/ visitados, 1, i, 1, 1, i);
                /*if (ENCONTRE) {
                    cout << "1 " << i << '\n';
                    std::cout << FILAS << " " << COLUMNA_SALIDA << '\n';
                    cout << '\n';
                    break;
                }*/
            }
            cout << "1 " << MEJORES.first << '\n';
            cout << FILAS << " " << MEJORES.second << '\n';
            cout << '\n';
        }

    }
}
