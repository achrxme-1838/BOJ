#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char&b){
    char temp = a;
    a = b;
    b = temp;
}

void reverse_word(std::string& word){
    unsigned long length = word.length();
    for(int i=0; i<length/2; i++){
        swap(word[i], word[length - i - 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string input;
    getline(cin, input);

    bool tag_flag = false;
    bool space_flag = false;

    std::string output;
    std::string word_stack;

    for(auto c : input){
        if( c == '<') tag_flag = true;
        if( c == '>') {
            output += c;
            tag_flag = false;
        }

        if(!tag_flag and c !=' ' and c != '>') word_stack += c;

        if(word_stack.length() != 0 and (c ==' ' or tag_flag)){
            reverse_word(word_stack);

            output += word_stack;
            word_stack.clear();

            if(c == ' ') output += ' ';
        }

        if(tag_flag) output += c;
    }

    reverse_word(word_stack);
    output += word_stack;

    cout << output;
}