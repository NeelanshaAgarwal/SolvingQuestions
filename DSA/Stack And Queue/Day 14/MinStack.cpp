#include<bits/stdc++.h>

using namespace std;


// brute force approch

/*class MinStack {
    stack<pair<int,int>>st;
    public:
    void push(int x) {
        if(st.empty()){
            st.push({x,x});
        }else{
            st.push({x,min(x,st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};*/

// optimized approch

class MinStack {
    stack<long long>st;
    long long minEle;
    public:
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        minEle = INT_MAX;
    }

    void push(int value) {
        long long val = static_cast<long long>(value);
        if(st.empty()){
            st.push(val);
            minEle = val;
        }else if(val<minEle){
            st.push(2*val*1LL-minEle);
            minEle = val;
        }else{
            st.push(val);
        }
    }

    void pop() {
        if(st.empty()){
            return;
        }
        long long el = st.top();
        st.pop();

        if(el<minEle){
            minEle = 2*minEle-el;
        }
    }

    int top() {
        if(st.empty()){
            return -1;
        }
        long long el = st.top();
        if(el<minEle){
            return minEle;
        }
        return el;
    }

    int getMin() {
        if(st.empty()){
            return -1;
        }
        return minEle;
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->top()<<endl;
    cout<<obj->getMin()<<endl;
    return 0;
}