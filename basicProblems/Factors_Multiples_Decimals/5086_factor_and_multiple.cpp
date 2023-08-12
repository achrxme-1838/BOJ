#include <iostream>
#include <vector>

using namespace std;

class FactorAndMultiple
{
public:
    void test(const int input_1, const int input_2)
    {
        if(input_1 % input_2 == 0) cout << "multiple" << endl;
        else if(input_2 % input_1 == 0) cout << "factor" << endl;
        else cout << "neither" << endl;
    }
};


int main()
{
    std::vector<std::pair<int, int>> pairs;
    int a, b;

    while (std::cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        pairs.push_back({a, b});
    }

    FactorAndMultiple fam;

    for(auto pair_num : pairs)
        if(!(pair_num.first == 0 and pair_num.second == 0))
            fam.test(pair_num.first, pair_num.second);

    return 0;
}