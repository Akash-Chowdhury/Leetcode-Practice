//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int c, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(), arr.end());
        int start=0, end=arr[n-1],mid, ans=0;
        while(start<=end){
            int count=1, left=0;
            mid=start+(end-start)/2;
            for(int i=0; i<n; i++){
                if(arr[i]-arr[left]>=mid){
                    left=i;
                    count++;
                }
            }
            if(count>=c){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends