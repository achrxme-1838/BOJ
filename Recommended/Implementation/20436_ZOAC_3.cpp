#include <iostream>
#include <cstdlib>

using namespace std;

void char_to_position(char input, int& x, int& y){
    int key_line_1[10]{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    int key_line_2[9]{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    int key_line_3[7]{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for(int i=0; i<10; i++){
        if(input == key_line_1[i]){
            x = i; y = 0; return;
        }
    }
    for(int i=0; i<9; i++){
        if(input == key_line_2[i]){
            x = i; y = 1; return;
        }
    }
    for(int i=0; i<7; i++){
        if(input == key_line_3[i]){
            x = i; y = 2; return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    char left_char, right_char;
    int left_x, left_y, right_x, right_y;
    cin >> left_char >> right_char;
    char_to_position(left_char, left_x, left_y);
    char_to_position(right_char, right_x, right_y);

    std::string input_word;
    cin >> input_word;

    int new_x, new_y;
    int sum_of_time = 0;

    for(auto c : input_word){
        char_to_position(c, new_x, new_y);
        // at left side
        if((new_y == 0 and new_x <= 4)
            or (new_y == 1 and new_x <= 4)
            or (new_y == 2 and new_x <= 3)){

            sum_of_time += abs(new_x - left_x) + abs(new_y - left_y) + 1;
            left_x = new_x;
            left_y = new_y;
        }
        // at right side
        else {
            sum_of_time += abs(new_x - right_x) + abs(new_y - right_y) + 1;
            right_x = new_x;
            right_y = new_y;
        }
    }

    cout << sum_of_time;

    return 0;
}