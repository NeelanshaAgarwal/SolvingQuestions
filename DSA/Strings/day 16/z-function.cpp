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

int main() {
    string  haystack = "sadbutsad", needle = "but";
    Solution obj;
    cout<<obj.strStr(haystack,needle);

    return 0;
}