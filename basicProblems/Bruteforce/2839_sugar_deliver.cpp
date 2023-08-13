#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int max_5 = N / 5;
    int max_3 = N / 3;

    int min_vinyl = 10000;
    int current_vinyl;

    for(int num_5=0; num_5<=max_5; num_5++){
        for(int num_3=0; num_3<=max_3; num_3++){
            if(N - num_3*3 - num_5*5 == 0){
                current_vinyl = num_5 + num_3;
                if(current_vinyl < min_vinyl) min_vinyl = current_vinyl;
            }
        }
    }

    if(min_vinyl != 10000) cout << min_vinyl;
    else cout << -1;

    return 0;
}
