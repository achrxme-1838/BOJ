#include <iostream>
#include <vector>
#include <set>

using namespace std;

int a, b, idx=1;
vector <pair<int, int>> edges;
set <int> nodes;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        if (a == 0 && b == 0) {
            if (edges.size() + 1 == nodes.size() or edges.size() == 0) {
                cout << "Case " << idx << " is a tree.\n";
            }
            else {
                cout << "Case " << idx << " is not a tree.\n";
            }
            idx++;
            nodes.clear();
            edges.clear();
        }
        else {
            nodes.insert(a);
            nodes.insert(b);
            edges.emplace_back( a,b );
        }
    }


}