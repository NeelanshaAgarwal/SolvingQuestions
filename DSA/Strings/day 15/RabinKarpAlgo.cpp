#include<bits/stdc++.h>

using namespace std;

// Brute force

/*int findSubString(string s , string ss){
    int sSize = s.size();
    int ssSize = ss.size();
    for(int i = 0; i <= sSize - ssSize; i++){
        int j;
        for(j = 0; j < ssSize; j++){
            if(s[i+j] != ss[j]){
                break;
            }
        }
        if(j == ssSize){
            return i;
        }
    }
    return -1;
}

int main() {
    string s = "ababcabdab";
    string ss = "bdab";
    cout<<findSubString(s,ss);
    return 0;
}*/

// Rabin karp algo

#define d 256 // Number of characters in the input alphabet

void rabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();
    int i,j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // Compute the value of h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    if (m > n || m == 0) {
        cout << "Pattern cannot be larger than text or be empty!" << endl;
        return;
    }

    // Calculate initial hash values for pattern and first window
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
        // If the hash values of the current window and the pattern match, compare the characters
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            // If the pattern is found
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Handle negative hash values
            if (t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    string text = "abcdabcabcd";
    string pattern = "abc";
    int q = 101; // Prime number for modulo
    rabinKarp(text, pattern, q);
    return 0;
}


// leetcode problem 686 solution

/*
class Solution {
private:
    const int base = 1000000;
    const int d = 31;
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int count = 1;
        string source = a;

        while(source.size()<b.size()){
            count++;
            source+=a;
        }
        if(source == b) return count;
        if(Rabin_Karp(source, b) != -1) return count;
        if(Rabin_Karp(source + a, b) != -1) return count + 1;
        return -1;
    }

    int Rabin_Karp(string source, string target) {
        if(source.empty()||target.empty()) return -1;
        int n = source.size();
        int m = target.size();
        int s = 0, t = 0, h = 1;
        for(int i=0;i<m;i++){
            h=(h*d)%base;
        }
        for(int i=0;i<m;i++){
            t = (d*t+target[i])%base;
        }
        for(int i=0;i<n;i++){
            s = (d*s+source[i])%base;
            if(i<m-1) continue;
            if(i>=m){
                s = (s-source[i-m]*h)%base;
            }
            if(s<0)
                s+=base;
            if(s == t){
                if(source.substr(i-m+1,m) == target) return i-m+1;
            }
        }
        return -1;
    }
};
*/