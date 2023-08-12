#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points;
    int x, y;

    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    int x_min = 10000, x_max = -10000;
    int y_min = 10000, y_max = -10000;

    for(auto point :points)
    {
        if(point.first > x_max) x_max = point.first;
        if(point.first < x_min) x_min = point.first;

        if(point.second > y_max) y_max = point.second;
        if(point.second < y_min) y_min = point.second;
    }

    cout << (x_max - x_min) * (y_max - y_min) << endl;


    return 0;
}