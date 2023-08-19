#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long> inputs;
    long input;
    for(int i=0; i<N; i++)
    {
        cin >> input;
        inputs.push_back(input);
    }

    vector<long> sorted_inputs = inputs;

    sort(sorted_inputs.begin(), sorted_inputs.end(), compare);
    sorted_inputs.erase(std::unique(sorted_inputs.begin(), sorted_inputs.end()), sorted_inputs.end());

    for(auto input : inputs)
    {
        auto iter = lower_bound(sorted_inputs.begin(), sorted_inputs.end(), input);
        long idx = std::distance(sorted_inputs.begin(), iter);

        cout << idx << " ";
    }

    return 0;
}