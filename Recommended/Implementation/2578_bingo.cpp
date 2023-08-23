#include <iostream>
#include <vector>

using namespace std;

void FindNum(const std::vector<std::vector<int>>& bingo_board, int& x, int& y,
             const int& input)
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(bingo_board[i][j] == input){
                x = j;
                y = i;
                return;
            }
        }
    }
}

int BingoTest(std::vector<std::vector<bool>>& result_board, const int x, const int y)
{
    int x_count = 0;
    int y_count = 0;
    int cross_left_count = 0;
    int cross_right_count = 0;

    for(int i=0; i<5; i++){
        if(result_board[i][x]) x_count++;
        if(result_board[y][i]) y_count++;
        if(x==y){
            if(result_board[i][i]) cross_left_count++;
        }
        if(x+y==4){
            if(result_board[i][4-i]) cross_right_count++;
        }
    }

    int result = 0;

    if(x_count == 5) result++;
    if(y_count == 5) result++;
    if(cross_left_count == 5) result++;
    if(cross_right_count == 5) result++;

    return  result;
}



int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::vector<int>> bingo_board;
    std::vector<int> line;
    int input;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> input;
            line.push_back(input);
        }
        bingo_board.push_back(line);
        line.clear();
    }

//    for(auto a : bingo_board){
//        for(auto b : a){
//            cout << b << " ";
//        }
//        cout << '\n';
//    }

    std::vector<std::vector<bool>> result_board;
    std::vector<bool> result_line;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            result_line.push_back(false);
        }
        result_board.push_back(result_line);
        result_line.clear();
    }


    int called, x, y;
    int count = 0;
    for(int i=0; i<25; i++)
    {
        cin >> called;
        FindNum(bingo_board, x, y, called);
        result_board[y][x] = true;
        int result = BingoTest(result_board, x, y);
        count += result;
        if(count >= 3){
            cout << i+1;
            break;
        }
    }

    return 0;
}
