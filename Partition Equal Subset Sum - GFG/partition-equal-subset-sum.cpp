//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subsetSum(int arr[], int n, int w, vector<vector<bool>>& dp)
{
    if (w == 0)
        return true;
    if (n == 0)
        return false;
    if (dp[n][w] != false)
        return dp[n][w];

    if (arr[n - 1] > w)
        return dp[n][w] = subsetSum(arr, n - 1, w, dp);

    return dp[n][w] = subsetSum(arr, n - 1, w - arr[n - 1], dp) || subsetSum(arr, n - 1, w, dp);
}

bool solve(int arr[], int n, int w)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
    return subsetSum(arr, n, w, dp);
}

bool equalPartition(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;
    else {
        return solve(arr, n, sum / 2);
    }
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends