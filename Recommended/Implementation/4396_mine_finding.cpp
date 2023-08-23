#include <iostream>
#include <vector>

using namespace std;

int TestNBH(const std::vector<std::vector<bool>>& mine_map, int x, int y, int N){

    int result = 0;

    if(y - 1 >= 0) {
        if (mine_map[y - 1][x]) result++;
        if(x + 1 < N) {
            if (mine_map[y - 1][x + 1]) result++;
        }
        if(x - 1 >= 0) {
            if (mine_map[y - 1][x - 1]) result++;
        }
    }

    if(x - 1 >= 0) {
        if (mine_map[y][x - 1]) result++;
    }
    if(x + 1 < N) {
        if (mine_map[y][x + 1]) result++;
    }

    if(y + 1 < N) {
        if (mine_map[y + 1][x]) result++;
        if(x + 1 < N) {
            if (mine_map[y + 1][x + 1]) result++;
        }
        if(x - 1 >= 0) {
            if (mine_map[y + 1][x - 1]) result++;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    std::vector<std::vector<bool>> mine_map;
    std::vector<bool> mine_line;
    char input;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input;
            if(input == '.') {
                mine_line.push_back(false);
            }
            else mine_line.push_back(true);
        }
        mine_map.push_back(mine_line);
        mine_line.clear();
    }

    std::vector<std::vector<char>> open_map;
    std::vector<char> open_line;
    char open;

    bool game_end = false;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> open;
            open_line.push_back(open);
            if(open == 'x' and mine_map[i][j]) {
                game_end = true;
            }
        }
        open_map.push_back(open_line);
        open_line.clear();
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!game_end) {
                if (open_map[i][j] == 'x') {
                    int result = TestNBH(mine_map, j, i, N);
                    cout << result;
                }
                else cout << '.';
            }
            else{
                if (open_map[i][j] == 'x') {
                    int result = TestNBH(mine_map, j, i, N);
                    if(mine_map[i][j]) cout << '*';
                    else cout << result;
                }
                else {
                    if(mine_map[i][j]) cout << '*';
                    else cout << '.';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}