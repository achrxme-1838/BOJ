#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int last_node = 0;
bool terminated = false;
int cnt = 0;

void InOrder(vector<pair<int, int>>& tree, int node){
    if(node == -1) return;
    InOrder(tree, tree[node].first);
    last_node = node;
    InOrder(tree, tree[node].second);
}

void PseudoInOrder(const vector<pair<int, int>>& tree, int node){

    if(tree[node].first != -1){
        cnt++;
        PseudoInOrder(tree, tree[node].first);
        if(!terminated) cnt ++;

    }
    if(tree[node].second != -1){
        cnt++;
        PseudoInOrder(tree, tree[node].second);
        if(!terminated) cnt++;
    }
    if(node == last_node) {
        terminated = true;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> tree(N+1);

    for(int i=0; i<N; i++){
        int n, a, b; cin >> n >> a >> b;
        tree[n] = {a, b};
    }

    InOrder(tree, 1);
    PseudoInOrder(tree,  1);
    cout << cnt;

}
