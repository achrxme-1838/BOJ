#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    std::vector<std::vector<int>> number_map;
    std::vector<int> number_line;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            number_line.push_back(0);
        }
        number_map.push_back(number_line);
        number_line.clear();
    }

    int center = N/2;

    int x = center;
    int y = center;

    int ans_x, ans_y;

    bool go_r= true, go_d=false, go_l=false, go_u=false;
    bool layer_done=false;
    int layer_stride = 2;
    int layer_move_count = 0;

    number_map[y][x] = 1;
    y--;

    for(int i=2; i<= N*N; i++){

        if(layer_done){
            layer_done = false;
            go_r = true;
            layer_stride += 2;
            i-=1;
        }

        else{
            number_map[y][x] = i;
            if(i==K) {
                ans_x = y + 1; ans_y = x + 1;
            }

            if(go_r){
                if(layer_move_count>=layer_stride-1){
                    go_r = false; go_d = true; layer_move_count = 0;
                }else{
                    x+=1; layer_move_count++;
                }
            }
            if(go_d){
                if(layer_move_count>=layer_stride){
                    go_d = false; go_l = true; layer_move_count = 0;
                }else{
                    y+=1; layer_move_count++;
                }
            }
            if(go_l){
                if(layer_move_count>=layer_stride){
                    go_l = false; go_u = true; layer_move_count = 0;
                }else{
                    x-=1; layer_move_count++;
                }
            }
            if(go_u){
                if(layer_move_count>=layer_stride){
                    go_u = false; layer_done = true; layer_move_count = 0;
                    y--;
                }else{
                    y-=1; layer_move_count++;
                }
            }
        }
    }

    for(const auto& num_line : number_map){
        for(auto n : num_line){
            cout << n << ' ';
        }
        cout << '\n';
    }

    if(K==1){
        ans_x = center + 1; ans_y = center + 1;
    }

    cout << ans_x << ' ' << ans_y;

    return  0;
}