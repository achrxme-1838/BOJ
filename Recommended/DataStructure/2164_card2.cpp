#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    queue<int> q;

    for(int i=1; i<=N; i++){
        q.push(i);
    }

    int idx = 1;
    while(q.size()>1){
        if(idx % 2 == 1){
            q.pop();
        }
        else{
            int qf = q.front();
            q.pop();
            q.push(qf);
        }
        idx++;
    }

    cout << q.front();

    return 0;
}
