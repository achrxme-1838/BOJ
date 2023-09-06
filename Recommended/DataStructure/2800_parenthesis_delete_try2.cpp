#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>

using namespace std;

set<string> results;

vector<pair<int, int>> delete_set;

// 조합을 구하는 함수
// n: 전체 원소 수, r: 조합할 원소 수, idx: 현재 선택한 원소의 인덱스, depth: 현재까지 고른 원소의 수
void combination(vector<pair<int, int>>& arr, vector<pair<int, int>>& comb,
                 int n, int r,
                 int idx = 0, int depth = 0) {
    if (r == depth) {
        for (int i = 0; i < r; i++) {
            cout << "(" << comb[i].first << " " << comb[i].second << ") ";
//            delete_set.emplace_back(comb[i].first, comb[i].second);
        }
        cout << "called \n";
        return;
    }

    if (idx == n) return;

    comb[depth] = arr[idx];
    combination(arr, comb, n, r, idx + 1, depth + 1);  // idx번째 원소를 선택
    combination(arr, comb, n, r, idx + 1, depth);      // idx번째 원소를 선택하지 않음
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string input;
    cin >> input;

    int l = input.length();

    stack<int> left_stack;
    stack<int> right_stack;

    for (int i = 0; i < l; i++) {
        if (input[i] == '(') left_stack.push(i);
        if (input[l - i - 1] == ')') right_stack.push(l - i - 1);
    }

    vector<pair<int, int>> parenthesis_pair;
    while(!left_stack.empty()){
        int left = left_stack.top();
        int right = right_stack.top();

        left_stack.pop();
        right_stack.pop();

        parenthesis_pair.emplace_back(left, right);
    }


    int number_of_paren = parenthesis_pair.size();
    vector<pair<int, int>> comb(number_of_paren);
    for(int r=1; r<=number_of_paren; r++) {
        combination(parenthesis_pair, comb, parenthesis_pair.size(), r);
//        delete_set.clear();
        cout << "pass" << '\n';
    }


//    r = 3;
//    vector<pair<int, int>> comb_2(3);
//    combination(parenthesis_pair, comb_2, parenthesis_pair.size(), r);



    return 0;
}

