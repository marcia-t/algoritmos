#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int occ = 0;
int impressions = 0;


void badcode(map<int,string> codes, vector<int> code, string result){
  if (impressions == 100) return;

  for (int i = 0; i<code.size(); i++){
    if (code[i] == 0 && code[i+1] == 0) return;
    if (code[i] == 0)
  }
}

int main(){
    int n;
    while (cin >> n) {
        vector<string> letters;
        map<int, string> codes;
        std::vector<int> code;
        string s_code;
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

        cin >> s_code;
        for (int i = 0; i<s_code.length(); i++){
            string c = s_code.substr(i, 1);
            if (c == "0") {
              string x = s_code.substr(i+1, 1);
              if (x != "0"){
                
              }
            }
            int valor = atoi(c.c_str());
            code.push_back(valor);
        }

        std::cout << "Case #"+to_string(occ) << '\n';
        badcode(letters, codes, code, "");
        std::cout << "" << '\n';
    }
}
