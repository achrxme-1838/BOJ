#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    int N_number;
    std::set<int> N_number_set;

    for (int i = 0; i < N; i++) {
        cin >> N_number;
        N_number_set.insert(N_number);
    }

    int M;
    cin >> M;

    int M_number;
    std::vector<int> M_number_vec;

    for (int i = 0; i < M; i++) {
        cin >> M_number;
        M_number_vec.push_back(M_number);
    }

    for (int i: M_number_vec) {
        if (N_number_set.find(i) != N_number_set.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}
