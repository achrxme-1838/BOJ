#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    vector<int> input;
    for(int n=0; n<N; n++){
        int temp; cin >> temp;
        input.push_back(temp);
    }

    stack<int> _stack;
    vector<char> result;
    bool success = true;

    _stack.push(0);
    _stack.push(1);
    result.push_back('+');

    int current = 2;
    for(auto next : input){
        if(!success) break;
        while(true){
            if(_stack.top() < next){
                _stack.push(current);
                result.push_back('+');
                current++;
            }
            else if(_stack.top() == next){
                _stack.pop();
                result.push_back('-');
                break;
            }
            else{
                cout << "NO" << '\n';
                success = false;
                break;
            }
        }
    }

    if(success){
        for(auto r: result){
            cout << r << '\n';
        }
    }

}