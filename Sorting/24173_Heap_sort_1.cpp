#include <iostream>
#include <vector>

using namespace std;

long long int swap_count = 0;
long long int K;
bool end_flag = false;

void swap(long long int& a, long long int& b){
    long long int temp = a;
    a = b;
    b= temp;

    swap_count++;

    if(swap_count == K) {
        if(b > a) cout << a << " " << b;
        else      cout << b << " " << a;
        end_flag = true;
    }

}

void heapify(std::vector<long long int>& A, int k, int n){
    int left = 2*k;
    int right = 2*k + 1;
    int smaller;

    if(right <= n){
        if(A[left] < A[right]) smaller = left;
        else                   smaller = right;
    }
    else if(left <= n){ // because of else -> right > n (out of range) here
        smaller = left;
    }
    else return;

    if(A[smaller] < A[k]){
        swap(A[k], A[smaller]);
        heapify(A, smaller, n);
    }
}

void build_min_heap(std::vector<long long int>& A, int n){
    for(int i=n/2; i>=1; i--){
        heapify(A, i, n);
    }
}

void heap_sort(std::vector<long long int>& A, int n){
    build_min_heap(A, n);
    for(int i=n; i>=2; i--){
        swap(A[1], A[i]);
        heapify(A, 1, i-1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N >> K;
    std::vector<long long int> A;

    A.push_back(0);
    long long int input=0;
    for(int i=0; i<N; i++){
        cin >> input;
        A.push_back(input);
    }

    heap_sort(A, N);

    if(!end_flag) cout << -1;

    return 0;
}
