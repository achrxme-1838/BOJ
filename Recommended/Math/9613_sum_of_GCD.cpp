#include <iostream>
#include <vector>

using namespace std;

int GCD(int A, int B)
{
    while(B > 0)
    {
        int tmp = A;
        A = B;
        B = tmp % B;
    }

    return A;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    for(int n=0; n<N; n++){
        int K; cin >> K;

        vector<int> input_list;
        input_list.clear();

        long long int sol=0;

        for(int k=0; k<K; k++){
            int num; cin >> num;
            input_list.push_back(num);
        }

        for(int k=0; k<K-1; k++){
            int A = input_list[k];
            for(int j=k+1; j<K; j++){
                int B = input_list[j];
                sol += GCD(A, B);
            }
        }

        cout << sol << '\n';
    }
}