#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    for(int i=0; i<N; i++){
        stack<bool> _stack;
        bool success = true;
        string str; cin >> str;

        for(auto s : str){
            if(s == '(') _stack.push(true);
            else{
                if(_stack.empty()) {
                    success = false;
                    break;
                }
                else {
                    _stack.pop();
                }
            }
        }
        if(!success or !_stack.empty()) cout << "NO\n";
        else if(_stack.empty()) cout << "YES\n";

    }

    return 0;
}