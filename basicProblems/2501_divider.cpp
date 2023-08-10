#include <iostream>
#include <vector>

using namespace std;

std::vector<int> Divider(int num)
{
    std::vector<int> output;

    for(int i = 1; i <= num / 2; i++)
    {
        if(num % i == 0) output.push_back(i);
    }
    output.push_back(num);

    return output;
}

int main()
{
    int N, K;
    cin >> N >> K;

    std::vector<int> result_vec = Divider(N);

    if(result_vec.size() >= K) cout << result_vec.at(K-1) << endl;
    else cout << 0 << endl;
}