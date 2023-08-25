#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    cin >> input;
    std::string copy_input = input;

    char sound[5]{'q', 'u', 'a', 'c', 'k'};

    int sound_idx = 0;
    int input_idx;
    int count = 0;

    bool counted = false;
    int success_stack;

    bool invalid = false;

    while(input.length() > 0)
    {
        input_idx = 0;
        success_stack = 0;
        for(auto c : input){

            if(sound_idx == 0 and c == sound[sound_idx]) {
                sound_idx++; success_stack++;
                copy_input.erase(input_idx, 1);
                input_idx--;
                if(copy_input.length() == 0) invalid = true;
            }
            else if(sound_idx == 1 and c == sound[sound_idx]) {
                sound_idx++; success_stack++;
                copy_input.erase(input_idx, 1);
                input_idx--;
                if(copy_input.length() == 0) invalid = true;
            }
            else if(sound_idx == 2 and c == sound[sound_idx]) {
                sound_idx++; success_stack++;
                copy_input.erase(input_idx, 1);
                input_idx--;
                if(copy_input.length() == 0) invalid = true;
            }
            else if(sound_idx == 3 and c == sound[sound_idx]) {
                sound_idx++; success_stack++;
                copy_input.erase(input_idx, 1);
                input_idx--;
                if(copy_input.length() == 0) invalid = true;
            }
            else if(sound_idx == 4 and c == sound[sound_idx]) {
                sound_idx = 0;
                copy_input.erase(input_idx, 1);
                input_idx--;
                if(!counted and success_stack >= 4){
                    count ++;
                    counted = true;
                }
            }

            input_idx++;
        }
        if(!counted){
            invalid = true;
            break;
        }
        counted = false;
        input = copy_input;
    }

    if (count != 0 and !invalid) cout << count;
    else cout << -1;
}

