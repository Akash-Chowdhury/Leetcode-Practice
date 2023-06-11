//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void find(int i, int j, vector<vector<int>> &m, int n, vector<string>&ans, vector<vector<int>> &vis, string move){
        // base case
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        // move :- D L R U 
        
        // down move
        if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i][j]=1;
            find(i+1,j,m,n,ans,vis,move+'D');
            vis[i][j]=0;
        }
        
        // left move
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j]=1;
            find(i,j-1,m,n,ans,vis,move+'L');
            vis[i][j]=0;
        }
        
        // right move
        if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j]=1;
            find(i,j+1,m,n,ans,vis,move+'R');
            vis[i][j]=0;
        }
        
        //UP move
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i][j]=1;
            find(i-1,j,m,n,ans,vis,move+'U');
            vis[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &M, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(M[0][0]==1){
            find(0,0,M,n,ans,vis,"");
           
        } return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends