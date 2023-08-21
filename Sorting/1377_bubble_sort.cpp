#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> list;
    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        list.push_back({num, i});
    }

    std::sort(list.begin(), list.end());


    int max_num_of_go_left = 0;
    int idx = 0;
    for(auto pair : list){
        int num_of_go_left = pair.second - idx + 1;
        idx ++;
        if(num_of_go_left > max_num_of_go_left) max_num_of_go_left = num_of_go_left;
    }
    cout << max_num_of_go_left;


    return 0;
}