#include <iostream>
#include <vector>

using namespace std;

bool PrimeNumberJudge(int num)
{
    // true : primeNum
    if(num <= 1) return false;

    for(int i = 2; i <= num/2; i++){
        if(num % i == 0) return false;
    }
    return true;
}

std::vector<int> factor_vec;

void Factorization(int input)
{
    if(PrimeNumberJudge(input)){
        factor_vec.push_back(input);
        return;
    }

    for(int i = 2 ; i <= input / 2 ; i++){
        if(input % i == 0){
            Factorization(i);
            Factorization(input / i);
            return;
        }
    }
}

int main()
{
    int input;
    cin >> input;

    Factorization(input);

    for(auto i : factor_vec)
    {
        cout << i << endl;
    }

    return 0;
}