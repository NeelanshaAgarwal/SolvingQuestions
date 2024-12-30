#include<bits/stdc++.h>

using namespace std;

class Stack{
    queue<int> q;
    public:
    void push(int data){
        int s = q.size();
        q.push(data);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int n = q.front();
        q.pop();
        return n;
    }
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    return 0;
}