#include <iostream>

using namespace std;

void MaxHeapify(int A[], int heap_size, int i)
{
    int left = 2*i;
    int right = 2*i + 1;

    int largest;
    if(left<=heap_size and A[left] > A[i]) largest = left;
    else largest = i;

    if(right<=heap_size and A[right]>A[largest]) largest = right;

    if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, heap_size,largest);
    }
}

void BuildMaxHeap(int A[], int heap_size){
    for(int i=heap_size/2; i>=1; i--){
        MaxHeapify(A, heap_size, i);
    }

}

void HeapIncreaseKey(int A[], int i, int key){
    A[i] = key;
    while(i > 1 and A[i/2] < A[i]){
        int temp = A[i];
        A[i] = A[i/2];
        A[i/2] = temp;
        i = i/2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;

    int A[100001];
    A[0] = -1;

    int heap_size = 0;
    for(int n=0; n<N; n++){
        int in; cin >> in;
        if(in==0) {
            if(heap_size==0) cout << 0 << '\n';
            else{
                cout << A[1] << '\n';
                A[1] = A[heap_size--];
                MaxHeapify(A, heap_size, 1);
            }
        }
        else {
            A[++heap_size] = -1;
            HeapIncreaseKey(A, heap_size, in);
        }
    }

    return 0;
}
