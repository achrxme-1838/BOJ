#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    set<int> out_set;
    set<int> in_set;
    set<int> s;

    bool root_exist = true;
    bool double_access = false;
    bool self_loop = false;
    int case_idx = 1;

    int edge_size = 0;

    while(true){
        int a, b; cin >> a >> b;
        if(a!=0 and a!=-1 and a==b) {
            self_loop = true;
            continue;
        }
        if(a!=0 and a!=-1) edge_size++;

        if(a == 0 and b == 0){
            // out set의 원소들 중 in set에 없는 원소만
            set<int> only_out_set;
            for(auto out: out_set){
                if(in_set.find(out) == in_set.end()){
                    only_out_set.insert(out);
                }
            }
            if(only_out_set.size()!=1) root_exist = false;
            if(self_loop) cout << "Case " << case_idx << " is a tree.\n";
            if(root_exist and !double_access
                and s.size() == edge_size+1) cout << "Case " << case_idx << " is a tree.\n";
            else cout << "Case " << case_idx << " is not a tree.\n";

            root_exist = true;
            double_access = false;
            edge_size = 0;

            out_set.clear();
            in_set.clear();
            case_idx++;
            continue;
        }
        if(a == -1 and b == -1){
            break;
        }

        s.insert(a);
        s.insert(b);

        out_set.insert(a);

        if(in_set.find(b) == in_set.end()) {
            in_set.insert(b);
        }
        else{
            double_access = true;
        }
    }
}