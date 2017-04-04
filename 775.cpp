#include <iostream>

#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;

int n = 0;

vector<pair<int, int> > conecta_con(int inicio, vector<pair<int,int> > r){
    vector<pair<int, int> > rutas;
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


/*
Me fijo si una ruta existe (al derecho y al revés) en un arreglo de rutas
*/
bool existe_ruta(pair<int,int> r, vector<pair<int,int> > rutas){
    for (int i =0; i<rutas.size(); i++){
        if ((r.first == rutas[i].first && r.second == rutas[i].second) || (r.first == rutas[i].second && r.second == rutas[i].first )) return true;
    }
    return false;
}

/*
Me fijo si el nodo ya existe entre las rutas que visité
*/
bool existe_nodo(int nodo, vector<pair<int, int> > rutas){
    for (int i = 0; i<rutas.size(); i++){
        if (rutas[i].first == nodo || rutas[i].second == nodo){
            return true;
        }
    }
    return false;
}

bool paso_x_todos(vector<pair<int,int> > ca){
    for (int i = 1; i<=n; i++){
        if (!existe_nodo(i, ca)) return false;
    }
    return true;
}

bool es_hamiltoniano(vector<pair<int, int> > rutas){
    return paso_x_todos(rutas);
}


string armar_result(vector <pair<int,int>> camino){
  string resultado = "";
  for (int i =0; i<camino.size(); i++){
    std::string r = std::to_string(camino[i].first);
    resultado = resultado + r + " ";
    if (i+1 == camino.size()){
      std::string r = std::to_string(camino[i].second);
      resultado = resultado + r;
    }
  }
return resultado;
}

//en inicial veo desde dónde salgo para ver cuando llego al final
void ciclo(int inicial, int inicio, vector<pair<int,int> > rutas, vector<pair<int,int> > &ca){
    vector<pair<int,int> >  rutas_conectadas = conecta_con(inicio,  rutas);
    //si en el camino actual tengo la misma cant de rutas que el total de rutas, llegué al final
    for(int i= 0; i<rutas_conectadas.size(); i++){
        if (!existe_ruta(rutas_conectadas[i], ca) && !existe_nodo(rutas_conectadas[i].second, ca)){// ELSE si el nodo existe--> ver si llegue al final!
            ca.push_back(rutas_conectadas[i]);
            ciclo(inicial, rutas_conectadas[i].second, rutas, ca);
            ca.pop_back();
        }
        else if(!existe_ruta(rutas_conectadas[i], ca) && existe_nodo(rutas_conectadas[i].second, ca)){
            if (rutas_conectadas[i].second == inicial){
                ca.push_back(rutas_conectadas[i]);
                if (es_hamiltoniano(ca)){
                  string resultado = armar_result(ca);
                  std::cout << resultado << '\n';
                }
                ca.pop_back();
            }
        }
    }
    //std::cout << "N" << '\n';
    return;
}
/*
bool hay_camino(vector <pair<int, int> >  rutas){
  std::cout << "haycamino" << '\n';
  vector <pair<int, int> > camino;
  for (int i = 1; i<=n; i++){
    std::cout << "entro al for" << '\n';
      vector<pair<int,int> > camino_actual;
      camino = ciclo(i, i, rutas, camino_actual);
      for (int j = 0; j<camino.size(); j++){
        std::cout << camino[i].first << " " << camino[i].second << '\n';
      }
      if (camino.size()>0) return true;
  }
  return false;
}*/


int main(){
    vector <pair<int, int> > rutas;
    while (cin >> n){
        string a, b;
        while(cin >> a) {
            if (a == "%"){
              //if (!hay_camino(rutas)) std::cout << "N" << '\n';
              for (int i = 1; i<=n; i++){
                vector <pair<int, int> > camino_actual;
                ciclo(i, i, rutas, camino_actual);
              }
            }
            else {
                int b;
                cin >> b;
                int c =   std::atoi( a.c_str() );
                rutas.push_back(make_pair(c, b));
            }
        }
        n = 0;
    }

}
