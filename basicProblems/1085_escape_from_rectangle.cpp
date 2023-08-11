#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int x_left = x;
    int x_right = w-x;
    int y_up = h-y;
    int y_down = y;

    int min = x_left;

    if(min > x_right) min = x_right;
    if(min > y_up) min = y_up;
    if(min > y_down) min = y_down;

    cout << min;

    return 0;
}