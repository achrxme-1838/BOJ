#include <iostream>
#include <stdio.h>

using namespace std;

void PrintList(int* list, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d\n", list[i]);
    }
}

void Swap(int list[], int i, int j)
{
    int temp = list[j];
    list[j] = list[i];
    list[i] = temp;
}

int Partition(int list[], int left, int right)
{
    int pivot;
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


void Sort(int list[], int left, int right)
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

    int list[N];

    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    Sort(list, 0, N-1);
    PrintList(list, N);

    return 0;
}