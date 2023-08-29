#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> dates(N);

    int start = 100000;
    int end = 0;

    for(int i=0; i<N; i++){
        int S, E;
        cin >> S >> E;
        dates[i] = {S, E};

        start = min(start, S);
        end = max(end, E);
    }

    vector<int> calendar(end-start+1, 0);

    for(auto date: dates){
        for(int i=date.first - start; i<= date.second - start; i++){
            calendar[i]++;
        }
    }

    int continuous = 0;
    int max_h = 0;
    int area = 0;
    for(auto cal : calendar){
        if(cal != 0){
            continuous++;
            max_h = max(max_h, cal);
        }
        else{
            area += continuous * max_h;
            continuous = 0;
            max_h = 0;
        }
    }
    area += continuous * max_h;

    cout << area;

    return 0;
}