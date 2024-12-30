#include<bits/stdc++.h>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int data){
        cout<<"Pushed "<<data<<endl;
        s1.push(data);
        /*while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        cout<<"Pushed "<<data<<endl;
        s1.push(data);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }*/
    }

    int pop(){

        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;

        /*if(s1.empty()){
            cout<<"Queue is Empty"<<endl;
            exit(0);
        }
        int val = s1.top();
        s1.pop();
        return val;*/
    }

    int peek(){

        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();
        }

        /*if(s1.empty()){
            cout<<"Queue is Empty"<<endl;
            exit(0);
        }
        return s1.top();*/
    }

    int size(){

        return s1.size() + s2.size();
        /*return s1.size();*/
    }

    int empty(){
        return s1.empty() && s2.empty();
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;
    return 0;
}