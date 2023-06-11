//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        bool isfind(string text, string pat,int idx){
            int n=text.length();
            int m=pat.length();
            for(int i=0; i<m; i++){
                if(idx>n) return false;
                if(text[idx++]!=pat[i]){
                    return false;
                }
            }
            return true;
        }
        vector <int> search(string pat, string text)
        {
            //code hee.
            int n=text.length();
            int m=pat.length();
            vector<int>ans;
            for(int i=0; i<n; i++){
                if(text[i]==pat[0]){
                    if(isfind(text,pat,i)){
                        ans.push_back(i+1);
                    }
                }
            }return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends