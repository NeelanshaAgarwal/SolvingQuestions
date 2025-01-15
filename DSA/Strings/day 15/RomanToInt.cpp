#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    
    unordered_map<char, int> romanMap = {
        {'I', 1}, 
        {'V', 5}, 
        {'X', 10}, 
        {'L', 50}, 
        {'C', 100}, 
        {'D', 500}, 
        {'M', 1000}
    };

    int n = s.size();
    int res = romanMap[s[n-1]];
    for(int i = n-2; i >= 0; i--) {
        if(romanMap[s[i]] < romanMap[s[i+1]]) {
            res -= romanMap[s[i]];
        } 
        else {
            res += romanMap[s[i]];
        }
    }
    return res;
}

int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}