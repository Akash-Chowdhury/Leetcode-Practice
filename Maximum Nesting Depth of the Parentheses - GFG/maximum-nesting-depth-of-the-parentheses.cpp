//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int count=0;
        int itr=0;
       for(int i=0; i<s.length(); i++){
           if(s[i]=='('){
               itr++;
               count=max(count,itr);
           }
           else{
               if(s[i]==')')itr--;
           }
       }
       if(itr==0){
           return count;
       }
       return -1;

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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends