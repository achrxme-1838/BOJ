#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isOperator(char c){
    return (c=='*') or (c=='/') or (c=='+') or (c=='-');
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    stack<double> calc_stack;
    string input; cin >> input;


    for(auto c : input){
        if(isOperator(c)){
            double b = calc_stack.top(); calc_stack.pop();
            double a = calc_stack.top(); calc_stack.pop();
            double r;
            if(c == '+') r = a+b;
            if(c == '-') r = a-b;
            if(c == '*') r = a*b;
            if(c == '/') r = a/b;
            calc_stack.push(r);
        }
        else{
            calc_stack.push(double(c-'0'));
        }
    }

//    cout << fixed;
//    cout.precision(2);
    cout << calc_stack.top();

    return 0;
}
