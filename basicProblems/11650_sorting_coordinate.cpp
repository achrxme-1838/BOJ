#include <iostream>

using namespace std;

void PrintArray(int list[][2], int length)
{
    for(int i=0; i<length; i++){
        cout << list[i][0] << " " << list[i][1] << endl;
    }
    cout << endl;
}

void Merge(int list[][2], int left_idx, int mid_idx, int right_idx)
{
    int length = right_idx - left_idx + 1;
    int left_length = mid_idx - left_idx + 1 + 1; // +1 for joker
    int right_length = right_idx - mid_idx + 1;   // +1 for joker

    int left_list[left_length][2];
    int right_list[right_length][2];

    for(int i=0; i < left_length - 1; i++){
        left_list[i][0] = list[left_idx + i][0];
        left_list[i][1] = list[left_idx + i][1];
    }
    left_list[left_length - 1][0] = 1000000;
    left_list[left_length - 1][1] = 1000000;

    for(int i=0; i < right_length - 1; i++){
        right_list[i][0] = list[mid_idx + 1 + i][0];
        right_list[i][1] = list[mid_idx + 1 + i][1];
    }
    right_list[right_length - 1][0] = 1000000;
    right_list[right_length - 1][1] = 1000000;

    int i = 0;
    int j = 0;
    int k = 0;
    while(k < length)
    {
        if(left_list[i][0] > right_list[j][0]) {
            list[left_idx + k][0] = right_list[j][0];
            list[left_idx + k][1] = right_list[j][1];
            j += 1;
            k += 1;
        }
        else if(left_list[i][0] == right_list[j][0]
                and left_list[i][1] > right_list[i][1]){
            list[left_idx + k][0] = right_list[j][0];
            list[left_idx + k][1] = right_list[j][1];
            j += 1;
            k += 1;
        }
        else{
            list[left_idx + k][0] = left_list[i][0];
            list[left_idx + k][1] = left_list[i][1];
            i += 1;
            k += 1;
        }
    }
}

void Sort(int list[][2], int left_idx, int right_idx)
{
    if(right_idx - left_idx<= 0) {
        return;
    }

    int mid_idx = (left_idx + right_idx) / 2;

    Sort(list, left_idx, mid_idx);
    Sort(list, mid_idx+1, right_idx);
    Merge(list, left_idx, mid_idx, right_idx);
}


int main()
{
    int N;
    cin >> N;

    int list[N][2];

    for(int i=0; i<N; i++){
        cin >> list[i][0] >> list[i][1];
    }
    PrintArray(list, N);

    Sort(list, 0, N-1);
    PrintArray(list, N);

    return 0;
}