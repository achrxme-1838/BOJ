#include <iostream>
#include <vector>

using namespace std;

std::vector<int> DividerGetter(int num)
{
    std::vector<int> output;

    for(int i = 1; i <= num / 2; i++)
        if(num % i == 0) output.push_back(i);

    return output;
}

void SumOfDivider(int input)
{
    std::vector<int> divider_list = DividerGetter(input);

    int sum = 0;

    for(auto i : divider_list) sum += i;

    if(sum == input){
        cout << input << " = ";
        for(int i = 0; i < divider_list.size() - 1 ; i++) cout << divider_list.at(i) << " + ";
        cout << divider_list.at(divider_list.size() - 1) << endl;
    }
    else cout << input << " is NOT perfect." << endl;

}

int main()
{
    std::vector<int> inputs;
    int input;
    while (std::cin >> input) {
        if (input == -1 ) break;
        inputs.push_back(input);
    }

    for(auto num : inputs)
    {
        SumOfDivider(num);
    }
}