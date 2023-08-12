#include <iostream>
#include <vector>

using namespace std;

std::vector<int> decomposition(int num) {
    int remain;
    std::vector<int> decomposed_num;

    while (num >= 10) {
        remain = num % 10;
        decomposed_num.push_back(remain);
        num = (num - remain) / 10;
    }

    decomposed_num.push_back(num);

    return decomposed_num;
}

int main()
{
    int N;
    cin >> N;

    std::vector<int> decomposed_num;
    int              current_sum;

    int              result = -1;

    for(int i = 1; i < N; i++)
    {
        current_sum = 0;
        decomposed_num = decomposition(i);

        for(auto num : decomposed_num){
            current_sum += num;
        }
        if(current_sum + i == N){
            result = i;
            break;
        }
    }
    if(result != -1) cout << result;
    else cout << 0;

    return 0;
}