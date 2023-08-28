#include <iostream>
#include <vector>

using namespace std;

std::vector<int> roll_back(std::vector<int> shuffled_vec, std::vector<int> shuffle_rule){
    std::vector<int> roll_backed_vec;
    int length = shuffled_vec.size();
    for(int i=0; i<length; i++){
        roll_backed_vec.push_back(-1);
    }

    int j = 0;
    for(auto rule : shuffle_rule){
        roll_backed_vec[rule-1] = shuffled_vec[j];
        j++;
    }

    return roll_backed_vec;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    std::vector<int> shuffled_vec;
    std::vector<int> shuffle_rule;
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        shuffled_vec.push_back(input);
    }
    for(int i=0; i<N; i++){
        cin >> input;
        shuffle_rule.push_back(input);
    }

    std::vector<int> result;
    for(int i=0; i<K; i++){
        result = roll_back(shuffled_vec, shuffle_rule);
        shuffled_vec = result;
    }

    for(auto a : result){
        cout << a << ' ';
    }

}

