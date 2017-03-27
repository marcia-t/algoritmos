#include <iostream>

#include <vector>

using namespace std;

vector<bool> mejor;
vector<int> duration;
int D, tracks, dur_mejor;


void backtrack(vector<bool> &s, int dur, int k) {

    if(dur > D) return;
    if(dur > dur_mejor){
        mejor = vector<bool>(s);
        dur_mejor = dur;
    }
    if (k >= duration.size()) return;

    s.push_back(false);
    backtrack(s,dur,k+1);
    s.pop_back();

    s.push_back(true);
    backtrack(s,dur + duration[k], k+1);
    s.pop_back();

}

int main() {

    while(cin >> D) {


        cin >> tracks;

        duration.resize(tracks);

        for(int i = 0; i < tracks; ++i) {
            cin >> duration[i];

        }

        mejor.clear();
        dur_mejor = 0;
        vector<bool> s;

        backtrack(s,0,0);
        int total = 0;
        for(unsigned int i = 0; i < mejor.size(); ++i) {
            if(mejor[i]) {
                total += duration[i];
                cout << duration[i] << ' ';
            }
        }
        cout << "sum:" << total << '\n';
    }
}
