#include<bits/stdc++.h>

using namespace std;

// brute force approch

/*int largestRectangleArea(int arr[],int n){
    int maxArea = 0 ;
    for(int i=0;i<n;i++){
        int minHeight = INT_MAX;
        for(int j=i;j<n;j++){
            minHeight = min(minHeight,arr[j]);
            maxArea = max(maxArea,minHeight*(j-i+1));
        }
    }
    return maxArea;
}*/

// optimized approch 1

/*class Solution {
    public:
    int largestRectangleArea(vector<int>&height){
        int n = height.size();
        stack<int>st;
        int left[n],right[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            }else{
                left[i] = st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-1;
            }else{
                right[i] = st.top()-1;
            }
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,height[i]*(right[i]-left[i]+1));
        }
        return maxArea;
    }
};*/


// optimized approch 2

class Solution {
    public:
    int largestRectangleArea(vector<int>&histo){
        int n = histo.size();
        stack<int>st;
        int maxArea = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width = st.empty()?i:i-st.top()-1;
                maxArea = max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.largestRectangleArea(arr,n);
}