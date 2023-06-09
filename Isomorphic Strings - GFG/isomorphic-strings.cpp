//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
       if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> mp1;
    unordered_map<char, bool> mp2;

    for (int i = 0; i < s.length(); i++) {
        if (mp1.find(s[i]) == mp1.end()) {
            if (mp2.find(t[i]) != mp2.end() && mp2[t[i]]) {
                return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = true;
        } else {
            if (mp1[s[i]] != t[i]) {
                return false;
            }
        }
    }

    return true;
        
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends