#include <iostream>
#include <array>

using namespace std;

int ReturnMaxLength(std::array<int, 3> sides, int& max_index)
{
    int max_length = 0;

    for(int i = 0; i < 3; i++)
    {
        if(sides[i] > max_length){
            max_length = sides[i];
            max_index = i;
        }
    }
    return max_length;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    std::array<int, 3> sides{a, b, c};

    int max_index = 0;
    int max_length = ReturnMaxLength(sides, max_index);
    if(max_length >= a + b + c - max_length){
        sides[max_index] = a + b + c - max_length - 1;
    }

    cout << sides[0] + sides[1] + sides[2];

    return 0;
}