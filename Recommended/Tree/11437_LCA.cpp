#include <iostream>
#include <vector>
#define MAXSIZE 50001

using namespace std;

vector<int> tree_1[MAXSIZE];
vector<int> depth(MAXSIZE);
vector<int> parent(MAXSIZE);
vector<int> visited(MAXSIZE, false);

void DFS(int idx, int prev, int d){

    visited[idx] = true;
    depth[idx] = d;
    parent[idx] = prev;

    for(auto next : tree[idx]){
        if(!visited[next]) DFS(next, idx, d+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    for(int n=0; n<N-1; n++){
        int a, b; cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1, -1, 0);

    int M; cin >> M;

    for(int m=0; m<M; m++){
        int a, b; cin >> a >> b;

        while(depth[a] != depth[b]) {
            if (depth[a] > depth[b])    a = parent[a];
            else                        b = parent[b];
        }

        while(a!=b){
            a = parent[a];
            b = parent[b];
        }

        cout << a << '\n';

    }
}