#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> relations[500001];
bool visited[500001] = {false, };

int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    double W;
    cin >> N >> W;
    for(int n=0; n<N-1; n++){
        int a, b;
        cin >> a >> b;

        relations[a].push_back(b);
        relations[b].push_back(a);
    }

    double leaf_num = 0;

    queue<int> q;
    visited[1] = true;
    q.push(1);

    while(!q.empty()){
        int current_idx = q.front();
        q.pop();

        bool current_is_not_leaf = false;

        for(int i=0; i < relations[current_idx].size(); i++){
            int next = relations[current_idx][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                // 현재 node에 방문 한적 없는 node가 연결 -> 그게 곧 자식 node -> 지금 노드가 leaf가 아님
                current_is_not_leaf = true;
            }
        }
        if(!current_is_not_leaf) leaf_num ++;
    }

    cout << fixed;
    cout.precision(10);
    cout << W / leaf_num;


    return 0;
}

