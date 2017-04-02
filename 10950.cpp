#include <iostream>

#include <vector>

using namespace std;

int impressions = 0;
int occ = 0;

class Result{
public:
  string code;
  string result;
};

bool matches(string letter, string code, vector<pair<string, int>> codes){
  return false;
}

/*
En esta instancia ya sé que la primer posición está ok para el código
*/
Result create_result(string letter, string code, vector<pair<string, int>> codes, string result){
  Result r;
  r.code = "bla";
  r.result = "blabla";
  return r;
}

/*
Con impressions corto si llego a más de 100
En result guardo el string que voy armando
*/
void get_badcode(vector<pair<string, int>> codes, vector<string> letters, string code,  string result){
  if(impressions ==100) return;
  for (int i = 0; i<letters.size(); i++){
    if (matches(letters[i], code, codes)){
     Result x=   create_result(letters[i], code, codes, result);
      get_badcode(codes, letters, x.code, x.result);
    }
    //si ya recorrí todo el código..
    if(code == ""){
      std::cout << result << '\n';
      impressions++;
    }
  }
}


int main(){
  int n;




    while (cin >> n) {
      vector<pair<string, int>> codes;
      vector<string> letters;
      string code;
      occ++;
      impressions = 0;

      if (n == 0) return 0;


      codes.resize(n);
      letters.resize(n*2);
      for (int i= 0; i<n; i++){
        string a;
        int b;
        cin >> a;
        cin >> b;
        codes[i] = make_pair(a, b);

        //agrego cada letra y su variante en caso de tener un 0 adelante para ir abriendo el árbol
        letters.push_back(a);
        letters.push_back("0"+a);
      }
      cin >> code;

      std::cout << "" << '\n';
      std::cout << "Case #"+to_string(occ) << '\n';
      get_badcode(codes, letters, code,"");
      std::cout << "" << '\n';

    }
}
