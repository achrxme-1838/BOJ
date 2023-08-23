#include <iostream>
#include <vector>

using namespace std;

void MaleChange(std::vector<bool>& switch_vec, int switch_name, int N){
    int target = switch_name - 1;

    while(target < N){
        switch_vec[target] = !(switch_vec[target]);
        target = target + switch_name;
    }
}

void FemaleChange(std::vector<bool>& switch_vec, int switch_name, int N){
    int target = switch_name - 1;
    int right = target + 1;
    int left = target - 1;

    switch_vec[target] = !(switch_vec[target]);

    while(switch_vec[left] == switch_vec[right]){
        if(right >= N) break;
        if(left < 0) break;

        switch_vec[left] = !(switch_vec[left]);
        switch_vec[right] = !(switch_vec[right]);
        right++;
        left--;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num_of_switch;
    cin >> num_of_switch;

    std::vector<bool> switch_vec;
    int switch_input;
    for(int i=0; i<num_of_switch; i++){
        cin >> switch_input;
        if(switch_input == 0) switch_vec.push_back(false);
        else switch_vec.push_back(true);
    }

    int num_of_student;
    cin >> num_of_student;

    int gender;
    int switch_name;
    for(int i=0; i<num_of_student; i++){
        cin >> gender >> switch_name;
        if(gender==1){
            MaleChange(switch_vec, switch_name, num_of_switch);
        }
        if(gender==2){
            FemaleChange(switch_vec, switch_name, num_of_switch);
        }
    }

    for(int i=0; i<num_of_switch; i++){
        if(switch_vec[i]) cout << '1' << ' ';
        if(!switch_vec[i]) cout << '0' << ' ';
        if((i+1) % 20 == 0) cout << '\n';
    }

    return 0;
}
