#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    stack<pair<int, int>> top_stack;

    for(int n=1; n<=N; n++){
        int test; cin >> test;
        bool success = false;
        stack<pair<int, int>> temp_stack = top_stack;

        while(!temp_stack.empty()){
            if(temp_stack.top().first > test){
                cout << temp_stack.top().second << ' ';
                success = true;
                break;
            }
            temp_stack.pop();
        }

        if(top_stack.empty()) top_stack.emplace(test, n);
        else if(top_stack.top().first < test) {
            top_stack.pop();
            top_stack.emplace(test, n);
        }
        else top_stack.emplace(test, n);


        if(!success) cout << "0 ";
    }



}
