#include <iostream>
#include <vector>

using namespace std;

vector<int> input;

void ReverseSearch(int start, int end){
    if(start >= end) return;

    if(start == end-1){
        cout << input[start] << '\n';
        return;
    }
    int next = start + 1;
    while(next < end){
        if(input[start] < input[next]) break;
        next++;
    }

    ReverseSearch(start + 1, next);
    ReverseSearch(next, end);
    cout << input[start] << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 50 / ( 30 / ( 24 5 ) ( 28 45 ) ) (98 / ( 52 60 ) )


    int num;
    while(cin >> num){
        input.push_back(num);
    }

    ReverseSearch(0, int(input.size()));

    return 0;
}