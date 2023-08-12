#include <iostream>
#include <vector>

using namespace std;

bool PrimeNumberJudge(int num)
{
    // true : primeNum
    if(num <= 1) return false;

    for(int i = 2; i <= num/2; i++)
    {
        if(num % i == 0) return false;
    }

    return true;
}

int main()
{
    int num_of_numbers;
    cin >> num_of_numbers;

    int input;
    std::vector<int> num_vec;
    for(int i = 0; i < num_of_numbers; i++)
    {
        cin >> input;
        num_vec.push_back(input);
    }

    int result = 0;
    for(auto num : num_vec)
    {
        if(PrimeNumberJudge(num)) result++;
    }

    cout << result;

    return 0;
}