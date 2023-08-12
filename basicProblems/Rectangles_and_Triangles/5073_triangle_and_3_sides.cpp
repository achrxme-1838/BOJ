#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {

    vector<array<int, 3>> side_vec;
    int a, b, c;

    while (cin >> a >> b >> c){
        if(a + b + c == 0) break;

        array<int,3> side = {a, b, c};
        side_vec.push_back(side);
    }

    int max_side_length;

    for(auto side : side_vec)
    {
        max_side_length = 0;

        for(int i = 0 ; i < 3 ; i++){
            if(max_side_length < side[i]){
                max_side_length = side[i];
            }
        }

        if(max_side_length < side[0] + side[1] + side[2] - max_side_length) {
            if (side[0] == side[1] and side[1] == side[2]) cout << "Equilateral" << endl;
            else if (side[0] == side[1] or side[0] == side[2] or side[1] == side[2]) cout << "Isosceles" << endl;
            else cout << "Scalene" << endl;
        }
        else{
            cout << "Invalid" << endl;
        }

    }


    return 0;
}