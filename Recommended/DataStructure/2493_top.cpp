#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    vector<int> test_stack;

    for(int n=0; n<N; n++){
        int test; cin >> test;

        bool success = false;

        int stack_size = test_stack.size();
        int step = 0;
        for(auto t : test_stack){
            if(t > test){
                cout << stack_size - step + 1<< ' ';
                success = true;
                break;
            }
            step++;
        }
        if(!success) cout << 0 << ' ';

        test_stack.push_back(test);
    }




    return 0;
}