#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K; cin >> N >> K;

    int ans = 1;
    for(int i=0; i<K; i++){
        ans = ans * (N-i);
    }
    int div = 1;
    for(int i=1; i<=K; i++){
        div = div * i;
    }
    cout << ans / div;


    return 0;
}