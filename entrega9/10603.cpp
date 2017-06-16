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
};

struct node {
  jug a;
  jug b;
  jug c;
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
    case 2:
      t.b = j;
    case 3:
      t.c = j;
  }
  return t;
}

//1:a, 2:b, 3:c
jug get(int n, node t){
  switch (n) {
    case 1:
      return t.a;
    case 2:
      return t.b;
    case 3:
      return t.c;
  }
}

//1:a, 2:b, 3:c
//precond: asumo que ya chequeé que las cantidades permiten pasar de p a q.
node pass_from_to (int p, int q, node t){
  jug from = get(p,t);
  jug to = get(q,t);
  int ct = to.load - to.filled;
  int cf = from.filled - ct;
  std::cout << "ct:" << ct << '\n';
      std::cout << "cf:" << cf << '\n';
  if(ct <= cf) {

    to.filled+=cf;
    from.filled-=cf;
  }
  t = set_jug_node(p,from,t);
  t =set_jug_node(q,to,t);
  return t;
}

//neighbor: peso + vecino
using nb = pair<int,node>;

int a, b, c, d;



int main(){
  node uno = create_node(3, 0, 4, 0, 5, 5);
  node dos = pass_from_to(3, 1, uno);
  std::cout << dos.a.load << "  " << dos.a.filled << '\n';
  std::cout << dos.b.load << "  " << dos.b.filled << '\n';
  std::cout << dos.c.load << "  " << dos.c.filled << '\n';

  std::cout << uno.a.load << "  " << uno.a.filled << '\n';
  std::cout << uno.b.load << "  " << uno.b.filled << '\n';
  std::cout << uno.c.load << "  " << uno.c.filled << '\n';
  /*int n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    node ini = create_node(a, 0, b, 0, c, c);

  }*/
}
