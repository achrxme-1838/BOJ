#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::string word_1, std::string word_2){
    if(word_1.size() == word_2.size())
        return word_1 < word_2;
    else
        return word_1.size() < word_2.size();
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::string> words;
    std::string word;
    for(int i=0; i<N; i++)
    {
        std::cin >> word;
        words.push_back(word);
    }

    std::sort(words.begin(), words.end(), compare);
    words.erase(std::unique(words.begin(), words.end()), words.end());

    for(int i = 0; i < words.size(); i++){
        std::cout << words[i] << std::endl;
    }

    return 0;
}