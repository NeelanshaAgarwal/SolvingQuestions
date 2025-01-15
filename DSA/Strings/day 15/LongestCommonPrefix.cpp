#include<bits/stdc++.h>

using namespace std;

// Approch 1

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) {
        return "";
    }

    string ans = "";

    for(int i=0;i<strs[0].size();i++) {
        char c = strs[0][i];
        int match = true;
        for(int j=1;j<strs.size();j++) {
            if(strs[j].size() < i || c != strs[j][i]) {
                match = false;
                break;
            }
        }
        if(!match) {
            break;
        }
        
        ans.push_back(c);
    }
    return ans;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}

// Time Complexity: O(n*m) where n is the number of strings and m is the length of the longest string
// Space Complexity: O(m) where m is the length of the longest string

// Approch 2

/*class TriNode{
    public:
    char data;
    TriNode* children[26];
    int childCount;
    bool isTerminal;

    TriNode(char ch){
        data = ch;
        for(i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
    public:
    TriNode* root;

    Trie(char ch){
        root = new TriNode(ch);
    }

    void insertUtil(TriNode* root, string word){
    if(word.length()==0){
        root->isTerminal = true;
        return;
        }

        int index = word[0]-'a';
        TriNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TriNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void lcp(string str, string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount==1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<int> &arr, int n){
    trie *t = new Trie('\0');

    for(int i=0;i<n;i++){
        t->insertWord(arr[i])
    }

    string frist = arr[0];
    string ans = "";

    t->lcp(frist, ans);
    return ans;
}*/