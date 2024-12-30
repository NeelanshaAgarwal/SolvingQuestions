#include<bits/stdc++.h>

using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(){
        capacity = 1000;
        arr = new int[capacity];
        top = -1;
    }


void push(int x){
    if(top == capacity - 1){
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = x;
}

int pop(){
    if(top == -1){
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return arr[top--];
}

int Top(){
    if(top == -1){
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return arr[top];
}

int size(){
    return top + 1;
}

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    cout << s.Top() << endl;
    cout << s.size() << endl;
    return 0;
}