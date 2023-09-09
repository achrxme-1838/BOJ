#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::priority_queue<long long, std::vector<long long>, std::greater<>> min_queue;

    for(int n=1; n<=N*N; n++){
        long long in;
        std::cin >> in;
        if(n<=N+1) min_queue.push(in);
        else{
            min_queue.pop();
            min_queue.push(in);
        }
    }
    min_queue.pop();
    std::cout << min_queue.top();

    return 0;
}