#include <iostream>

#include <vector>

using namespace std;

int occ = 0;
int impressions = 0;


void badcode(std::vector<string> letters, map<int,string> codes, string code, string result){
  if (impressions == 100) return;

  for (int i = 0; i<letters.size(); i++){
    
  }

}


int main(){

  int n;

    while (cin >> n) {
      vector<string> letters;
      map<int, string> codes;
      string code;
      occ++;
      impressions = 0;


      if (n == 0) {
        std::cout  << '\n';
        return 0;
      }

      for (int i= 0; i<n; i++){
        string a;
        int b;
        cin >> a;
        cin >> b;
        codes[b] = a;
        letters.push_back(a);
        std::sort(letters.begin(), letters.end());
      }

        cin >> code;
        std::cout << "Case #"+to_string(occ) << '\n';
        badcode(letters, codes, code, "");
        std::cout << "" << '\n';
    }


}
