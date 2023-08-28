#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int num_of_train, num_of_order;
    cin >> num_of_train >> num_of_order;

    std::vector<std::bitset<20>> train_list;
    std::bitset<20> train;
    train.reset();
    for(int _=0; _<num_of_train; _++){
        train_list.push_back(train);
    }

    int order_type, i, x;
    for(int _=0; _<num_of_order; _++) {
        cin >> order_type;
        if (order_type == 1) {
            cin >> i >> x;
            train_list[i-1].set(x-1, true);
        }
        else if (order_type == 2){
            cin >> i >> x;
            train_list[i-1].set(x-1, false);
        }
        else if (order_type == 3){
            cin >> i;
            train_list[i-1] = train_list[i-1] << 1;
        }
        else if (order_type == 4){
            cin >> i;
            train_list[i-1] = train_list[i-1] >> 1;
        }
    }

    std::set<std::string> pass_set;
    int count=0;
    for(auto bit_set : train_list){
        std::string bit_str = bit_set.to_string();
        if(pass_set.find(bit_str)==pass_set.end()) {
            pass_set.insert(bit_str);
            count++;
        }
    }

    cout << count;

    return 0;
}
