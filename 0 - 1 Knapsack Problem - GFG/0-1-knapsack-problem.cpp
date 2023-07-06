//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int wt[], int val[], int w, int n, int dp[][1001]){
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+solve(wt,val,w-wt[n-1],n-1,dp),
        solve(wt,val,w,n-1,dp));
    }
    else if(wt[n-1]>w){
        return dp[n][w]=solve(wt,val,w,n-1,dp);
    }
}

int knapSack(int w, int wt[], int val[], int n) {
    int dp[n+1][1001];
    memset(dp, -1, sizeof(dp));
    return solve(wt, val, w, n, dp);
}

};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends