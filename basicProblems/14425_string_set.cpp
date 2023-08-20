#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    std::string input;
    std::set<std::string> N_string_set;

    for (int i = 0; i < N; i++) {
        cin >> input;
        N_string_set.insert(input);
    }

    std::string test;
    int count = 0;
    for(int i = 0; i < M; i++){
        cin >> test;
        if(N_string_set.find(test) != N_string_set.end()) count++;
    }

    cout << count;

    return 0;
}
