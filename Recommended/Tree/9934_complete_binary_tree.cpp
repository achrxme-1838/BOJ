#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int K; cin >> K;

    vector<vector<int>> floors(K);
    vector<int> ins;
    for(int i=1; i<=pow(2, K)-1; i++){
        int in; cin >> in;
        ins.push_back(in);
    }

    int cur_floor = 0;
    vector<int> copy = ins;
    vector<int> temp;
    while(!copy.empty()){

        for(int i=1; i<=copy.size(); i++) {
            if (i % 2 == 1) {
                floors[cur_floor].push_back(copy[i-1]);
            } else {
                temp.push_back(copy[i-1]);
            }
        }
        copy = temp;
        temp.clear();
        cur_floor++;
    }

    for(int j=floors.size()-1; j >= 0; j--){
        auto l = floors[j];
        for(auto a: l){
            cout << a << ' ';
        }
        cout << '\n';
    }


    return 0;
}