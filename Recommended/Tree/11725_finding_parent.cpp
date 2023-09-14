#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int patent_arr[MAX];
bool visited[MAX];
vector<int> v[MAX]; // -> this will produce MAX num of vectors
// =! vector<int> v(MAX); ->  this will produce 1 vectors with size MAX

void DFS(int idx){
    visited[idx] = true;
    for(int i=0; i<v[idx].size(); i++){
        int next_idx = v[idx][i];
        if(!visited[next_idx]){
            patent_arr[next_idx] = idx;
            DFS(next_idx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    for(int n=0; n<N-1; n++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i=2; i<=N; i++){
        cout << patent_arr[i] << '\n';
    }


}