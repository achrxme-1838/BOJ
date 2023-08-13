#include <iostream>

using namespace std;

bool CountContinuous6(int num)
{
    while(num > 0)
    {
        if(num % 1000 == 666) return true;
        num = num / 10;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    int test_num = 665;
    int count = 0;

    while(true)
    {
        if(CountContinuous6(test_num)) count +=1;

        if(count >= N) break;
        test_num += 1;
    }

    cout << test_num;

    return 0;
}