#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Stack{
private:
    int top_idx, maxSize;
    T* stack;

public:
    Stack(int max_size)
        :maxSize(max_size), top_idx(-1)
    {
        stack = new T[maxSize];
    }

    bool isFull(){
        if(top_idx==maxSize-1) return true;
        else return false;
    }
    bool isEmpty(){
        if(top_idx==-1) return true;
        else return false;
    }
    T pop(){
        if(isEmpty()) return -1;
        else return stack[top_idx--];
    }
    void push(int element){
        if(isFull()) cout << "Full!\n";
        else stack[++top_idx] = element;
    }
    void top(){
        if(isEmpty()) cout << -1 << '\n';
        else cout << stack[top_idx] << '\n';
    }
    void size(){
        cout << top_idx + 1 << '\n';
    }

    ~Stack(){
        delete[] stack;
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    Stack<int> stack(10000);
    for(int i=0; i<N; i++){
        string order; cin >> order;
        if(order == "push"){
            int num; cin >> num;
            stack.push(num);
        }
        else if(order == "top"){
            stack.top();
        }
        else if(order == "size"){
            stack.size();
        }
        else if(order == "empty"){
            cout << stack.isEmpty() << '\n';
        }
        else if(order == "pop"){
            cout << stack.pop() << '\n';
        }
    }

    return 0;
}
