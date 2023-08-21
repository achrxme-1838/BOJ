#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    cin >> T;

    std::vector<std::pair<int, int>> input_vec;
    int A, B;
    for(int i=0; i<T; i++){
        cin >> A >> B;
        input_vec.push_back({A, B});
    }

    for(auto pair : input_vec){
        int i = 1;
        int j = 1;
        while(true){
            if(pair.first*i == pair.second*j){
                cout << pair.first*i << '\n';
                break;
            }
            else if(pair.first*i > pair.second*j) j++;
            else i++;
        }
    }

    return 0;
}