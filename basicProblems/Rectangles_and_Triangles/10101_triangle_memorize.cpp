#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> angles;
    int angle;
    for(int i = 0; i < 3; i ++)
    {
        cin >> angle;
        angles.push_back(angle);
    }

    if(angles[0] + angles[1] + angles[2] == 180){
        if(angles[0] == 60 and angles[1] == 60) cout << "Equilateral";
        else{
            if((angles[0]==angles[1]) or (angles[0]==angles[2]) or (angles[1]==angles[2])) cout << "Isosceles";
            else cout << "Scalene";
        }
    }
    else cout << "Error";

    return 0;
}