#include <iostream>
#include <string>

using namespace std;

class Queue
{
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size)
        : capacity(size), front(0), rear(-1), count(0)
    {
        arr = new int[size];
    }
    ~Queue(){
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
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity; // % capacity : implementation of rotational queue
                                        // <- not to move every element to front when dequeue
        count--;

        return x;
    }

    void enqueue(int item){
        if(isFull()){
            cout << -1 << '\n';
        }
        rear = (rear+1) % capacity;
        arr[rear] = item;
        count ++;
    }

    int front_queue(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int back_queue(){
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

    Queue queue(10000);
    for(int i=0; i<N; i++){
        string order; cin >> order;
        if(order == "push"){
            int num; cin >> num;
            queue.enqueue(num);
        }
        else if(order == "front"){
            cout << queue.front_queue() << '\n';
        }
        else if(order == "back"){
            cout << queue.back_queue() << '\n';
        }
        else if(order == "size"){
            cout << queue.size() << '\n';
        }
        else if(order == "empty"){
            cout << queue.isEmpty() << '\n';
        }
        else if(order == "pop"){
            cout << queue.dequeue()<< '\n';
        }
    }


    return 0;
}
