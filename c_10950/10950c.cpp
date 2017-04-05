#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;

int impressions = 0;
int occ = 0;
vector<string> impress;


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
  return (cc == code.substr(0, 1) || cc == code.substr(0, 2) || cc == code.substr(0, 3));
}

/*
En Matches chequeo que una letra y su código coincidan con la primera parte del código que estoy testeando
Letter puede ser la letra sola o con el cero adelante (el 0 se descarta en el 1er if)
*/
bool matches(string letter, string code, vector<pair<string, int>> codes){
  //en el caso de la rama con el 0 adelante
  if (letter.substr(0, 1) == "0" && code.substr(0, 1) == "0"){
    //si ambos empiezan con 0, descarto los 0s y chequeo
      string l = letter.substr(1, 2);
      string c = code.substr(1);
      return matches(l , c, codes);
  }
  else if (letter.substr(0, 2) == "00" && code.substr(0, 2) == "00"){
      string l = letter.substr(2);
      string c = code.substr(2);
      return matches(l , c, codes);
  }
  else{
    for (int i = 0; i < codes.size(); i++){
      if(codes[i].first == letter && match_code(codes[i].second, code)){
        return true;
      }
    }
  }
  return false;
}

/*
En esta función me encargo de quitar la parte del código que ya fue descifrada y agregarsela al resultado en curso
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
  else if (letter.substr(0, 2) == "00" && code.substr(0, 2) == "00"){
    //si ambos empiezan con 00, descarto los 00s y chequeo
      string l = letter.substr(2);
      string c = code.substr(2);
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
Esta función imprime los resultados que se van obteniendo
Con impressions corto si llego a más de 100
En result guardo el string que voy armando
codes y letters son siempre los mismos que ingresaron por consola
*/
vector<string> get_badcode(vector<pair<string, int>> codes, vector<string> letters, string code,  string result){

  //if(impressions ==100) return ;
  //abro el árbol para cada letra (en el vector también están las letras con el 0 adelante)

  for (int i = 0; i<letters.size(); i++){

    //std::cout << "entro al 1er for" << '\n';
    if (matches(letters[i], code, codes)){
     Result x=   create_result(letters[i], code, codes, result);
     //si el code está vacío quiere decir que ya descifré todo
     if(x.code == ""){
       impress.push_back(x.result);
       //std::cout << x.result << '\n';
       impressions++;
     }
     //sino, sigo entrando por las ramas del árbol
     //x.code tiene lo que resta del código a descifrar y x.result el string descifrado hasta el momento
      else   get_badcode(codes, letters, x.code, x.result);
    }
  }
  return impress;
}


int main(){
  int n;

    while (cin >> n) {
      //impress.erase(impress.begin(), impress.end());
    //  impress.resize(10000);

      vector<pair<string, int>> codes;
      vector<string> letters;
      string code;
      occ++;
      impressions = 0;

      if (n == 0) return 0;


      codes.resize(n);
      letters.resize(n*3);
      for (int i= 0; i<n; i++){
        string a;
        int b;
        cin >> a;
        cin >> b;
        codes[i] = make_pair(a, b);

        //agrego cada letra y su variante en caso de tener un 0 adelante para ir abriendo el árbol
        letters.push_back(a);
        letters.push_back("0"+a);
        //si el código es menor a 10 (una sola cifra) puede tener hasta dos 0s adelante
        if (b < 10){
          letters.push_back("00"+a);
        }
      }
      cin >> code;

      std::cout << "" << '\n';
      std::cout << "Case #"+to_string(occ) << '\n';


      vector<string> decrypted = get_badcode(codes, letters, code,"");


      sort(decrypted.begin(), decrypted.end());

      int j;
      if (decrypted.size() < 100) j = decrypted.size();
      else j = 100;

      for (int i = 0; i<j; i++){
        std::cout << decrypted[i] << '\n';
      }



    }

}
