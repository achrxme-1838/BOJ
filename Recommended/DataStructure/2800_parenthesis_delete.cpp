#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

//set<string> results;

void DelParenthesis(string input){
    int l = input.length();

    stack<unsigned char> left_stack;
    stack<unsigned char> right_stack;

    for(int i=0; i<l; i++){
        if(input[i] == '(') left_stack.push(i);
        if(input[l-i-1] == ')') right_stack.push(l-i-1);
    }

    if(left_stack.empty()) return;

    while(!left_stack.empty()){
        unsigned char current_left_idx = left_stack.top();
        unsigned char current_right_idx = right_stack.top();
        left_stack.pop();
        right_stack.pop();

        string result = input.substr(0, current_left_idx)
                        + input.substr(current_left_idx+1, current_right_idx-current_left_idx-1)
                        + input.substr(current_right_idx+1);
        results.insert(result);

        while(!left_stack.empty()){
            left_stack.pop();
            right_stack.pop();
        }

        DelParenthesis(result);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string input; cin >> input;

    DelParenthesis(input);

    for(auto r: results){
        cout << r << '\n';
    }
}