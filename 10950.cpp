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

/*
c es el código que estoy buscnado en este momento
*/
bool match_code(int c, string code){
  string cc = to_string(c);
  return (cc == code.substr(0, 1) || cc == code.substr(0, 2));
}

/*
Letter puede ser la letra sola o con el cero adelante
*/
bool matches(string letter, string code, vector<pair<string, int>> codes){
  //en el caso de la rama con el 0 adelante
  if (letter.substr(0, 1) == "0" && code.substr(0, 1) == "0"){
    //si ambos empiezan con 0, descarto los 0s y chequeo
      string l = letter.substr(1, 2);
      string c = code.substr(1);
      return matches(l , c, codes);
  }
  else{
    for (int i = 0; i < codes.size(); i++){
      if(codes[i].first == letter && match_code(codes[i].second, code)){
        //std::cout << "engancha!" << '\n';
        return true;
      }
    }
  }
  return false;
}

/*
En esta instancia ya sé que la primer posición está ok para el código
*/
Result create_result(string letter, string code, vector<pair<string, int>> codes, string result){
  Result r;
  string res_code;
  string res_res;
  if (letter.substr(0, 1) == "0" && code.substr(0, 1) == "0"){
    //si ambos empiezan con 0, descarto los 0s y chequeo
      string l = letter.substr(1, 2);
      string c = code.substr(1);
      return create_result(l , c, codes, result);
  }
  else{
    for (int i = 0; i < codes.size(); i++){
      if(codes[i].first == letter && match_code(codes[i].second, code)){
        string cc = to_string(codes[i].second);
        if  (cc == code.substr(0, 1)){
          res_code = code.substr(1);
        }
        else if (cc == code.substr(0, 2)){
          res_code = code.substr(2);
        }
        res_res = result+letter;
      }
    }
  }


  r.code = res_code;
  r.result = res_res;
  return r;
}

/*
Con impressions corto si llego a más de 100
En result guardo el string que voy armando
*/
void get_badcode(vector<pair<string, int>> codes, vector<string> letters, string code,  string result){

  //std::cout << "entro a badcode" << '\n';

  if(impressions ==100) return;
  for (int i = 0; i<letters.size(); i++){
    //std::cout << "entro al for" << '\n';
    if (matches(letters[i], code, codes)){
      //std::cout << "matchea" << '\n';
     Result x=   create_result(letters[i], code, codes, result);
     //std::cout << x.code << '\n';
     //std::cout << x.result << '\n';
     //si el code está vacío quiere decir que ya descifré todo
     if(x.code == ""){
       std::cout << x.result << '\n';
       impressions++;
     }
     //x tiene lo que resta del código a descifrar y result el string descifrado hasta el momento
      else   get_badcode(codes, letters, x.code, x.result);
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
      //std::cout << "" << '\n';

    }

}
