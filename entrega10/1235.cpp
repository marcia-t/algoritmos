#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;

/*
COMPLEJIDAD
El algoritmo de Prim implementado con colas de prioridad tiene complejidad O(m log n) con:
n: cantidad de vértices (n)
m: cantidad de aristas (n(n-1)/2)
La cantidad de vértices estará dada por la cantidad de códigos, N.
Cada vértice estará conectado con el resto de los vértices,
formando un grafo completo con n(n-1)/2 aristas.
Si el cero no llegara a estar entre los códigos, para calcular el peso tendremos O(n) (recorrer todos los códigos)
Entonces, en el peor caso, el algoritmo tendrá complejidad O(m log n) + O(n).
*/

constexpr int INF = 1000*1000;
vector<int> codes;
bool zero_exists = false;
int counter;
graph G;
vector<int> DIST;
vector<bool> VISITED;


struct node {
    int a;
    int b;
    int c;
    int d;
    node() {}
    node(int A, int B, int C, int D) : a(A), b(B), c(C), d(D) {}
    bool operator==(const node& nn) const
    {
        return (a == nn.a && b == nn.b && c == nn.c && d == nn.d);
    }
    bool operator < (const node &n) const {
        if (a < n.a) return true;
        else if (a == n.a) {
            if (b < n.b) return true;
            else if (b == n.b) {
                if (c < n.c) return true;
                else if (c == n.c) return d < n.d;
                else return false;
            }
        }
        else return false;
    }
};

using equiv_int_n = map<int, node>;
equiv_int_n key_node;

void print (node n){
    std::cout << n.a << " " << n.b << " " << n.c << " " << n.d << '\n';
}

node set_node(int number){
    int digit = number%10;
    number /= 10;
    int d = digit;
    digit = number%10;
    number /= 10;
    int c = digit;
    digit = number%10;
    number /= 10;
    int b = digit;
    digit = number%10;
    number /= 10;
    int a = digit;
    node n= node(a,b,c,d);
    return n;
}

int calculate (int a, int b){
    int up, down;
    if (a<b) up = b-a;
    else up=10-a+b;
    if (a<b) down=a+10-b;
    else down=a-b;
    return (min(up,down));
}

int calculate_t (node n, node m){
    int aa = calculate(n.a,m.a);
    int bb = calculate(n.b,m.b);
    int cc = calculate(n.c,m.c);
    int dd = calculate(n.d,m.d);
    return aa+bb+cc+dd;
}

void create_key_map(){
    for (size_t i = 0; i < codes.size(); i++) {
        node n = set_node(codes[i]);
        key_node[counter] = n;
        counter++;
    }
}

void process_codes(){
    create_key_map();
    for (size_t i = 0; i < counter; i++) {
        node n = key_node[i];
        node m;
        for (size_t j = i+1; j  < counter; j++) {
            m =  key_node[j];
            int d = calculate_t(n,m);
            G[i].push_back(pi(d,j));
            G[j].push_back(pi(d,i));
        }
    }
}

int calculate_zero_distance(){
  int d = INF;
  node m = node(0,0,0,0);
  for (size_t i = 0; i < codes.size(); i++) {
      node n = set_node(codes[i]);
      d = min(d, calculate_t(n,m));
  }
  return d;
}


int prim(){
    int u,w;
    int min_rolls = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(pi(0, 0));
    DIST[0] = 0;
    while (!pq.empty()) {
        pi front = pq.top(); pq.pop();
        u = front.second, w = front.first;
        if (!VISITED[u]){
            VISITED[u] = true;
            min_rolls = min_rolls+w;
            for (pi v : G[u]) {
                if (!VISITED[v.second] && DIST[v.second] > v.first){
                    DIST[v.second] = v.first;
                    pq.push(pi(v.first, v.second));
                }
            }
        }
    }
    int z = 0;
    if(!zero_exists) z = calculate_zero_distance();
    return min_rolls+z;
}



int main(){
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        int n;
        cin >> n;
        counter = 0;
        G.assign(n+1,vpi());
        key_node.clear();
        DIST.assign(n+1, INF);
        VISITED.assign(n+1, false);
        codes.clear();
        zero_exists = false;
        for (size_t j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (c == 0000) zero_exists = true;
            codes.push_back(c);
        }
        process_codes();
        std::cout << prim() << '\n';
    }
}
