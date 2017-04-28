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

bool matrizRutas[256][256];


vector<pair<int, int> > conecta_con(int inicio){
    vector<pair<int, int> > rutas;
    /*for (int i = 0; i < r.size(); i++){
        if (inicio == r[i].first){
            rutas.push_back(r[i]);
        }
        else if (inicio == r[i].second){
            rutas.push_back(make_pair(r[i].second, r[i].first));
        }
    }*/
    for (int i = 0; i<256; i++){
        if (matrizRutas[inicio][i]){
            rutas.push_back(make_pair(inicio , i));
        }
    }
    return rutas;
}


/*
Me fijo si una ruta existe (al derecho y al revés) en un arreglo de rutas
*/
bool existe_ruta(pair<int,int> r, bool matriz[256][256]){
    /*  for (int i =0; i<rutas.size(); i++){
          if ((r.first == rutas[i].first && r.second == rutas[i].second) || (r.first == rutas[i].second && r.second == rutas[i].first )) return true;
      }
      return false;*/
    return (matriz[r.first][r.second] || matriz[r.second][r.first]);
}

/*
Me fijo si el nodo ya existe entre las rutas que visité
*/
bool existe_nodo(int nodo, bool nodos[256]){
    /*  for (int i = 0; i<rutas.size(); i++){
          if (rutas[i].first == nodo || rutas[i].second == nodo){
              return true;
          }
      }
      return false;*/
    return (nodos[nodo]);
}

bool es_hamiltoniano(bool rutasVisitadas[256]){
    for (int i = 1; i<=n; i++){
        if (!existe_nodo(i, rutasVisitadas)) return false;
    }
    return true;
}




string armar_result(bool rutasVisitadas[256]){
    string resultado = "";
    for (int i =0; i<256; i++){
        /*  std::string r = std::to_string(camino[i].first);
          resultado = resultado + r + " ";
          if (i+1 == camino.size()){
              std::string r = std::to_string(camino[i].second);
              resultado = resultado + r;
          }*/
        if (rutasVisitadas[i]) {
            resultado = resultado + std::to_string(i);
        }
    }
    return resultado;
}

//en inicial veo desde dónde salgo para ver cuando llego al final
void ciclo(int inicial, int inicio, bool  matrizActual[256][256], bool nodosActuales[256], string resultado ){
    vector<pair<int,int> >  rutas_conectadas = conecta_con(inicio);
    //si en el camino actual tengo la misma cant de rutas que el total de rutas, llegué al final
    if (encontre) return;
    for(int i= 0; i<rutas_conectadas.size(); i++){
        if (!existe_ruta(rutas_conectadas[i], matrizActual) && !existe_nodo(rutas_conectadas[i].second, nodosActuales)){// ELSE si el nodo existe--> ver si llegue al final!

            matrizActual[rutas_conectadas[i].first][rutas_conectadas[i].second] = true;
            matrizActual[rutas_conectadas[i].second][rutas_conectadas[i].first] = true;
            nodosActuales[rutas_conectadas[i].second] = true;
            resultado = resultado + " " + std::to_string(rutas_conectadas[i].second);
            ciclo(inicial, rutas_conectadas[i].second, /*rutas,*/ matrizActual, nodosActuales, resultado);
            resultado = resultado.substr(0, resultado.length()-2);
            nodosActuales[rutas_conectadas[i].second] = false;
            matrizActual[rutas_conectadas[i].first][rutas_conectadas[i].second] = false;
            matrizActual[rutas_conectadas[i].second][rutas_conectadas[i].first] = false;

        }
        else {
            if (rutas_conectadas[i].second == inicial){
                //ca.push_back(rutas_conectadas[i]);
                if (es_hamiltoniano(nodosActuales)){
                    //string resultado = armar_result(nodosActuales);
                    resultado = resultado + " " + std::to_string(inicial);
                    std::cout << resultado << '\n';
                    encontre = true;
                }
                //ca.pop_back();
            }
        }
    }
    return;
}

void limpiarNodos(bool nodosActuales[256]){
    for (int i = 0; i< 256; i++){
        nodosActuales[i] =false;
    }
}


int main(){

    while (cin >> n){
        encontre = false;
        string a;
        bool matrizActual[256][256];
        bool nodosActuales[256];
        for (int i = 0; i< 256; i++){
            for (int j = 0; j< 256; j++){
                matrizRutas[i][j] = false;
                matrizActual[i][j] = false;
            }
            nodosActuales[i] =false;
        }


        while(!encontre)  {
            cin >> a;
            if (a == "%"){
                //break;
                for (int i = 1; i<=n; i++){
                    limpiarNodos(nodosActuales);
                    nodosActuales[i] = true;
                    string resultado = std::to_string(i);

                    ciclo(i, i, matrizActual, nodosActuales, resultado);
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
                //rutas.push_back(make_pair(c, b));

            }

        }
    }

}
