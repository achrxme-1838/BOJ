#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    string file_name;
    string extension_name;
    bool extension_idx = false;

    map<string, int> name_to_num;

    for(int i=0; i<N; i++){
        cin >> file_name;
        extension_name.clear();
        extension_idx = false;
        for(auto c : file_name){
            if(extension_idx) extension_name += c;
            if(c == '.') extension_idx = true;
        }

        if(name_to_num.count(extension_name) == 0) name_to_num.insert({extension_name, 1});
        else name_to_num[extension_name] += 1;
    }

    for(const auto& m : name_to_num){
        cout << m.first << ' ' << m.second << '\n';
    }

}