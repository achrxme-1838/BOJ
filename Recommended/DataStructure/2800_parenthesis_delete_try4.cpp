#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

string input;
set<string> answer_set;
vector<bool> delete_indices(201, false);
vector<pair<int, int>> parenthesis_indices;

void reform_str(int idx, int del_signal)
{
    int num_paren_set = parenthesis_indices.size();

    if(del_signal>=1){
        int x=0;
        string temp;
        for(auto c : input){
            if(!delete_indices[x]) temp += c;
            x++;
        }
        answer_set.insert(temp);
    }

    for(int i=idx; i<num_paren_set; i++){
        delete_indices[parenthesis_indices[i].first] = true;
        delete_indices[parenthesis_indices[i].second] = true;
        reform_str(i+1, del_signal+1);
        delete_indices[parenthesis_indices[i].first] = false;
        delete_indices[parenthesis_indices[i].second] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    int l = input.length();

    stack<int> left_stack;
    stack<int> right_stack;

    for (int i = 0; i < l; i++) {
        if(input[i] == '(') left_stack.push(i);
        if(input[i] == ')'){
            parenthesis_indices.emplace_back(left_stack.top(), i);
            left_stack.pop();
        }
    }

    reform_str(0, 0);

    for(auto a : answer_set){
        cout << a << '\n';
    }
}