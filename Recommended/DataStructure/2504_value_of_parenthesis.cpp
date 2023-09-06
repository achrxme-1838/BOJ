#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input; cin >> input;

    std::stack<int> stack_2;
    std::stack<int> stack_3;

    int temp = 1;
    int result = 0;
    char prev = '!';
    bool valid = true;
    for(auto c: input){
        if(c=='(') {
            temp *= 2;
            stack_2.push(temp);
        }
        if(c==')'){
            if(prev == '!') {
                valid = false;
                break;
            }
            else if(prev == '(') result += temp;
            temp /= 2;

            if(!stack_2.empty()) stack_2.pop();
            else{
                valid = false;
                break;
            }
        }

        if(c=='[') {
            temp *= 3;
            stack_3.push(temp);
        }
        if(c==']'){
            if(prev == '!') {
                valid = false;
                break;
            }
            else if(prev == '[') result += temp;
            temp /= 3;
            if(!stack_3.empty()) stack_3.pop();
            else {
                valid = false;
                break;
            }
        }
        prev = c;
    }

    if(!stack_2.empty() or !stack_3.empty()) valid = false;

    if(valid) cout << result;
    else cout << '0';

    return 0;
}