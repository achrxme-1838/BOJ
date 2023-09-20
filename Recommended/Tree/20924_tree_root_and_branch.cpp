#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[200001];
vector<int> dist_vec;

void branch_search(int idx, int cur_dist){
    if(tree[idx].empty()) {
        dist_vec.push_back(cur_dist);
        return;
    }

    for(auto next_idx_pair: tree[idx]){
        branch_search(next_idx_pair.first, cur_dist + next_idx_pair.second);
    }

}

int column_dist = 0;

void column_search(int idx){
    if(tree[idx].size() >= 2){
        branch_search(idx, 0);
        return;
    }
    if(tree[idx].empty()){
        return;
    }

    int next_idx = tree[idx][0].first;
    int next_dist = tree[idx][0].second;
    column_dist += next_dist;
    column_search(next_idx);
}

int main(){

    int N, R; cin >> N >> R;

    for(int n=0; n<N-1; n++){
        int a, b, d;
        cin >> a >> b >> d;

        tree[a].emplace_back(b, d);
    }

    column_search(R);

    cout << column_dist << ' ';

    int max_dist = 0;
    for(auto d: dist_vec){
        if(max_dist < d) max_dist = d;
    }

    cout << max_dist;


    return 0;
}

