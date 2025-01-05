#include <bits/stdc++.h> 

using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n,INT_MIN);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&a[st.top()]>a[i]){
        int ind = st.top();
        st.pop();
        if(!st.empty()){
            int range = i-st.top()-1;
            ans[range-1] = max(ans[range-1],a[ind]);
        }
        else{
            int range = i;
            ans[range-1]=max(ans[range-1],a[ind]);
        }
    }
    st.push(i);
    }
    while(!st.empty()){
        int index = st.top();
        st.pop();
        if(!st.empty()){
            int range = n-st.top()-1;
            ans[range-1] = max(ans[range-1],a[index]);
        }
        else{
                int range = n;
                ans[range-1] = max(ans[range-1],a[index]);
        }
    }
    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i],ans[i+1]);
    }
    return ans;
}

int main(){
    vector<int>a = {10,20,30,50,10,70,30};
    vector<int>ans = maxMinWindow(a,a.size());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}