#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    std::vector<int> num_list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::string str = "1asc";

    if(find(num_list.begin(), num_list.end(), int(str[0])) != num_list.end() )
        cout << "true";


}