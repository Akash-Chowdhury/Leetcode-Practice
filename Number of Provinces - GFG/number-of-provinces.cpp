//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int v, vector<bool>& vis, vector<vector<int>>& adj){
    vis[node] = true;
    vector<int> temp;
    for(int i = 0; i < v; i++){
        int x = adj[node][i];
        if(x == 1){
            temp.push_back(i);
        }
    }
    for(auto x: temp){
        if(!vis[x]){
            dfs(x, v, vis, adj);
        }
    }
}

int numProvinces(vector<vector<int>>& adj, int v) {
    int count = 0;
    vector<bool> vis(v, false);
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            count++;
            dfs(i, v, vis, adj);
        }
    }
    return count;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends