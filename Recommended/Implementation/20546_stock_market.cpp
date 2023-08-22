#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int money;
    cin >> money;

    int BNP_budget = money;
    int TIMING_budget = money;
    int BNP_num = 0;
    int TIMING_num = 0;

    int price;
    int last_price;
    std::vector<int> stock_price_vec;
    for(int i=0; i<14; i++){
        cin >> price;
        stock_price_vec.push_back(price);
        if(i == 13) last_price = price;
    }

    int up_stack = 0;
    int down_stack = 0;

    int previous_price = stock_price_vec[0];

    for(auto price : stock_price_vec){
        int max_BNP_buy = BNP_budget / price;
        BNP_budget -= price * max_BNP_buy;
        BNP_num += max_BNP_buy;

        if(price > previous_price){
            up_stack ++;
            down_stack = 0;
        }
        if(price < previous_price){
            down_stack ++;
            up_stack = 0;
        }
        if(down_stack >= 3){
            int max_TIMING_buy = TIMING_budget / price;
            TIMING_budget -= price * max_TIMING_buy;
            TIMING_num += max_TIMING_buy;
        }
        if(up_stack >= 3){
            TIMING_budget += price * TIMING_num;
            TIMING_num = 0;
        }
    }

    int BNP_result = BNP_budget + BNP_num * last_price;
    int TIMIME_result = TIMING_budget + TIMING_num * last_price;

    if(BNP_result > TIMIME_result) cout << "BNP";
    else if(BNP_result < TIMIME_result) cout << "TIMING";
    else cout << "SAMESAME";

    return 0;
}