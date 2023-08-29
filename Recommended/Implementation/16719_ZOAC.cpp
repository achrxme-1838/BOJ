#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string input;
    cin >> input;

    vector<int> input_to_num;
    int length = input.size();
    for(auto c : input){
        input_to_num.push_back(c-65);
    }

    vector<int> output;
    vector<int> new_input = input_to_num;
//    vector<int> excluded;

    int front_idx = length + 1;
    for(int n=1; n<=3; n++) {
    // 여기서 나온 min idx랑 위에서 찾은 length랑 호환이 안됨
        int min_idx = int(min_element(new_input.begin(), new_input.end()) - new_input.begin());
        front_idx = min(front_idx, min_idx);

        int min = *min_element(new_input.begin(), new_input.end());
        output.push_back(min);

        length = new_input.size();
        new_input.clear();
        if(min_idx + 1 < length) { // 여기도 문제
            for (int i = min_idx + 1; i < length; i++) {
                new_input.push_back(input_to_num[i]);
            }

        }else{
            for(int i = 0; i < front_idx; i++){
                new_input.push_back(input_to_num[i]);
            }
        }


    }

    for(auto o: output){
        cout << char(o+65);
    }




    return 0;
}