


#include <bits/stdc++.h>
using namespace std;

/*bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}*/

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
