#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int CurrSize;
    int MaxSize;
    public:
    Queue(){
        arr = new int[16];
        front = -1;
        rear = -1;
        CurrSize = 0;
    }
    Queue(int MaxSize){
        this->MaxSize = MaxSize;
        arr = new int[MaxSize];
        front = -1;
        rear = -1;
        CurrSize = 0;
    }
    void push(int data){
        if(CurrSize == MaxSize){
            cout<<"Queue is Full"<<endl;
            exit(1);
        }
        if(rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear+1)%MaxSize;
        }
        arr[rear] = data;
        cout<<"Pushed "<<data<<endl;
        CurrSize++;
    }
    int pop(){
        if(front == -1){
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        int popped = arr[front];
        if(CurrSize == 1){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%MaxSize;
        }
        CurrSize--;
        return popped;
    }
    int peek(){
        if(front == -1){
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        return arr[front];
    }
    int size(){
        return CurrSize;
    }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"Size of Queue: "<<q.size()<<endl;
    cout<<"Popped: "<<q.pop()<<endl;
    cout<<"Popped: "<<q.pop()<<endl;
    cout<<"Popped: "<<q.pop()<<endl;
    cout<<"Size of Queue: "<<q.size()<<endl;
    cout<<"Peek: "<<q.peek()<<endl;
    return 0;
}