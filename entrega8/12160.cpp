#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<string>
using namespace std;
using vi = vector<int>;
using graph = vector<vi>;
constexpr int UNDEFINED = -1;



int L, U, R;
vi BUTTONS;
graph G;


int main(){
    for (int i = 1; i <= 100; i++) {
        cin >> L >> U >> R;
        if (L == 0 &&  R == 0 && U == 0) return 0;
        BUTTONS.assign(R, UNDEFINED);
        for (int j = 0; j < R; j++) {
            int a;
            cin >> a;
            BUTTONS[j] = a;
        }
        std::cout << "Case " << i <<": " << '\n';
    }
}
