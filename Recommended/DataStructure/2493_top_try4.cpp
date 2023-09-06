#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    stack<pair<int, int>> top_stack;
    top_stack.emplace(100000001, 0);

    for(int n=1; n<=N; n++){
        int test; cin >> test;

        while(top_stack.top().first < test){
            top_stack.pop();
        }
        cout << top_stack.top().second << ' ';

        top_stack.emplace(test, n);
    }

    return 0;
}