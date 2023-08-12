#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    std::vector<int> N_cards;

    int input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        N_cards.push_back(input);
    }


    int max_sum = 0;
    int current_sum;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j ++){
            for(int k = j + 1; k < N; k ++)
            {
                current_sum = N_cards[i] + N_cards[j] + N_cards[k];
                if(current_sum > max_sum and current_sum <= M) max_sum = current_sum;
            }
        }
    }

    cout << max_sum;

    return 0;
}