//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int findMA(vector<int>& arr){
    int maxi=arr[0];
    int n=arr.size();
    for(int i=1; i<n; i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int func(vector<int>& arr, int h){
    int n=arr.size();
    int totalH=0;
    for(int i=0; i<n; i++){
        totalH += ceil(arr[i] / static_cast<double>(h));
    }
    return totalH;
}

int Solve(int n, vector<int>& arr, int h) {
    int start = 1;
    int end = findMA(arr);
    int ans = INT_MAX;

    while(start <= end){
        int mid = start + (end - start) / 2;
        int totalHour = func(arr, mid);

        if(totalHour <= h){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends