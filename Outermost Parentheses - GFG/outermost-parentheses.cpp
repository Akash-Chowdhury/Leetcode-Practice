//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            char a = st.top();
            if (a == '(' && s[i] == ')') {
                st.pop();
                if (!st.empty()) {
                    ans += s[i];
                }
            } else {
                st.push(s[i]);
                if (st.size() > 1) {
                    ans += s[i];
                }
            }
        }
    }

    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends