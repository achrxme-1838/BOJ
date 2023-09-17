#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    map<int, int> relation_num;

    for(int n=0; n<N-1; n++){
        int a, b; cin >> a >> b;

        if(relation_num.find(a) == relation_num.end()){
            relation_num.insert({a, 1});
        }
        else relation_num[a]++;


        if(relation_num.find(b) == relation_num.end()){
            relation_num.insert({b, 1});
        }
        else relation_num[b]++;
    }

    int q; cin >> q;

    for(int i=0; i<q; i++){
        int t, k; cin >> t >> k;
        if(t==1){
            if(relation_num[k] > 1){
                cout << "yes\n";
            }
            else cout << "no\n";
        }
        if(t==2){
            cout << "yes\n";
        }


    }

    return 0;

}