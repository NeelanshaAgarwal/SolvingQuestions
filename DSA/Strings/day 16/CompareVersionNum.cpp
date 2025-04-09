#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:

    vector<int> splitString(string &s, char delimeter){
        vector<int> ans;
        int start = 0;
        int end = s.find(delimeter,start);
        while(end!=string::npos){ // npos: np position, end of string
            string temp = s.substr(start, end-start);
            ans.push_back(stoi(temp)); // stoi: string to int
            start = end+1;
            end = s.find(delimeter, start);
        }
        string temp = s.substr(start);
        ans.push_back(stoi(temp));
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitString(version1,'.');
        vector<int> v2 = splitString(version2,'.');
        int val1, val2;
        for(int i=0;i<max(v1.size(),v2.size());i++){
            val1 = i<v1.size() ? v1[i]: 0;
            val2 = i<v2.size() ? v2[i]: 0;
            if(val1<val2) return -1;
            else if(val1>val2) return 1;
        }
        return 0;
    }
};
*/

/*
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        istringstream iss1(version1), iss2(version2); // istringstream: input string stream 

        string token;

        while(getline(iss1,token,'.')) v1.push_back(stoi(token)); // getline: get line from string stream, push into vector
        while(getline(iss2,token,'.')) v2.push_back(stoi(token));
        
        int val1,val2;
        for(int i=0;i<max(v1.size(),v2.size());i++){
            val1 = i<v1.size()?v1[i]:0;
            val2 = i<v2.size()?v2[i]:0;

            if(val1<val2) return -1;
            else if(val1>val2) return 1;
        }
        return 0;
    }
};
*/

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int n1 = version1.size(), n2 = version2.size();
            int i=0,j=0;
            while(i<n1||j<n2){
                int val1=0 , val2=0;
                while(i<n1 && version1[i]!='.'){
                    val1 = val1*10 + (version1[i]-'0'); // '0' is subtracted to convert char to int
                    i++;
                }
                i++;
                while(j<n2 && version2[j]!='.'){
                    val2 = val2*10 + (version2[j]-'0');
                    j++;
                }
                j++;
    
                if(val1<val2) return -1;
                else if(val1>val2) return 1;
            }
            return 0;
        }
    };

int main() {
    Solution sol;
    string version1 = "1.01";
    string version2 = "1.001";
    int result = sol.compareVersion(version1, version2);
    cout << "Comparison result: " << result << endl; // Output: 0
    return 0;
}