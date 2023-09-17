#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> new_tree;
int leaf=0;
void leaf_cnt(int idx){
    if(new_tree[idx].empty()){
        leaf++;
        return;
    }
    else{
        for(auto n: new_tree[idx]){
            leaf_cnt(n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int N;
    vector<int> tree[50];

    cin >> N;
    int root;

    for(int n=0; n<N; n++){
        int in; cin >> in;

        if(in==-1) root = n;
        else tree[in].push_back(n);
    }

    int rm; cin >> rm;
    if(rm == root) cout << 0;
    else {
        for (auto v: tree) {
            vector<int> tmp;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != rm) {
                    tmp.push_back(v[i]);
                }
            }
            new_tree.push_back(tmp);
        }

        leaf_cnt(root);

        cout << leaf;
    }


    return 0;
}