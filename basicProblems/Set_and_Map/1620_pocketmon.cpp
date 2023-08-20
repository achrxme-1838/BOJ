#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

bool isNumber(const std::string &str){
    // std::istringstream : input from string
    // cf. std::cin : input from keyboard
    std::istringstream iss(str);
    int number;
    iss >> number; // try converting string to int (extract int from string)
    // if input is int, the converting should be success
    return !iss.fail() && iss.eof();
}

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

    for(auto input : input_vec){
        if(isNumber(input)){
            cout << num_to_name[stoi(input)] << '\n';
        }
        else{
            cout << name_to_num[input] << '\n';
        }
    }

    return 0;
}