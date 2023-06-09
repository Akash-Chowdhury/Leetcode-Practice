//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
    string word = "";
    string ans = "";
    int i = s.length() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == '.') {
            i--;
        }
        if (i < 0) {
            break;
        }
        if (!ans.empty()) {
            ans.push_back('.');
        }
        word = "";
        while (i >= 0 && s[i] != '.') {
            word += s[i];
            i--;
        }
        reverse(word.begin(), word.end());
        ans += word;
    }
    return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends