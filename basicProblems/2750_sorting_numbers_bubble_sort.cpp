#include <iostream>

using namespace std;

void PrintArray(int* list, int length)
{
    for(int i=0; i<length; i++){
        cout << list[i] << endl;
    }
    cout << endl;
}

void Swap(int list[], int a, int b)
{
    int c = list[b];
    list[b] = list[a];
    list[a] = c;
}

void Sort(int list[], int length) {

    for(int i=length-1; i>=0; i--){
        for(int j = 0; j<i; j++){
            if(list[j] > list[j + 1]) Swap(list, j, j+1);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int list[N];

    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    Sort(list, N);
    PrintArray(list, N);

    return 0;
}