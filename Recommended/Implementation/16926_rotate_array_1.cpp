#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    std::vector<std::vector<int>> arr;
    std::vector<int> line;
    int input;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> input;
            line.push_back(input);
        }
        arr.push_back(line);
        line.clear();
    }

    int shorter = N;
    if(M < N) shorter = M;
    int num_of_layer = shorter/2;

    for(int r=0; r<R; r++) {
        for (int i = 0; i < num_of_layer; i++) {
            int x_width = M - i * 2;
            int y_width = N - i * 2;

            int temp = arr[N - 1 - i][i];

            // down
            for (int j = 0; j < y_width - 1; j++) {
                arr[N - 1 - i - j][i] = arr[N - 1 - i - j - 1][i];
            }
            //left
            for (int j = 0; j < x_width - 1; j++) {
                arr[i][i + j] = arr[i][i + j + 1];
            }
            //up
            for (int j = 0; j < y_width - 1; j++) {
                arr[i + j][M - 1 - i] = arr[i + j + 1][M - 1 - i];
            }
            //right
            for (int j = 0; j < x_width - 2; j++) {
                arr[N - 1 - i][M - 1 - i - j] = arr[N - 1 - i][M - 1 - i - j - 1];
            }

            arr[N - 1 - i][i + 1] = temp;
        }
    }

    for(auto l : arr){
        for(auto a : l){
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}