#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int occ = 0;
int impressions = 0;
class Result{
public:
  string code;
  string result;
};


bool match(string subcode, string letter, map<int,string> codes){
  int c = atoi( subcode.c_str() );
  return (codes[c] == letter);
}



Result create_result(string letter, string code, map<int,string> codes, string result){
  Result r;
  string res_code;
  string res_res;
  if (code.substr(0,1) == "0"){
    if (match(code.substr(1, 2), letter, codes)){
      res_code = code.substr(2);
    }
    else if (match(code.substr(1, 3), letter, codes)){
      res_code = code.substr(3);
    }
  }
  else {
    if (match(code.substr(0, 1), letter, codes)){
      res_code = code.substr(1);
    }
    else if (match(code.substr(0, 2), letter, codes)){
      res_code = code.substr(2);
    }
  }
  res_res = result + letter;
  r.code= res_code;
  r.result= res_res;
  return r;
}




bool matches(string letter, string code, map<int,string> codes){
  if (code.substr(0,1) == "0"){
    return (match(code.substr(1, 2), letter, codes) ||  match(code.substr(1,3), letter,codes));
  }
  else{
    return (match(code.substr(0, 1), letter, codes) ||  match(code.substr(0,2), letter, codes));
  }
}

void badcode(std::vector<string> &letters, map<int,string> &codes, string code, string result){
  if (code == ""){
    std::cout << result << '\n';
    impressions++;
  }
  if (impressions == 100) return;

  for (int i = 0; i<letters.size(); i++){
    if (matches(letters[i], code, codes)){
      Result x=   create_result(letters[i], code, codes, result);
      badcode(letters, codes, x.code, x.result);
    }
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
