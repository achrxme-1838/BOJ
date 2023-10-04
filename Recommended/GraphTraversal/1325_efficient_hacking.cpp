#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};


vector<int> graph[10001];
bool visited[10001];
int cnt = 0;

void DFS(int idx){
    visited[idx] = true;
    cnt ++;
    for(auto v : graph[idx]){
        if(!visited[v]) DFS(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> output;

    for(int i=1; i<=N; i++) {
        DFS(i);
        output.push({cnt, i});
        cnt = 0;
        memset(visited, false, sizeof(visited));
    }

    if(!output.empty()){
        int idx = output.top().first;
        int result = output.top().second;
        output.pop();
        cout << result << ' ';
        while(!output.empty() && idx==output.top().first){
            cout << output.top().second << ' ';
            output.pop();
        }
    }
}