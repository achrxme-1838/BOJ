#include <iostream>
#include <vector>
#define MAXSIZE 10001

using namespace std;

void dfs(int idx, vector<int>* tree, vector<bool>& visited,
         int target, vector<int>& trajectory){
    visited[idx] = true;
    trajectory.push_back(idx);

    if(idx == target) return;

    for(auto next : tree[idx]){
        if(next == -1) return;

        if(!visited[next]) {
            dfs(next, tree, visited, target, trajectory);
            if(trajectory.back() == target) return;
        }
    }

    trajectory.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; cin >> T;

    for(int t=0; t<T; t++){
        vector<int> tree[MAXSIZE];
        vector<bool> visited_1(MAXSIZE, false);
        vector<bool> visited_2(MAXSIZE, false);

        int N; cin >> N;

        int root = -1;
        vector<bool> root_idx(N, true);

        for(int n=0; n<N-1; n++){
            int a, b;
            cin >> a >> b;

            tree[a].push_back(b);
            root_idx[b] = false;
        }

        for(int r=1; r<N; r++){
            if(root_idx[r]) root = r;
        }

        int target_1, target_2;
        cin >> target_1 >> target_2;

        vector<int> traj_1;
        vector<int> traj_2;

        dfs(root, tree, visited_1, target_1, traj_1);
        dfs(root, tree, visited_2, target_2, traj_2);

        int deepest_common = -1;
        for(auto t1 : traj_1) {
            for (auto t2: traj_2) {
                if(t1 == t2){
                    deepest_common = t1;
                }
            }
        }
        cout << deepest_common << '\n';

    }


}
