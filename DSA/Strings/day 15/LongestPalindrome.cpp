#include<bits/stdc++.h>

using namespace std;

// Brute Force Approach

bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
}

string longestPalindrome(string s) {
    int n = s.size();
    int maxLength = 0;
    int startInd = 0 , endInd = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)) {
                if(j-i+1 > maxLength){
                    maxLength = j-i+1;
                    startInd = i;
                    endInd = j;
                }
            }
        }
    }
    return s.substr(startInd,maxLength);  
}

// Optimized Approach



int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}
