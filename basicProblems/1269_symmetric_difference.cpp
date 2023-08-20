#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    std::set<int> set_A;
    std::set<int> set_B;

    int input;
    for(int i=0; i<N; i++)
    {
        cin >> input;
        set_A.insert(input);
    }
    for(int i=0; i<M; i++)
    {
        cin >> input;
        set_B.insert(input);
    }

    std::vector<int> result;
    result.resize(set_A.size() + set_B.size());
    auto itr = set_symmetric_difference(set_A.begin(), set_A.end(),
                                        set_B.begin(), set_B.end(),
                                        result.begin());

    cout << std::distance(result.begin(), itr);

    return 0;
}