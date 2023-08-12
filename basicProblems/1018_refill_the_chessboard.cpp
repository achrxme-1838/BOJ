#include <iostream>
#include <vector>

using namespace std;

int PaintBoard(vector<vector<char>> board_o ,int x_init, int y_init, char W_or_B)
{
    char odd_char, even_char;

    if(W_or_B == 'W'){
        even_char = 'W';
        odd_char = 'B';
    }
    else{
        even_char = 'B';
        odd_char = 'W';
    }

    int paint_num = 0;

    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if((x + x_init + y + y_init) % 2 == 0 and board_o[y_init+y][x_init+x] != even_char) paint_num += 1;
            if((x + x_init + y + y_init) % 2 == 1 and board_o[y_init+y][x_init+x] != odd_char) paint_num += 1;
        }
    }
    return paint_num;
}

int main()
{
    int N, M;           // N : the number of rows, M : the number of columns
    cin >> N >> M;

    char W_or_B;
    vector<vector<char>> initial_board_state;
    vector<char> initial_row_state;

    for(int i=0; i<N; i++){
        initial_row_state.clear();
        for(int j=0; j<M; j++){
            cin >> W_or_B;
            initial_row_state.push_back(W_or_B);
        }
        initial_board_state.push_back(initial_row_state);
    }

    int current_min = 100;
    for(int x=0; x+8<=M; x++){
        for(int y=0; y+8<=N; y++){

            int W_num = PaintBoard(initial_board_state, x, y, 'W');
            int B_num = PaintBoard(initial_board_state, x, y, 'B');

            if(W_num < current_min) current_min = W_num;
            if(B_num < current_min) current_min = B_num;
        }
    }

    cout << current_min;

    return 0;
}
