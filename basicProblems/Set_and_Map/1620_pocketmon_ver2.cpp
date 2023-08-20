#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    std::string name;
    std::map<std::string, int> name_to_num;
    std::map<int, std::string> num_to_name;

    for(int i=1; i<N+1; i++)
    {
        cin >> name;
        name_to_num.insert({name, i});
        num_to_name.insert({i, name});
    }

    std::string input;
    std::vector<std::string> input_vec;
    for(int i=0; i<M; i++)
    {
        cin >> input;
        input_vec.push_back(input);
    }


    for(auto input : input_vec)
    {
        if(isdigit(input[0])){
            cout << num_to_name[stoi(input)] << '\n';
        }
        else{
            cout << name_to_num[input] << '\n';
        }
    }

    return 0;
}