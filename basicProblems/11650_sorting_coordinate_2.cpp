#include <iostream>

using namespace std;


void Swap(long list[], int i, int j)
{
    long temp = list[j];
    list[j] = list[i];
    list[i] = temp;
}

int Partition(long list[], int left, int right)
{
    long pivot;
    int low, high;

    low = left+1;
    high = right;
    pivot = list[left];

    while(true)
    {
        if(list[low] < pivot) low++;
        if(list[high] > pivot) high--;

        if(low > high) break;

        if(list[high] <= pivot and list[low] >= pivot){
            Swap(list, low, high);
        }
    }

    Swap(list, left, high);
    return high;
}


void Sort(long list[], int left, int right)
{
    if(left < right){
        int q = Partition(list, left, right);

        Sort(list, left, q-1);
        Sort(list, q+1, right);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);

    long max_num = 100000;
    long min_num = -100000;

    long range = max_num - min_num;

    int input_x;
    int input_y;

    long list[N];

    for(int i=0; i<N; i++){
        scanf("%d", &input_x);
        scanf("%d", &input_y);
        list[i] = (input_x - min_num) * range + (input_y - min_num);
    }

    Sort(list, 0, N-1);

    for(int i=0; i<N; i++){
        printf("%ld %ld\n", (list[i] / range + min_num),
                        (list[i] % range + min_num));
    }

    return 0;
}