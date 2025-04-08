#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if(n==1) return "1";
            if(n==2) return "11";
            string say = countAndSay(n-1);
            string res = "";
            for(int i=0;i<say.length();i++){
                char ch = say[i];
                int cnt = 1;
                while(i<say.length()-1 && say[i]==say[i+1]){
                    cnt++;
                    i++;
                }
                res+= to_string(cnt) + string(1,ch);
            }
            return res;
        }
    };

int main() {
    Solution sol;
    int n = 5; // Example input
    cout << "The " << n << "th term in the count-and-say sequence is: " << sol.countAndSay(n) << endl;
    return 0;
}
