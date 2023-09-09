#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> numbers;
    for(int n=2; n<=N; n++){
        numbers.push_back(n);
    }

    int del_cnt = 0;
    while(true){
        int P;

        for(auto n : numbers){
            if(n!=-1){
                P = n;
                break;
            }
        }

        int del_num = P;
        while(del_num <= N){
            if(numbers[del_num-2] != -1) {
                numbers[del_num-2] = -1;
                del_cnt++;
                if(del_cnt==K) {
                    cout << del_num << '\n';
                    return 0;
                }
            }
            del_num += P;
        }
    }


}