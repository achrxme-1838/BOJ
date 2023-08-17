#include <iostream>

using namespace std;

void Merge(int list[], int left_idx, int mid_idx, int right_idx)
{
    int length = right_idx - left_idx + 1;
    int left_length = mid_idx - left_idx + 1 + 1; // +1 for joker
    int right_length = right_idx - mid_idx + 1;   // +1 for joker

    int left_list[left_length];
    int right_list[right_length];

    for(int i=0; i < left_length - 1; i++){
        left_list[i] = list[left_idx + i];
    }
    left_list[left_length - 1] = 1000000;

    for(int i=0; i < right_length - 1; i++){
        right_list[i] = list[mid_idx + 1 + i];
    }
    right_list[right_length - 1] = 1000000;

    int i = 0;
    int j = 0;
    int k = 0;
    while(k < length)
    {
        if(left_list[i] > right_list[j]) {
            list[left_idx + k] = right_list[j];
            j += 1;
            k += 1;
        }
        else{
            list[left_idx + k] = left_list[i];
            i += 1;
            k += 1;
        }
    }
}

void Sort(int list[], int left_idx, int right_idx)
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

    int list[N];

    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    Sort(list, 0, N-1);

    for(int i=0; i<N; i++){
        cout << list[i] << endl;
    }

    return 0;
}