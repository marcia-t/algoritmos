#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;
constexpr int MAX_PRICE = 1000001;
using ii = pair<int,int>;

int abooks;
vector<int> bprices;
int amoney;
ii best = ii(0, MAX_PRICE);


void solve(){
  //tengo que llegar hasta la mitad del precio q tengo q pagar
  int half_price = amoney / 2;
  for (int  i = 0; i < bprices.size(); i++) {
    if (bprices[i] < half_price +1){ //Sumo 1 porque es la división entera.
      int p_1 = bprices[i];
      int p_2 = amoney - p_1;
      if(binary_search(bprices.begin(), bprices.end(), p_2)){
        //si existe el par, voy a chequear que su diferencia sea menor que el mejor par
        //cuento con que el par guarde el nro más chico y el más grande en fst y scnd respectivamente
        int d_1 = best.second - best.first;
        int d_2 = p_2 - p_1;
        if (d_2<d_1){
          best = ii(p_1,p_2);
        }
      }
    }
  }
  std::cout << "Peter should buy books whose prices are " << best.first << " and " << best.second << "." << '\n';
  cout << '\n';
}

int main(){

    while(scanf("%d", &abooks)!=EOF){
      bprices.resize(0);
      best = ii(0,MAX_PRICE);
      for(int i = 0; i<abooks;i++){
        int p;
        cin >> p;
        bprices.push_back(p);
      }
      sort(bprices.begin(), bprices.end());
      cin>>amoney;
      solve();


    }
}
