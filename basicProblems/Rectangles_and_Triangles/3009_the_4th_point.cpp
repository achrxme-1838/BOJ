#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int, int>> points;
    int x, y;

    int count = 0;
    while (cin >> x >> y) {
        count++;
        points.push_back({x, y});
        if(count > 2) break;
    }

    int x_4 = 0, y_4 = 0;

    int x_1 = points[0].first;
    int x_2 = points[1].first;
    int x_3 = points[2].first;

    if(x_1 == x_2) x_4 = x_3;
    else{
        if(x_1 == x_3) x_4 = x_2;
        else x_4 = x_1;
    }

    int y_1 = points[0].second;
    int y_2 = points[1].second;
    int y_3 = points[2].second;

    if(y_1 == y_2) y_4 = y_3;
    else{
        if(y_1 == y_3) y_4 = y_2;
        else y_4 = y_1;
    }

    cout << x_4 << " " << y_4;


    return 0;
}