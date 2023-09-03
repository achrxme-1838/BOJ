#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    deque<pair<int, int>> balloon;
    for(int n=1; n<=N; n++){
        int in; cin >> in;
        balloon.emplace_back(in, n);
    }

    auto rot = balloon.front();
    balloon.pop_front();
    cout << rot.second << ' ';

    for(int n=0; n<N-1; n++) {

        bool direction = false;
        if(rot.first > 0) direction = true;

        if(direction){
            for(int i=0; i<rot.first-1; i++){
                auto temp = balloon.front();
                balloon.pop_front();
                balloon.push_back(temp);
            }
            rot = balloon.front();
            balloon.pop_front();
        }
        else{
            for(int i=0; i>rot.first+1; i--){
                auto temp = balloon.back();
                balloon.pop_back();
                balloon.push_front(temp);
            }
            rot = balloon.back();
            balloon.pop_back();
        }
        cout << rot.second << ' ';
    }

    return 0;
}