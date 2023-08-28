#include <iostream>
#include <vector>

using namespace std;

void rotate(std::vector<std::vector<int>>& arr, int size, bool direction){

    std::vector<std::vector<int>> copy_arr = arr;
    int center = size/2;

    // [y][x]
    if(direction) {
        for (int stride = 1; stride <= size / 2; stride++) {
            copy_arr[center - stride][center]           = arr[center - stride][center - stride];
            copy_arr[center - stride][center + stride]  = arr[center - stride][center];
            copy_arr[center][center + stride]           = arr[center - stride][center + stride];
            copy_arr[center + stride][center + stride]  = arr[center][center + stride];
            copy_arr[center + stride][center]           = arr[center + stride][center + stride];
            copy_arr[center + stride][center - stride]  = arr[center + stride][center];
            copy_arr[center][center - stride]           = arr[center + stride][center - stride];
            copy_arr[center - stride][center - stride]  = arr[center][center - stride];
        }
    } else{
        for (int stride = 1; stride <= size / 2; stride++) {
            copy_arr[center - stride][center]           = arr[center - stride][center + stride];
            copy_arr[center - stride][center + stride]  = arr[center][center + stride];
            copy_arr[center][center + stride]           = arr[center + stride][center + stride];
            copy_arr[center + stride][center + stride]  = arr[center + stride][center];
            copy_arr[center + stride][center]           = arr[center + stride][center - stride];
            copy_arr[center + stride][center - stride]  = arr[center][center - stride];
            copy_arr[center][center - stride]           = arr[center - stride][center - stride];
            copy_arr[center - stride][center - stride]  = arr[center - stride][center];
        }
    }

    arr = copy_arr;

}

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int K;
    cin >> K;

    std::vector<std::vector<std::vector<int>>> arr_vec;
    std::vector<std::vector<int>> arr;
    std::vector<int> line;

    std::vector<int> n_vec;
    std::vector<int> d_vec;

    for(int k=0; k<K; k++) {
        int n, d;
        cin >> n >> d;
        n_vec.push_back(n);
        d_vec.push_back(d);

        int input;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> input;
                line.push_back(input);
            }
            arr.push_back(line);
            line.clear();
        }
        arr_vec.push_back(arr);
        arr.clear();
    }

    for(int k=0; k<K; k++) {
        int rotate_num = d_vec[k] / 45;

        if (rotate_num > 0) {
            for (int i = 0; i < rotate_num; i++) {
                rotate(arr_vec[k], n_vec[k], true);
            }
        } else {
            for (int i = 0; i > rotate_num; i--)
                rotate(arr_vec[k], n_vec[k], false);
        }

        for (auto l: arr_vec[k]) {
            for (auto c: l) {
                cout << c << ' ';
            }
            cout << '\n';
        }

    }

}
