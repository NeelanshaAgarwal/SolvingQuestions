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

// leetcode problem 28

/*class Solution {
    public:
        int strStr(string haystack, string needle) {
            string s = needle + '#' + haystack;
            int n = s.size(), n1 = needle.size(), n2=haystack.size() ;
            int i=0,j=-1,kmp[n+1],pos=-1;
            kmp[0]=-1;
            while(i<n){
                while(j!=-1 && s[i]!=s[j]){
                    j = kmp[j];
                }
                j++;i++;
                kmp[i]=j;
                if(kmp[i]==n1){
                    pos = i-2*n1-1;
                    break;
                }
            }
            return pos;
        }
    };*/