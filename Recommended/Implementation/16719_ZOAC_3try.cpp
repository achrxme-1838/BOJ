#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;
}

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

    string raw_input;
    cin >> raw_input;

    vector<pair<char, int>> input;
    int idx=0;
    for(auto r: raw_input){
        input.push_back({r, idx});
        idx++;
    }

    int input_length = input.size();

    for(int k=1; k<=input_length; k++) {

        int N = k;

        auto test_start = input.begin();
        auto test_end = input.end();
        vector<int> pivot_list;
        vector<pair<char, int>> output_str;

        for (int n = 1; n <= N; n++) {
            auto pivot_iter = min_element(test_start, test_end);
            auto pivot_char = *pivot_iter;

            pivot_list.push_back(int(pivot_iter - input.begin()));
            output_str.push_back(pivot_char);

            if (n == N) break;

            if (pivot_iter == test_end - 1) {
                vector<int> next_indices = continuous_min_not_pivot(pivot_list, input_length);
                test_start = *min_element(next_indices.begin(), next_indices.end()) + input.begin();
                test_end = *max_element(next_indices.begin(), next_indices.end()) + input.begin() + 1;
            } else {
                test_start = pivot_iter + 1;
            }
        }

        sort(output_str.begin(), output_str.end(), compare);

        for(auto o : output_str) {
            cout << o.first;
        }
        cout << '\n';
    }

    return 0;
}
