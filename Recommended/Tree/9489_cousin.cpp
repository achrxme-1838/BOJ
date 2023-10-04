#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXSIZE 1000001

using namespace std;

map<int, vector<int>> tree;
vector<int> visited(MAXSIZE, false);
vector<int> parent(MAXSIZE);

int target_parent;
int cnt = 0;
bool no_parent;

void DFS_depth2(int idx, int d){
    visited[idx] = true;
    if(d == 2){
        cnt ++;
        return;
    }

    for(auto next : tree[idx]){
        if(!visited[next]) {
            if(next!= target_parent) DFS_depth2(next, d+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    while(true) {
        no_parent = false;

        int N, K;
        cin >> N >> K;

        if(N==0 and K==0) break;

        int prev = -1;
        queue<int> temp_leaf;
        int temp_parent;

        for (int n = 0; n < N; n++) {
            int in;
            cin >> in;
            if (n == 0) {
                temp_leaf.push(in);
            } else {
                if (in != prev + 1) { // discontinued -> shift to next parent
                    temp_parent = temp_leaf.front();
                    tree.insert({temp_parent, {}});
                    temp_leaf.pop();
                }
                tree[temp_parent].push_back(in);
                parent[in] = temp_parent;

                temp_leaf.push(in);

                prev = in;
            }
        }

        target_parent = parent[K];
        int target_grand = parent[target_parent];
        if (target_parent == 0 or target_grand == 0) {
            no_parent = true;
        }
        if(!no_parent)
            DFS_depth2(target_grand, 0);

        if (!no_parent) cout << cnt << '\n';
        else cout << 0 << '\n';

        tree.clear();
        for(int i=0; i<MAXSIZE; i++){
            visited[i] = false;
            parent[i] = 0;
        }

        cnt = 0;
        no_parent = false;

    }
}
