//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<vector<int>> ans(N, vector<int>(N));
    vector<int> v;

    // Store all elements of the matrix in a 1D vector
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v.push_back(Mat[i][j]);
        }
    }

    // Sort the 1D vector in non-decreasing order
    sort(v.begin(), v.end());

    // Fill the sorted elements back into the matrix
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans[i][j] = v[index++];
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
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends