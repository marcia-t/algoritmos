#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
using graph = vector<vpi>;

vector<int> codes;
bool zero_exists = false;

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
  if (a<b) up = 10-a+b;
  else up = a-b;
  if (b<a) down= 10-b+a;
  else down=  b-a;
  return (min(up,down));
}

int calculate_t (node n, node m){
  int aa = calculate(n.a,m.a);
  int bb = calculate(n.b,m.b);
  int cc = calculate(n.c,m.c);
  int dd = calculate(n.d,m.d);
  return aa+bb+cc+dd;
}

void process_codes(){
  //el último se procesará solo
  if (!zero_exists){
    codes.push_back(0000);
  }
  for (size_t i = 0; i < codes.size(); i++) {
    node n = set_node(codes[i]);
    node m;
    for (size_t j = i+1; j  < codes.size(); j++) {
       m =  set_node(codes[j]);
       int d = calculate_t(n,m);
       print(n);
       print (m);
       std::cout << d << '\n';
    }
  }
}

int main(){
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++) {
    int n;
    cin >> n;
    for (size_t j = 0; j < n; j++) {
      int c;
      cin >> c;
      if (c == 0000) zero_exists = true;
      codes.push_back(c);
    }
    process_codes();
  }
}
