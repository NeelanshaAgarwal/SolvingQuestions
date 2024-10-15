#include<bits/stdc++.h>
using namespace std;

/*int multiply(double num,int n){
    double ans = 1.0;
    for(int i=0;i<=n;i++){
        ans=ans*num;
    }
    return ans;
}

double getNthRoot(int n,int m){
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while((high-low)>eps){
        double mid  = (low+hight)/2.0;
        if(multiply(mid,n)<m){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<low<<" "<<high<<endl;
}*/

/*
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m) {
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = func(i, n);
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}
*/

int func(int mid,int n,int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>mid) return 2;
    }
    if(ans == mid) return 1;
    return 0;
}

int getNthRoot(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid = (low+high)/2;
        int midN = func(mid,n,m);
        if(midN==1){
            return mid;
        }
        else if(midN == 0){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int ans = getNthRoot(n,m);
    cout<<ans;
    return 0;
}