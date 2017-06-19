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

using namespace std;

struct jug {
    int load;
    int filled;
    bool operator==(const jug& a) const
      {
          return (load == a.load && filled == a.filled);
      }
};

struct node {
    jug a;
    jug b;
    jug c;
    bool operator==(const node& nn) const
      {
          return (a == nn.a && b == nn.b && c == nn.c);
      }
};

jug create_jug (int load, int filled){
    jug j;
    j.load = load;
    j.filled = filled;
    return j;
}

node create_node (int a, int fa, int b,int fb, int c, int fc){
    jug aa = create_jug(a, fa);
    jug bb = create_jug(b, fb);
    jug cc = create_jug(c, fc);
    node n;
    n.a = aa; n.b=bb; n.c =cc;
    return n;
}

//1:a, 2:b, 3:c
node set_jug_node(int n, jug j, node t){
    switch (n) {
        case 1:
            t.a = j;
            break;
        case 2:
            t.b = j;
            break;
        case 3:
            t.c = j;
            break;
    }
    return t;
}

//1:a, 2:b, 3:c
jug get_jug(int n, node t){
    switch (n) {
        case 1:
            return t.a;
        case 2:
            return t.b;
        case 3:
            return t.c;
    }
}

//ojo: tengo que guardar la cantidad de lo que pasé
//1:a, 2:b, 3:c
//retorna un par que tiene la cantidad de litros pasados y el nodo modificado
//precond: asumo que ya chequeé que las cantidades permiten pasar de p a q.
pair<int,node> pass_from_to (int p, int q, node t){
    int sent;
    jug from = get_jug(p,t);
    jug to = get_jug(q,t);
    int ct = to.load - to.filled; //lugar que tengo en to
    int cf = from.filled; //lìquido disponible que tengo en from
    //tengo cf y quiero pasar a ct
    //cant a pasar: ct.
    //filled en from es filled-ct (filled menos lo que voy a pasar)
    if(ct <= cf) {
        to.filled+=ct;
        from.filled-=ct;
        sent = ct;
    }
    else {
        to.filled+=cf;
        from.filled = 0;
        sent=cf;
    }
    t = set_jug_node(p,from,t);
    t = set_jug_node(q,to,t);
    return make_pair(sent, t);
}

//neighbor(pi): peso + vecino
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;
using equiv = vector<node> ;
int a, b, c, d;
graph G;



int main(){
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
      cin >> a >> b >> c >> d;
      node ini = create_node(a, 0, b, 0, c, c);
    }
}
