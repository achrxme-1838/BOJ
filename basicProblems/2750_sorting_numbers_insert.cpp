#include <iostream>

using namespace std;

void PrintArray(int* list, int length)
{
    for(int i=0; i<length; i++){
        cout << list[i] << endl;
    }
    cout << endl;
}

void Sort(int list[], int length) {

    int key;

    for (int i = 1; i < length; i++) {
        key = list[i];

        for (int j = i - 1; j >= 0; j--) {
            if (key < list[j]) {
                list[j + 1] = list[j];
                list[j] = key;
            }
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