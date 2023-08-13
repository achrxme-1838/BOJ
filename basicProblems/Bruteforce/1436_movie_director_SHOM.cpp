#include <iostream>

using namespace std;

bool CountContinuous6(int num)
{

    bool first = false;
    bool second = false;
    bool third = false;

    while(num > 0)
    {
        int remain = num % 10;
        num = (num - remain) / 10;

        if(remain == 6) {
            if(!first) first = true;
            else if(!second) second = true;
            else third = true;
        }
        else{
            if(first){
                first = false;
                second = false;
                third = false;
            }
        }

        if(third) return true;
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
        if(CountContinuous6(test_num)) count += 1;
        if(count >= N) break;
        test_num += 1;
    }

    cout << test_num;

    return 0;
}