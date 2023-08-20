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
    cin >> N >> M;

    std::string name;
    std::map<std::string, int> name_to_num;

    int count = 0;

    for(int i=0; i<N+M; i++){
        cin >> name;
        auto iter = name_to_num.find(name);
        if(iter == name_to_num.end()){
            name_to_num.insert({name, 1});
        }
        else{
            iter->second += 1;
            if(iter->second == 2) count++;
        }
    }

    cout << count << '\n';
    for(auto pair: name_to_num)
    {
        if(pair.second == 2) cout << pair.first << '\n';
    }


    return 0;
}