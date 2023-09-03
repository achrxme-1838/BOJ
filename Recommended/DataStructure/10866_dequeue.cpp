#include <iostream>

using namespace std;

class Deque{
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Deque(int size)
        : capacity(size), front(0), rear(0), count(0)
    {
        arr = new int[size];
    }
    ~Deque(){
        delete[] arr;
    }

    int size(){
        return count;
    }
    bool isEmpty(){
        return (size()==0);
    }
    bool isFull(){
        return (size()==capacity);
    }
    void addFront(int n){
        if(isFull()) {
            return;
        }
        arr[front] = n;
        front = (front-1+capacity) % capacity;
        count++;
    }
    void addRear(int n){
        if(isFull()) {
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = n;
        count++;
    }
    int deleteFront(){
        if(isEmpty()){
            return -1;
        }
        front = (front+1)%capacity;
        count--;
        return arr[front];
    }
    int deleteRear(){
        if(isEmpty()){
            return -1;
        }
        int tmp = arr[rear];
        rear = (rear-1+capacity)%capacity;
        count--;
        return tmp;
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[(front+1)%capacity];
    }
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    Deque deque(10000);
    for(int i=0; i<N; i++){
        string order; cin >> order;
        if(order == "push_front"){
            int num; cin >> num;
            deque.addFront(num);
        }
        else if(order == "push_back"){
            int num; cin >> num;
            deque.addRear(num);
        }
        else if(order == "front"){
            cout << deque.getFront() << '\n';
        }
        else if(order == "back"){
            cout << deque.getRear() << '\n';
        }
        else if(order == "size"){
            cout << deque.size() << '\n';
        }
        else if(order == "empty"){
            cout << deque.isEmpty() << '\n';
        }
        else if(order == "pop_front"){
            cout << deque.deleteFront()<< '\n';
        }
        else if(order == "pop_back"){
            cout << deque.deleteRear()<< '\n';
        }
    }


}