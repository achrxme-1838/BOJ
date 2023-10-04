#include <iostream>
#include <vector>
#define MAXSIZE 100001

using namespace std;

vector<pair<int, int>> tree_connect_dist[MAXSIZE];
vector<bool> visited(MAXSIZE, false);

int max_dist = 0;
int max_idx = -1;

void dfs(int idx, int length){

    if(tree_connect_dist[idx].size() <= 1){
        if(length > max_dist) {
            max_dist = length;
            max_idx = idx;
        }
    }

    visited[idx] = true;

    for(auto next : tree_connect_dist[idx]){
        if(!visited[next.first]){
            dfs(next.first, length + next.second);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    for(int n=0; n<N-1; n++){
        int a, b, d;
        cin >> a >> b >> d;

        tree_connect_dist[a].emplace_back(b, d);
        tree_connect_dist[b].emplace_back(a, d);
    }

    if(N==2) {
        cout << tree_connect_dist[1][0].second;
        return 0;
    }
    if(N==1) {
        cout << 0;
        return 0;
    }



    dfs(1, 0);

    max_dist = 0;
    for(int i = 0; i < visited.size(); i ++){
        visited[i] = false;
    }

    dfs(max_idx, 0);
    cout << max_dist;

    return 0;
}