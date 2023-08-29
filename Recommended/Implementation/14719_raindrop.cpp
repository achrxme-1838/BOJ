#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<int> blocks(W, 0);
    int block_h;
    for(int i=0; i<W; i++){
        cin >> block_h;
        blocks[i] = block_h;
    }

    int rain_cnt = 0;
    for(int h=0; h<H; h++){
        int left_most = W;
        int right_most = -1;
        int block_cnt = 0;
        for(int x=0; x<W; x++){
            if(blocks[x] > h){
                left_most = min(x, left_most);
                right_most = max(x, right_most);
                block_cnt ++;
            }
        }
        if(left_most < W and right_most > -1 and left_most != right_most){
            rain_cnt += (right_most - left_most) - block_cnt + 1;
        }
    }
    cout << rain_cnt;

    return 0;
}