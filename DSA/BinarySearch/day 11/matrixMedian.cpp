#include<bits/stdc++.h>
using namespace std;

/*int median(vector<vector<int>> &matrix,int m, int n){
    vector<int>lst;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            lst.push_back(matrix[i][j]);
        }
    }
    sort(lst.begin(),lst.end());
    return lst[(m*n)/2];
}*/

int upperBound(vector<int> &arr,int x,int n){
    int low = 0 , high = n-1;
    int ans = n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>>&matrix,int m,int n,int x){
    int cnt = 0;
    for(int i=0;i<m;i++){
        cnt+=upperBound(matrix[i],x,n)
    }
    return cnt;
}

int median(vector<vector<int>>&matrix,int m,int n){
    int low=INT_MAX, high-INT_MIN;
    for(int i=0;i<m;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][n-1]);
    }
    int req = (n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smallequal = countSmallEqual(matrix,m,n,mid);
        if(smallequal<=req){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(),n = matrix[0].size();
    int ans = median(matrix,m,n);
    cout << "The median element is: " << ans << endl;
    return 0;
}