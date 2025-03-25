#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areAnagrams(string str1, string str2) {
    // Function to check if two strings are anagrams
    if(str1.size() != str2.size()) return false;
    unordered_map<char, int> mpp;
    for(int i = 0; i < str1.size(); i++) {
        mpp[s[i]]++;
        mpp[t[i]]--;
    }
    for(auto it : mpp) {
        if(it.second != 0) return false;
    }
    return true; // Placeholder return statement
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}