#include<bits/stdc++.h>

using namespace std;

//kmp algorithm

vector<int> kmp(string s){
    vector<int> lps(s.size(),0);

    for(int i=1;i<lps.size();i++){
        int prevInd = lps[i-1];
        while(prevInd>0 && s[i]!=s[prevInd]){
            prevInd = lps[prevInd-1];
    }
    lps[i] = prevInd + (s[i]==s[prevInd]?1:0);
    }
    return lps;
}

int main(){
    string s;
    cin>>s;
    vector<int> lps = kmp(s);
    for(int i=0;i<lps.size();i++){
        cout<<lps[i]<<" ";
    }
    return 0;
}

