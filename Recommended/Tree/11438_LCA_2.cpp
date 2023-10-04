#include <iostream>
#include <vector>
#include <array>

#define MAXSIZE 100001
#define MAX_HEIGHT 20

using namespace std;

vector<int> tree_1[MAXSIZE];
vector<int> depth(MAXSIZE);
vector<array<int, MAX_HEIGHT>> parent(MAXSIZE, {0, });
vector<int> visited(MAXSIZE, false);

void DFS(int idx, int prev, int d){

    visited[idx] = true;
    depth[idx] = d;
    parent[idx][0] = prev;

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

    int temp = N;
    int cnt = 0;
    while(temp > 1){
        temp = temp>>1;
        ++cnt;
    }
    int max_height = cnt;

    for(int k=1; k<=max_height; k++)
        for(int idx=2; idx<=N; idx++)
            if(parent[idx][k-1] != 0)
                parent[idx][k] = parent[parent[idx][k-1]][k-1];


    int M; cin >> M;

    for(int m=0; m<M; m++){
        int a, b; cin >> a >> b;

        while(depth[a] != depth[b]) {
            if(depth[a] < depth[b])
                swap(a, b);
            int dif = depth[a] - depth[b];
            for(int i=0; dif>0; i++){
                if(dif%2 == 1) a = parent[a][i];
                dif = dif >> 1;
            }
        }

        if(a!=b){
            for(int k = max_height; k>=0; k--){
                if(parent[a][k]!=0 and parent[a][k]!=parent[b][k]){
                    a = parent[a][k];
                    b = parent[b][k];
                }
            }
            a = parent[a][0];
        }

        cout << a << '\n';

    }
}