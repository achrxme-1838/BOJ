#include <iostream>

using namespace std;

int count_0 = 0;
int count_1 = 0;
int fibonacci(int n){
    if(n==0){
        count_0++;
        return 0;
    } else if (n == 1){
        count_1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T; cin >> T;
    for(int i=0; i<T; i++){
        int in; cin >> in;
        fibonacci(in);
        cout << count_0 << ' ' << count_1 << '\n';
        count_0 = 0; count_1 = 0;
    }

    return 0;

}