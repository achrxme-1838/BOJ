#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string input;
    cin >> input;

    int length = input.length();

    stack<int> last;

    int layer_depth = 0;
    int laser_cut = 0;
    int new_bar = 0;
    for(int i=0; i<length; i++){

        if(input[i] == '('){
            layer_depth++;
            new_bar++;
        }
        else{ // ')'
            layer_depth--;
            if(!last.empty() and last.top() =='(') {
                laser_cut += layer_depth;
                new_bar--;
            }
        }
        last.push(input[i]);
    }

    cout << laser_cut + new_bar;



}