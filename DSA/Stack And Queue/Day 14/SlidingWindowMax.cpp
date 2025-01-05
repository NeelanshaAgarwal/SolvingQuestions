#include<bits/stdc++.h>

using namespace std;

// brute force approch

/*void getMax(vector<int> nums,int l,int r,vector<int> &arr){
    int i, maxi = INT_MIN;
    for(i=l;i<=r;i++){
        maxi = max(maxi,nums[i]);
    }
    arr.push_back(maxi);
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int i,j;
    vector<int> arr;
    while(r<k-1){
        r++;
    }
    while(r<nums.size()){
        getMax(nums,l,r,arr);
        l++;
        r++;
    }

    return arr;
}*/

// optimized approch

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

