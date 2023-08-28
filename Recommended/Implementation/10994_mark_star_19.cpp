#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int input;
    cin >> input;

    // 1->1 / 2->5 / 3->9 / 4 ->13
    int size = 1 + (input-1)*4;
    int layer_num = input;

    std::vector<std::vector<bool>> answer;
    std::vector<bool> answer_line;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            answer_line.push_back(false);
        }
        answer.push_back(answer_line);
        answer_line.clear();
    }
    // center = 2 for size = 5
    int center = size / 2;

    for(int i=1; i<=layer_num; i++){
        int local_size = 1 +(i-1)*4;
        // local_size = 5 for i = 2
        for(int j=0; j<local_size; j++){
            answer[center-local_size/2][center-local_size/2 + j] = true;
            answer[center+local_size/2][center-local_size/2 + j] = true;
            answer[center-local_size/2 + j][center-local_size/2] = true;
            answer[center-local_size/2 + j][center+local_size/2] = true;
        }
    }

    for(auto a:answer){
        for(auto b: a){
            if(b) cout << '*';
            else  cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}