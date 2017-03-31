#include <iostream>

#include <vector>

using namespace std;


vector<pair<int,int>> camino_actual;


vector<pair<int, int>> conecta_con(int inicio, vector<pair<int,int>> r){
    vector<pair<int, int>> rutas;
    for (int i = 0; i < r.size(); i++){
        if (inicio == r[i].first){
            rutas.push_back(r[i]);
        }
        else if (inicio == r[i].second){
            rutas.push_back(make_pair(r[i].second, r[i].first));
        }
    }
    return rutas;
}

bool existe_ruta(pair<int,int> r, vector<pair<int,int>> rutas){
    for (int i =0; i<rutas.size(); i++){
        if ((r.first == rutas[i].first && r.second == rutas[i].second) || (r.first == rutas[i].second && r.second == rutas[i].first )) return true;
    }
    return false;
}

int mejor_camino(int inicio, vector<pair<int,int>> r, vector<pair<int,int>> &ca, int mayor_camino){
    int mejor = 0;
    int ultimo;
    if (mayor_camino >= r.size()) return mayor_camino;
    vector<pair<int,int>>  rutas_conectadas = conecta_con(inicio,  r);
    for(int i= 0; i<rutas_conectadas.size(); i++){
        if (!existe_ruta(rutas_conectadas[i], ca)){
            ca.push_back(rutas_conectadas[i]);
            //mayor_camino = ca.size();
            ultimo = mejor_camino (rutas_conectadas[i].second, r, ca, mayor_camino);
            mayor_camino= max(mayor_camino, ultimo);
            ca.pop_back();
        }

    }
    mayor_camino = max(mayor_camino, (int)ca.size());
    return  mayor_camino;

}


int main() {
    int n, m;

    vector<pair<int,int>> rutas;

    while (cin >> n) {
        int mayor_camino = 0;
        //ya guardé en n la cantidad de nodos
        //guardo en m la cantidad de rutas
        cin >> m;

        //si llego al final
        if (n == 0 && m == 0) return 0;

        rutas.resize(m);
        //armo el vector de pares (rutas)
        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a;
            cin >> b;
            rutas[i] = make_pair(a, b);
        }

        //backtrack sobre cada nodo
        for (int i = 0; i < n; i++){
            vector<pair<int,int>> camino_actual;
            //recorro la salida desde cada nodo.
            //i es el nodo por donde empiezo, rutas son las rutas que armé arriba, camino_actual
            // son las rutas que usé,  0 es el mejor camino cuando empiezo a recorrer.

            int camino = mejor_camino(i, rutas,  camino_actual, 0);

            if (camino > mayor_camino) mayor_camino = camino;

        }
        cout << mayor_camino << '\n';

    }
}
