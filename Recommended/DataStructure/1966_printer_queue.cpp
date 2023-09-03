#include <iostream>
#include <queue>

using namespace std;

int find_max_priority(queue<pair<int, bool>> input){
    auto copy = input;
    int max_p = 0;
    while(!copy.empty()){
        auto a = copy.front();
        copy.pop();
        if(a.first>max_p) max_p = a.first;
    }
    return max_p;
}


int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; cin >> T;
    for(int t=0; t<T; t++){
        int N, M; cin >> N >> M;
        queue<pair<int, bool>> priorities;
        int cnt = 0;

        for(int n=0; n<N; n++){
            int priority; cin >> priority;
            if(n==M) priorities.emplace(priority, true);
            else priorities.emplace(priority, false);
        }
        int max_priority;
        while(true){
            auto front_ = priorities.front();
            priorities.pop();
            max_priority = find_max_priority(priorities);
            if(front_.first < max_priority){
                priorities.push(front_);
            }
            else{
                cnt ++;
                if(front_.second){
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
