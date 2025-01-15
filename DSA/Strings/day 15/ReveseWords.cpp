#include<bits/stdc++.h>

using namespace std;

// Brute Force Approach

/*int main() {
    string s = "I Love Coding";
    cout<<"Before Reversing: "<<endl;
    cout<<s<<endl;
    s+=" ";
    stack<string> st;
    int i;
    string word = "";
    for(i=0;i<s.length();i++) {
        if(s[i]==' ') {
            st.push(word);
            word = "";
        } else {
            word+=s[i];
        }
    }

    string ans = "";
    while(!st.empty()) {
        ans+=st.top()+" ";
        st.pop();
    }

    ans+=st.top();
    cout<<"After Reversing: "<<endl;
    cout<<ans<<endl;
    return 0;
}*/

// Optimized Approach

string reverseWords(string s) {
    left = 0;
    right = s.size()-1;

    string temp = "";
    string ans = "";

    while(left<=right) {
        char ch = s[left];
        if(ch!=' ') {
            temp+=ch;
        } 
        else if(ch==' ' )
        { 
            if(ans!="") ans = temp+" "+ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }

    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }

    return ans;
}

in main() {
    string s = "I Love Coding";
    cout<<"Before Reversing: "<<endl;
    cout<<s<<endl;
    cout<<"After Reversing: "<<endl;
    cout<<reverseWords(s)<<endl;
    return 0;
}
