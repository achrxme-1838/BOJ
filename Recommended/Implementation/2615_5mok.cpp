#include <iostream>
#include <array>

using namespace std;

bool index_test(int x, int y){
    if(x>=19 or y>=19 or x<0 or y <0) return false;
    return true;
}

int winner(std::array<std::array<int, 19>, 19>& map,
           const int x, const int y){
    int start_num = map[y][x];
    int x_idx; int y_idx; int count;

    if(start_num != 0) {
        // -> direction
        count = 1;
        x_idx = x + 1;
        y_idx = y;
        while (index_test(x_idx, y_idx)
                and (!index_test(x - 1, y) or start_num != map[y][x - 1])
                and start_num == map[y_idx][x_idx]) {
            x_idx++;
            count++;
        }
        if (count == 5) return start_num;

        // down direction
        count = 1;
        x_idx = x;
        y_idx = y + 1;
        while (index_test(x_idx, y_idx)
                and (!index_test(x, y - 1) or start_num != map[y - 1][x])
                and start_num == map[y_idx][x_idx]) {
            y_idx++;
            count++;
        }
        if (count == 5) return start_num;

        // cross down direction
        count = 1;
        x_idx = x + 1;
        y_idx = y + 1;
        while (index_test(x_idx, y_idx)
                and (!index_test(x - 1, y - 1) or start_num != map[y - 1][x - 1])
                and start_num == map[y_idx][x_idx]) {
            x_idx++; y_idx++;
            count++;
        }
        if (count == 5) return start_num;

        // cross up direction
        count = 1;
        x_idx = x + 1;
        y_idx = y - 1;
        while (index_test(x_idx, y_idx)
                and (!index_test(x - 1, y + 1) or start_num != map[y + 1][x - 1])
                and start_num == map[y_idx][x_idx]) {
            x_idx++; y_idx--;
            count++;
        }
        if (count == 5) return start_num;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::array<std::array<int, 19>, 19> map = {{0, }, };

    int input;
    for(int y=0; y<19; y++){
        for(int x=0; x<19; x++){
            cin >> input;
            if(input!=0) map[y][x] = input;
        }
    }
    bool winner_decided = false;
    for(int y=0; y<19; y++){
        for(int x=0; x<19; x++){
            int result = winner(map, x, y);
            if(result != -1){
                winner_decided = true;
                cout << result << '\n' << y + 1 << ' ' << x + 1;
                break;
            }
        }
        if(winner_decided) break;
    }
    if(!winner_decided) cout << '0';

    return 0;
}