#include<bits/stdc++.h>

using namespace std;

// brute force approch

/*class StockSpanner {
    int arr[100000];
    StockSpanner() {
        arr = {0};
    }

    int next(int val) {
        arr.push_back(val);
        int n = arr.size();
        cnt = 1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=val){
                cnt++;
            }else{
                break;
            }
        }
    return cnt;
    }
};*/

// optimized approch

class StockSpanner {
    stack<pair<int,int>>st;
    int ind = -1;
    StockSpanner() {
        ind = -1;
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int val){
        ind++;
        while(!st.empty() && st.top().first<=val){
            st.pop();
        }
        int ans = ind-(st.empty()?-1:st.top().second);
        st.push({val,ind});
        return ans;
    }
};

int main(){
    StockSpanner obj;
    cout<<obj.next(100)<<endl;
    cout<<obj.next(80)<<endl;
    cout<<obj.next(60)<<endl;
    cout<<obj.next(70)<<endl;
    cout<<obj.next(60)<<endl;
    cout<<obj.next(75)<<endl;
    cout<<obj.next(85)<<endl;
    return 0;
}