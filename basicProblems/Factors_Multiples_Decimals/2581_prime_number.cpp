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
    int M, N;
    cin >> M >> N;

    int min_prime = 10000;
    int sum = 0;
    for(int i = M; i <= N; i++)
    {
        if(PrimeNumberJudge(i))
        {
            if(i < min_prime) min_prime = i;
            sum+=i;
        }
    }

    if(sum) {
        cout << sum << endl;
        cout << min_prime << endl;
    }
    else cout << -1 << endl;

}