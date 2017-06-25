#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>

using namespace std;
//neighbor(pi): peso + vecino
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;

constexpr int INF = 1000*1000;
int a, b, c, d, counter;
graph G;
vector<vector<int>> resol;

struct node {
    int a;
    int b;
    int c;
    node() {}
    node(int A, int B, int C) : a(A), b(B), c(C) {}
    bool operator==(const node& nn) const
    {
        return (a == nn.a && b == nn.b && c == nn.c);
    }
    bool operator < (const node &n) const {
        if (a < n.a) return true;
        else if (a == n.a) {
            if (b < n.b) return true;
            else if (b == n.b) return c < n.c;
            else return false;
        }
        else return false;
    }
};
void print (node n){
    std::cout << "(" << a << ", " << n.a << "),  ("<< b << ", "<< n.b << "), (" << c << ", "<< n.c <<  ")"<<'\n';
}

using equiv_n_int = map<node, int>;
using equiv_int_n = map<int,node>;
equiv_n_int node_key;
equiv_int_n key_node;

//en la pos n  del nodo t setear el valor j
node set_value_node(char n, int j, node t){
    switch (n) {
        case 'a':
            t.a = j;
            break;
        case 'b':
            t.b = j;
            break;
        case 'c':
            t.c = j;
            break;
    }
    return t;
}

//1:a, 2:b, 3:c
//get el valor a b o c del nodo t
int get_value(char val, node t){
    switch (val) {
        case 'a':
            return t.a;
        case 'b':
            return t.b;
        case 'c':
            return t.c;
    }
}

int get_load(char val){
    switch (val) {
        case 'a':
            return a;
        case 'b':
            return b;
        case 'c':
            return c;
    }
}

int closest_to_d (node t){
    int res = INF;
    int dif = INF;
    if (t.a <= d && d-t.a <= dif) {
      dif = min (dif, d-t.a);
      res = t.a;
    }
    if (t.b <= d && d-t.b <= dif) {
      dif = min (dif, d-t.b);
      res = t.b;
    }
    if (t.c <= d && d-t.c <= dif) {
      dif = min (dif, d-t.c);
      res = t.c;
    }
    return res;
}

//ojo: tengo que guardar la cantidad de lo que pasé
//1:a, 2:b, 3:c
//retorna un par que tiene la cantidad de litros pasados y el nodo modificado
pair<int,node> pass_from_to (char p, char  q, node t){
    int sent;
    int from = get_value(p,t);
    int to = get_value(q,t);
    int ct = get_load(q) - to; //lugar que tengo en to
    int cf = from; //lìquido disponible que tengo en from
    //tengo cf y quiero pasar a ct
    //cant a pasar: ct.
    //filled en from es filled-ct (filled menos lo que voy a pasar)
    if(ct <= cf) {
        to+=ct;
        from-=ct;
        sent = ct;
    }
    else {
        to+=cf;
        from = 0;
        sent=cf;
    }
    t = set_value_node(p,from,t);
    t = set_value_node(q,to,t);
    return make_pair(sent, t);
}

void calculate_new_node(pair<int,node> ln, int k){
  node_key[ln.second] = counter;
  key_node[counter] = ln.second;
  counter++;
  int nb_k = node_key[ln.second]; //es lo mismo q counter-1
  G[k].push_back(pi(ln.first, nb_k));
}

void calculate_existing_node(pair<int,node> ln, int k){
  int nb_k = node_key[ln.second];
  G[k].push_back(pi(ln.first, nb_k));
}



void add_to_res(node t){
  int de = closest_to_d(t);
  if (de != INF){
    int ref = node_key[t];
    resol[de].push_back(ref);
  }
}

/*
En cada nodo tengo que:
pasar 1 a 2, 1 a 3, 2 a 1, 2 a 3, 3 a 1, 3 a 2
creo el nodo de cada uno
me fijo si existe entre en el mapa
si no existe, la agrego, y agrego el nodo actual a los vecinos del padre
si ya existe, no lo agrego a las equiv pero sí lo agrego a los vecinos del padre (lo busco en las equiv y lo agrego)
*/
//n será vecino de todos los que encuentre y viceversa tmb
//si ya existe, lo tengo que guardar igual entre los vecinos del padre.
void create_nb(node n){
    //k es la clave de n, voy a agregar las adyacencias en G[k]...(peso,vecino);
    int k = node_key[n];
    add_to_res(n);
    auto ln1= pass_from_to('a','b',n);
    if (ln1.first != 0){
      if (node_key.count(ln1.second) > 0) calculate_existing_node(ln1,k);
      else {
        calculate_new_node(ln1,k);
        create_nb(ln1.second);
        add_to_res(ln1.second);
      }
    }
    auto ln2= pass_from_to('a','c',n);
    if (ln2.first != 0){
      if (node_key.count(ln2.second) > 0) calculate_existing_node(ln2,k);
      else {
        calculate_new_node(ln2,k);
        create_nb(ln2.second);
        add_to_res(ln2.second);
      }
    }
    auto ln3= pass_from_to('b','a',n);
    if (ln3.first != 0){
      if (node_key.count(ln3.second) > 0) calculate_existing_node(ln3,k);
      else {
        calculate_new_node(ln3,k);
        create_nb(ln3.second);
        add_to_res(ln3.second);
      }
    }
    auto ln4= pass_from_to('b','c',n);
    if (ln4.first != 0){
      if (node_key.count(ln4.second) > 0) calculate_existing_node(ln4,k);
      else {
        calculate_new_node(ln4,k);
        create_nb(ln4.second);
        add_to_res(ln4.second);
      }
    }
    auto ln5= pass_from_to('c','a',n);
    if (ln5.first != 0){
      if (node_key.count(ln5.second) > 0) calculate_existing_node(ln5,k);
      else {
        calculate_new_node(ln5,k);
        create_nb(ln5.second);
        add_to_res(ln5.second);
      }
    }
    auto ln6= pass_from_to('c','b',n);
    if (ln6.first != 0){
      if (node_key.count(ln6.second) > 0) calculate_existing_node(ln6,k);
      else {
        calculate_new_node(ln6,k);
        create_nb(ln6.second);
        add_to_res(ln6.second);
      }
    }
}

void create_graph(node ini){
    node_key[ini] = counter;
    key_node[counter] = ini;
    counter++;
    create_nb(ini);
}

//cada arista es peso + vecino
vector<int> dijkstra(int from) {
    vector<int> dist(G.size(), INF);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, from});
    while(not q.empty()) {
        auto u = q.top();
        q.pop();
        if(dist[u.second] < INF) continue;
        dist[u.second] = u.first;
        for(auto v : G[u.second]) if(dist[v.second] == INF) {
            q.push({u.first + v.first, v.second});
        }
    }
    return dist;
}

int main(){
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        counter = 0;
        cin >> a >> b >> c >> d;
        resol.assign(d+1, vector<int>());
        node ini = node(0,0,c);
        node_key.clear();
        key_node.clear();
        G.assign(10000, vpi());
        create_graph(ini);
        auto dij = dijkstra(0);
        bool head = false;
        for (size_t i = d; i > 0; i--) {
          if (!resol[i].empty()){
            int mini = INF;
            for (size_t j = 0; j < resol[i].size(); j++) {
              mini = min (dij[resol[i][j]], mini);
            }
            std::cout << mini << " " << i << '\n';
            head = true;
            break;
          }
        }
        if (!head)
        std::cout << "0 0" << '\n';
    }
}
