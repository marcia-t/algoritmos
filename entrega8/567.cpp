#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
#include<list>

using namespace std;
using vi = vector<int>;
using graph = vector<vi>;
constexpr int UNDEFINED = -1;
constexpr int INF = 21;

/*
Complejidad
Siendo n la cantidad de vértices (en este caso 20), la complejidad de este algoritmo resulta en O(n^3)
ya que se realizan 3 recorridos de tamaño n para calcular cada distancia (la operación no suma pues son accesos O(1)).
*/

int main(){
    graph distance;

    int n;
    int m= 0;
    while(scanf("%d", &n)!=EOF){
        m++;
        distance.assign(21,  vi(21, INF));
        for (size_t i = 0; i < n ; i++) {
            int d;
            cin >> d;
            distance[1][d] = 1;
            distance[d][1] = 1;
        }
        for (size_t j = 2; j < 20; j++) {
            int p;
            cin >> p;
            for (size_t h = 0; h < p; h++) {
                int q;
                cin >> q;
                distance[j][q] = 1;
                distance[q][j] = 1;
            }
        }

        //calculo la matriz de distancias con FloydWarshall;
        for(int z = 1; z <= 20; ++z) for(int v = 1; v <= 20; ++v) for(int w = 1; w <= 20; ++w)
                    distance[v][w] = min(distance[v][w], distance[v][z] + distance[z][w]);

        //cant de casos a probar
        cin >> n;

        //output de los resultados
        std::cout << "Test Set #" << m << '\n';
        for (size_t v  = 0; v  < n; v ++) {
            int a, b;
            cin >> a; cin >> b;
            if (a<10)  std::cout << " " << a;
            else std::cout << a;
            cout << " to ";
            if (b<10)  std::cout << " " << b;
            else std::cout << b;
            cout <<": "<< distance[a][b]<< '\n';
        }

        std::cout  << '\n';



    }
}
