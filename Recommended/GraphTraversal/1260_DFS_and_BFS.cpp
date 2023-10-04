#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

array<vector<int>, 1001> graph;
vector<int> visited(1001, false);

void DFS(int idx){
    visited[idx] = true;
    cout << idx << ' ';
    for(auto v : graph[idx]){
        if(!visited[v]) DFS(v);
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int next = q.front();
        q.pop();
        cout << next << ' ';

        for(int tmp : graph[next]){
            if(!visited[tmp]) {
                q.push(tmp);
                visited[tmp] = true;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M, V; cin >> N >> M >> V;
    for(int m=0; m<M; m++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<1001; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);

    cout << '\n';

    for(int n=0; n<1001; n++){
        visited[n] = false;
    }

    BFS(V);
}