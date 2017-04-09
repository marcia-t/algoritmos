#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, bool> sums;

std::vector<int> nums;

/*
En save_sum armo el string del resultado con los signos '+'.
Si el string no es clave (todavía no lo agregué y no existe) en mi map de sums, imprimo el resultado y lo agrego al map.
De lo contrario, lo ignoro.
*/
void save_sum(std::vector<bool> b_nums){
  string sum = "";
  for (int i=0; i<b_nums.size(); i++){
    if (b_nums[i]){
      string n = std::to_string(nums[i]);
      sum = sum + n+"+";
    }
  }
  int l = sum.length();
  sum = sum.substr(0, l-1);
  if (sums.count(sum) == 0){
    std::cout << sum << '\n';
    sums[sum] = true;
  }
}

/*
sumtiup resuelve el problema utilizando backtracking con 'partes de'.
Recibe un vector de booleanos que denota el recorrido del árbol de decisiones que voy armando, el total que tnego que sumar,
la posición del vector en la que me encuentro, y la suma parcial.
Si llegué a la suma que necesito (c_sum == t), imprimo los resultados y salgo de esa rama.
Si mi suma es mayor al total, salgo de la rama.
Y si mi posición es igual a la cantidad de números que me dieron para resolver el problema, salgo porque ya no tengo opciones.
*/
void sumitup( std::vector<bool> b_nums, int t, int pos, int c_sum){
  if(c_sum == t) {
    save_sum(b_nums);
    return;
  }
  if (c_sum > t) return;
  if (pos == nums.size()) return;
  b_nums.push_back(true);
  sumitup(b_nums, t, pos+1, c_sum+nums[pos]);
  b_nums.pop_back();

  b_nums.push_back(false);
  sumitup(b_nums, t, pos+1, c_sum);
  b_nums.pop_back();

}



int main(){

  int t;
  int n;

  while (cin >> t){
    cin >> n;

    if (n == 0) return 0;
    std::vector<bool> b_nums;
    sums.clear();
    nums.resize(n);


    for (int i = 0; i<n; i++){
      int a;
      cin >> a;
      nums[i]= a;
    }

    std::cout << "Sums of " << t << ":" << '\n';
    sumitup(b_nums,t, 0, 0);
    if (sums.empty()){
      std::cout << "NONE" << '\n';
    }

  }
}
