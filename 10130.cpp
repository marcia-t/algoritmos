#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include <string>
#include<cstdlib>

using namespace std;
using pp = pair<int,int>;


int CASES = 0;
pp pw[1000];
int people_w[1000];

int main(){
  cin >> CASES;

  for (int  i = 0; i < CASES; i++){
    int objs, people;
    cin >> objs;
    for (int j = 0; j<objs; j++){
      int p, w;
      cin >> p;
      cin >> w;
      pp pair = make_pair(p,w);
      pw[j] = pair;
    }
    cin >> people;
    for (int j = 0; <people; j++){
      int mw;
      cin >> mw;
      people_w[j] = mw;
    }
  }
}
