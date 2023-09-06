#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

bool except[201];
vector<pair<int,int>>close;
stack<int> open;
set<string> ans;
string s;

void dfs(int index, int delete_cnt){ // delete_cnt : just for the excluding the first depth

    if(delete_cnt >= 1){
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(!except[i]) temp+=s[i]; // except != 이면 temp에 string을 추가 -> refactoring
        }
        ans.insert(temp);
    }
    // close.size = 3
    for(int i=index; i<close.size(); i++){ // i = 0, 1, 2
        except[close[i].first] = 1;
        except[close[i].second] = 1;
        dfs(i+1, delete_cnt+1); // 1 1 + 2 1 + 3 1
        except[close[i].first] = 0;
        except[close[i].second] = 0;
    }
}
int main(){



    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') open.push(i);
        else if(s[i]==')'){
            close.push_back({open.top(), i});
            cout << open.top() << ' ' << i << '\n';
            open.pop();
        }
    }

    dfs(0,0);

    for(auto it=ans.begin(); it!=ans.end(); it++){
        cout<<*it<<'\n';
    }
}