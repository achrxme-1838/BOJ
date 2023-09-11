#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    string in; cin >> in;
    int ans = 0;
    for(auto i: in){
        ans += int(i) - 48;
    }

    cout << ans;

    return 0;
}