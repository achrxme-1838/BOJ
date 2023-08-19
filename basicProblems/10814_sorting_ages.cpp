#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
        return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    pair<int, string> member;
    vector<pair<int, string>> members;

    for(int i=0; i<N; i++)
    {
        cin >> member.first >> member.second;
        members.push_back(member);
    }

    stable_sort(members.begin(), members.end(), compare);
    for(int i = 0; i < members.size(); i++){
        std::cout << members[i].first << ' ' << members[i].second << '\n';
    }

    return 0;
}