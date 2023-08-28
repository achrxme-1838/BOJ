#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> reform_string(pair<string, int> input){
    int input_length = input.first.length();

    vector<pair<string, int>> reformed_string;

    if(input_length == 1) reformed_string.push_back(input);
    else if(input_length == 2){
        reformed_string.push_back(
                {to_string((input.first.at(0) - '0') + (input.first.at(1) - '0')),
                 input.second});
    }
    else{
        for(int i=1; i<input_length; i++){
            for(int j=i+1; j<input_length; j++){
                string init = input.first.substr(0, i);
                string mid = input.first.substr(i, j-i);
                string fin = input.first.substr(j);

                int total = stoi(init) + stoi(mid) + stoi(fin);
                reformed_string.push_back({to_string(total), input.second});
            }
        }
        return reformed_string;
    }

    return reformed_string;
}

int count_odd(string input){
    int input_length = input.length();
    int odd_cnt = 0;
    for(int i=0; i<input_length; i++){
        if((input[i] - '0')%2 == 1) odd_cnt++;
    }
    return odd_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num;
    cin >> num;

    string str = to_string(num);
    int odd = count_odd(str);

    vector<pair<string, int>> test_cases;
    vector<pair<string, int>> test_results;
    test_cases.push_back({str, odd});

    vector<pair<string, int>> reformed_strs;
    if (str.length() != 1) {
        while (!test_cases.empty()) {
            reformed_strs = reform_string(test_cases.at(0));

            for (auto reformed_str: reformed_strs) {
                reformed_str.second += count_odd(reformed_str.first);
                if (reformed_str.first.length() > 1) test_cases.push_back(reformed_str);
                test_results.push_back(reformed_str);
            }
            reformed_strs.clear();
            test_cases.erase(test_cases.begin());
        }
    }
    if (str.length() == 1) {
        test_results.push_back({str, odd});
    }

    int min = -1;
    int max = -1;
    for (auto r: test_results) {
        if (r.first.length() == 1) {
            if (min == -1) min = r.second;
            if (max == -1) max = r.second;

            if (min != -1 and min > r.second) min = r.second;
            if (max != -1 and max < r.second) max = r.second;
        }
    }

    cout << min << ' ' << max;


    return 0;
}