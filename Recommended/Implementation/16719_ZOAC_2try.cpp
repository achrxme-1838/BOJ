#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> reform_string(const string& input, int out_length){
    int input_length = input.length();

    vector<vector<int>> index_set_list;
    vector<int> init_idx_set;
    for(int i=0; i<out_length; i++){
        init_idx_set.push_back(input_length - 1 - i);
    }

    while(true){


    }




    vector<string> reformed_string;



    return reformed_string;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

}
