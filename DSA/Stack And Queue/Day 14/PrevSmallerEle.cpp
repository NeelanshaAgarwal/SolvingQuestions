#include<bits/stdtr1c++.h>

using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<A.size();i++){
        while(!s.empty() && s.top()>=A[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]  = s.top();
        }
        s.push(A[i]);
    }
    return ans;
}

int main(){
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> ans = prevSmaller(A);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}