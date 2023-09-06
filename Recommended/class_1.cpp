#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int counts[10000] = {0, };

    vector<int> input;

    int N; cin >> N;
    int sum = 0;
    for(int i=0; i<N; i++){
        int in; cin >> in;
        input.push_back(in);
        sum += in;
        counts[in+4000]+=1;
    }

    cout << sum / N << '\n';

    sort(input.begin(), input.end());
    cout << input[N/2] << '\n';

    int max_n=0;
    vector<int> max_number;
    for(int i=0; i<10000; i++){
        if(max_n < counts[i]){
            max_n = counts[i];
            max_number.clear();
            max_number.push_back(i-4000);
        }
        if(max_n == counts[i]){
            max_number.push_back(i-4000);
        }
    }

    if(max_number.size() > 1){
        cout << max_number[1] << '\n';
    }
    else cout << max_number[0] << '\n';





    return 0;
}