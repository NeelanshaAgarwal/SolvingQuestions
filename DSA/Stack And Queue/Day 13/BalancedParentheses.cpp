#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(auto it: s){
        if(it == '(' || it == '{' || it == '['){
            st.push(it);
        }
        else{
            if(st.empty()){
                return false;
            }
            char ch = st.top();
            st.pop();
            if(it == ')' && ch == '(' || it == '}' && ch == '{' || it == ']' && ch == '['){
                continue;
            }
            else{
                return false;
            }
        }
        return st.empty(); 
    }
}

int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}