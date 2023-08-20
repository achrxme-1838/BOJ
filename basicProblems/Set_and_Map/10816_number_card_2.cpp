#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    cin >> N;

    int integer;
    std::map<int, int> integer_to_num_of;

    for(int i=0; i<N; i++){
        cin >> integer;
        auto iter = integer_to_num_of.find(integer);
        if(iter == integer_to_num_of.end()){
            integer_to_num_of.insert({integer, 1});
        }
        else{
            iter->second += 1;
        }
    }

    cin >> M;
    std::vector<int> test_vec;
    int test_num;
    for(int i=0; i<M; i++){
        cin >> test_num;
        test_vec.push_back(test_num);
    }

    for(auto test : test_vec){
        cout << integer_to_num_of[test] << " ";
    }


    return 0;
}
