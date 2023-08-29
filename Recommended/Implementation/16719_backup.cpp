#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//map<char, int> char_to_order;
//
//bool compare(char a, char b){
//    int a_i = char_to_order[a];
//    int b_i = char_to_order[b];
//
//    return a_i < b_i;
//}

vector<int> continuous_min_not_pivot(vector<int> pivot_list, int max_n){

    vector<int> result;
    bool cont = false;
    for(int i=max_n-1; i>=0; i--){
        if(find(pivot_list.begin(), pivot_list.end(), i) == pivot_list.end()){
            cont = true;
            result.push_back(i);
        }
        else{
            if(cont) break;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string input;
    cin >> input;

//    int i = 0;
//    for(auto c: input){
//        char_to_order.insert({c, i});
//        i++;
//    }


    int input_length = input.length();

    for(int k=1; k<=input_length; k++) {
        int N = k;

        auto test_start = input.begin();
        auto test_end = input.end();
        vector<int> pivot_list;
        string output_str;

        for (int n = 1; n <= N; n++) {
            auto pivot_iter = min_element(test_start, test_end);
            char pivot_char = *pivot_iter;

            pivot_list.push_back(int(pivot_iter - input.begin()));
            output_str += pivot_char;

            if (n == N) break;

            if (pivot_iter == test_end - 1) {
                vector<int> next_indices = continuous_min_not_pivot(pivot_list, input_length);
                test_start = *min_element(next_indices.begin(), next_indices.end()) + input.begin();
                test_end = *max_element(next_indices.begin(), next_indices.end()) + input.begin() + 1;
            } else {
                test_start = pivot_iter + 1;

                if (int(test_start - input.begin()) < pivot_list[0]) {
                    test_end = pivot_list[0] + input.begin();
                } else {
                    test_end = input_length + input.begin();
                }
            }
        }

        sort(output_str.begin(), output_str.end(), compare);

        cout << output_str << '\n';
    }

    return 0;
}
