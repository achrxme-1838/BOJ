#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> top_stack;

    for(int n=1; n<=N; n++){
        int test; cin >> test;
        bool success = false;

        int l = top_stack.size();
        for(int i=0; i<l; i++){
            auto top = top_stack[l-i-1];
            if(top.first > test){
                cout << top.second << ' ';
                success = true;
                break;
            }
        }

        if(top_stack.empty()) top_stack.emplace_back(test, n);
        else if(top_stack.back().first < test) {
            top_stack.pop_back();
            top_stack.emplace_back(test, n);
        }
        else top_stack.emplace_back(test, n);


        if(!success) cout << "0 ";
    }
}
