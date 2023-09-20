#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[200001];
bool visited[200001];

vector<int> dist_vec;

void branch_search(int idx, int cur_dist){
    visited[idx] = true;

    vector<pair<int, int>> unvisited_node;
    for(auto node: tree[idx]){
        if(!visited[node.first]) {
            unvisited_node.push_back(node);
        }
    }

    if(unvisited_node.empty()) {
        dist_vec.push_back(cur_dist);
        return;
    }

    for(auto next_idx_pair: unvisited_node){
        branch_search(next_idx_pair.first, cur_dist + next_idx_pair.second);
    }

}

int column_dist = 0;

void column_search(int idx){
    visited[idx] = true;

    vector<pair<int, int>> unvisited_node;
    for(auto node: tree[idx]){
        if(!visited[node.first]) {
            unvisited_node.push_back(node);
        }
    }

    if(unvisited_node.size() >= 2){
        branch_search(idx, 0);
        return;
    }
    if(unvisited_node.empty()){
        return;
    }

    int next_idx = unvisited_node[0].first;
    int next_dist = unvisited_node[0].second;
    column_dist += next_dist;
    column_search(next_idx);
}

int main(){

    int N, R; cin >> N >> R;

    for(int n=0; n<N-1; n++){
        int a, b, d;
        cin >> a >> b >> d;

        tree[a].emplace_back(b, d);
        tree[b].emplace_back(a, d);
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

