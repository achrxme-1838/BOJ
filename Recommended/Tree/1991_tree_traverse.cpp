#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> tree(27, {-1, -1});

void PreorderTraverse(int idx){
    if(idx == -1) return;

    cout << char(idx + 65);
    PreorderTraverse(tree[idx].first);
    PreorderTraverse(tree[idx].second);
}

void InorderTraverse(int idx){
    if(idx == -1) return;

    InorderTraverse(tree[idx].first);
    cout << char(idx + 65);
    InorderTraverse(tree[idx].second);
}

void PostorderTraverse(int idx){
    if(idx == -1) return;

    PostorderTraverse(tree[idx].first);
    PostorderTraverse(tree[idx].second);
    cout << char(idx + 65);
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;

    for(int n=0; n<N; n++){
        char i, j, k;
        cin >> i >> j >> k;
        i -= 65; j-= 65; k-= 65;

        int a = (int)i;
        int b = (int)j;
        int c = (int)k;

        if(b!=46-65) {
            tree[a].first = b;
        }
        if(c!=46-65){
            tree[a].second = c;
        }
    }

    PreorderTraverse(0);
    cout << '\n';
    InorderTraverse(0);
    cout << '\n';
    PostorderTraverse(0);

}