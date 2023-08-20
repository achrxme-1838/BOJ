#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    cin >> input;
    auto length = input.size();

    std::string partial;
    std::set<std::string> partial_strings;

    for(int part_length=1; part_length<=length; part_length++){
        for(int i = 0; i <= length - part_length; i++){
            partial = input.substr(i, part_length);
            partial_strings.insert(partial);
        }
    }

    cout << partial_strings.size();

    return 0;
}