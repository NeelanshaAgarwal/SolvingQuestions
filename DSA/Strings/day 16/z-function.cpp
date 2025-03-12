// brute force 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack.at(i)==needle.at(0)){
                if(haystack.substr(i,needle.size())==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};

// leetcode problem 28
// optimized solution

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

int main() {
    string  haystack = "sadbutsad", needle = "but";
    Solution obj;
    cout<<obj.strStr(haystack,needle);

    return 0;
}