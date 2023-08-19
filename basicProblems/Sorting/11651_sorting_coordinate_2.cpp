#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::pair<int, int> coo_1,std::pair<int, int> coo_2){
    if(coo_1.second == coo_2.second) return coo_1.first < coo_2.first;
    return coo_1.second < coo_2.second;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    scanf("%d", &N);

    std::vector<std::pair<int, int>> coordinates;

    int x, y;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        coordinates.push_back(std::pair<int,int>(x, y));
    }

    std::sort(coordinates.begin(), coordinates.end(), compare);

    for(auto coo : coordinates){
        printf("%d %d\n", coo.first, coo.second);
    }


    return 0;
}