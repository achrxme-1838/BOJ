#include <iostream>

using namespace std;

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
    int list[5];

    for(int i=0; i<5; i++){
        cin >> list[i];
    }

    Sort(list, 5);

    int sum = 0;
    for(int i=0; i<5; i++){
        sum+=list[i];
    }

    cout << sum/5 << endl << list[2];


    return 0;
}