#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:

    void sortedInsert(stack < int > & s, int x) {
        if (s.empty() || x > s.top()) {
            s.push(x);
            return;
        }
        int temp = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }

    void sortStack(stack < int > & s) {

        if(stak.empty()){
            return;
        }

        int temp = stak.top();
        stak.pop();
        sortStack(stak);
        sortedInsert(stak, temp);

      /*stack < int > temp;
      while (!s.empty()) {
        int x = s.top();
        s.pop();
        while (!temp.empty() && temp.top() > x) {
          s.push(temp.top());
          temp.pop();
        }
        temp.push(x);
      }
      while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
      }*/
    }
};

int main() {
  Solution obj;
  stack < int > s;
  s.push(30);
  s.push(-5);
  s.push(18);
  s.push(14);
  s.push(-3);

  obj.sortStack(s);

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

