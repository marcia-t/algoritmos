#include <iostream>

#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;

int n = 0;
bool encontre = false;

constexpr int MAX_R = 256;
bool matrizRutas[MAX_R][MAX_R];

/*Retorna una lista de pares que conectan con un nodo (por def no son más de tres)*/
vector<pair<int, int> > conecta_con(int inicio){
    vector<pair<int, int> > rutas;
    for (int i = 0; i<MAX_R; i++){
        if (matrizRutas[inicio][i]){
            rutas.push_back(make_pair(inicio , i));
        }
    }
    return rutas;
}


/*
Me fijo si una ruta existe (al derecho y al revés) en una matriz de rutas
*/
bool existe_ruta(pair<int,int> r, bool matriz[MAX_R][MAX_R]){
    return (matriz[r.first][r.second] || matriz[r.second][r.first]);
}

/*
Me fijo si el nodo ya existe entre los nodos que visité
*/
bool existe_nodo(int nodo, bool nodos[MAX_R]){
    return (nodos[nodo]);
}

/*me fijo si el camino es hamiltoniano todos los nodos existentes están entre los nodos visitados*/
bool es_hamiltoniano(bool nodosVisitados[MAX_R]){
    for (int i = 1; i<=n; i++){
        if (!existe_nodo(i, nodosVisitados)) return false;
    }
    return true;
}


//en inicial veo desde dónde salgo para ver cuando llego al final
void ciclo(int inicial, int inicio, bool  matrizActual[MAX_R][MAX_R], bool nodosActuales[MAX_R], string resultado ){
    vector<pair<int,int> >  rutas_conectadas = conecta_con(inicio);
    if (encontre) return;
    for(int i= 0; i<rutas_conectadas.size(); i++){
        if (!existe_ruta(rutas_conectadas[i], matrizActual) && !existe_nodo(rutas_conectadas[i].second, nodosActuales)){
            matrizActual[rutas_conectadas[i].first][rutas_conectadas[i].second] = true;
            matrizActual[rutas_conectadas[i].second][rutas_conectadas[i].first] = true;
            nodosActuales[rutas_conectadas[i].second] = true;
            resultado = resultado + " " + std::to_string(rutas_conectadas[i].second);

            ciclo(inicial, rutas_conectadas[i].second,  matrizActual, nodosActuales, resultado);

            resultado = resultado.substr(0, resultado.length()-2);
            nodosActuales[rutas_conectadas[i].second] = false;
            matrizActual[rutas_conectadas[i].first][rutas_conectadas[i].second] = false;
            matrizActual[rutas_conectadas[i].second][rutas_conectadas[i].first] = false;
        }
        else {
            if (rutas_conectadas[i].second == inicial){
                if (es_hamiltoniano(nodosActuales)){
                    resultado = resultado + " " + std::to_string(inicial);
                    std::cout << resultado << '\n';
                    encontre = true;
                }
            }
        }
    }
    return;
}


int main(){

    while (cin >> n){
        encontre = false;
        string a;
        bool matrizActual[MAX_R][MAX_R];
        bool nodosActuales[MAX_R];
        for (int i = 0; i< MAX_R; i++){
            for (int j = 0; j< MAX_R; j++){
                matrizRutas[i][j] = false;
                matrizActual[i][j] = false;
            }
            nodosActuales[i] =false;
        }
        while(!encontre)  {
            cin >> a;
            if (a == "%"){
                for (int i = 1; i<=n; i++){
                    nodosActuales[i] = true;
                    string resultado = std::to_string(i);
                    ciclo(i, i, matrizActual, nodosActuales, resultado);
                    nodosActuales[i] = false;
                    if (encontre) i = n+1;
                }
                if (!encontre) {std::cout << "N" << '\n';
                    break;};
            }
            else {
                int b;
                cin >> b;
                int c =   std::atoi( a.c_str() );
                matrizRutas[c][b] = true;
                matrizRutas[b][c] = true;
            }
        }
    }
}
