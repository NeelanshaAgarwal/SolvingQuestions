#include<bits/stdc++.h>
using namespace std;

int MiniChar(string s){
    string rev = s;
    reverse(rev.begin(),rev.end());
    int n = rev.size();
    if(rev==s){
        return 0;
    }
    vector<int> lps(n,0);
    for(int i=1;i<n;i++){
        int prevInd = lps[i-1];
        while(prevInd>0 && rev[i]!=rev[prevInd]){
            prevInd = lps[prevInd-1];
        }
        if(rev[i]==s[prevInd]){
            prevInd++;
        }
        lps[i] = prevInd;
    }
    return n-lps[n-1];
}

int main(){
    string s;
    cin>>s;
    cout<<MiniChar(s);
    return 0;
}