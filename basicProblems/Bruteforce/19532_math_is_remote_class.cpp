#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int ans_x, ans_y;
    bool sol_index = false;

    for(int x = -999; x <= 999; x++)
    {
        for(int y = -999; y <= 999; y++)
        {
            if(a*x + b*y == c and d*x + e*y == f)
            {
                ans_x = x;
                ans_y = y;
                sol_index = true;
                break;
            }
        }

        if(sol_index) break;
    }

    cout << ans_x << " " << ans_y;


    return 0;
}
