#include <iostream>
#include <set>

using namespace std;

struct myOrder
{
    bool operator() (const std::string& left, const std::string& right) const
    {
        return left > right;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    std::string name;
    std::string enter_or_leave;
    std::set<std::string, myOrder> people_set;

    for(int i=0; i<N; i++)
    {
        cin >> name >> enter_or_leave;
        if(enter_or_leave == "enter") people_set.insert(name);
        else people_set.erase(name);
    }

    for(auto person : people_set)
    {
        cout << person << '\n';
    }

}