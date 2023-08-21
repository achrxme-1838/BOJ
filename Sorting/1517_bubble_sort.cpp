#include <iostream>

using namespace std;

// left_idx = p, mid_idx = q, right_idx = r
long long int count = 0;

void Merge(long long int list[], int left_idx, int mid_idx, int right_idx)
{
    int i = left_idx;
    int j = mid_idx + 1;
    int t = 0;

    long long int temp[right_idx - left_idx + 1];

    while(i <= mid_idx and j <= right_idx){
        if(list[i] <= list[j]){
            temp[t] = list[i];
            t++;
            i++;
        }
        else{
            temp[t] = list[j];
            count += mid_idx - i + 1;
            t++;
            j++;
        }
    }
    while(i <= mid_idx){
        temp[t] = list[i];
        t++;
        i++;
    }
    while(j <= right_idx){
        temp[t] = list[j];
        t++;
        j++;
    }

    i = left_idx;
    t = 0;
    while(i <= right_idx) {
        list[i] = temp[t];
        i++;
        t++;
    }
}

void Sort(long long int list[], int left_idx, int right_idx)
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
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    int long long list[N];

    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    Sort(list, 0, N-1);
    cout << count;

    return 0;
}