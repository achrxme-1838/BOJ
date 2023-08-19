#include <iostream>

using namespace std;

void PrintList(int* list, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d", list[i]);
    }
}

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
    left_list[left_length - 1] = -1;

    for(int i=0; i < right_length - 1; i++){
        right_list[i] = list[mid_idx + 1 + i];
    }
    right_list[right_length - 1] = -1;

    int i = 0;
    int j = 0;
    int k = 0;
    while(k < length)
    {
        if(left_list[i] < right_list[j]) {
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

    int temp = N;

    int decimal = 1;
    while(N>10){
        N = N/10;
        decimal++;
    }

    int list[decimal];
    int i = 0;

    while(temp>10){
        list[i] = temp%10;
        temp = temp/10;
        i++;
    }
    list[decimal-1] = temp;

    Sort(list, 0, decimal-1);
    PrintList(list, decimal);

    return 0;
}