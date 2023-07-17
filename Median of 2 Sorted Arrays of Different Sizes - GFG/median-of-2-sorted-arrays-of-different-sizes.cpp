//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    double MedianOfArrays(vector<int>& x, vector<int>& y) {
        int l1 = x.size();
        int l2 = y.size();
        if (l1 > l2) {
            return MedianOfArrays(y, x);
        }
        int start = 0, end = l1;
        while (start <= end) {
            int midX = (start + end) / 2;
            int midY = (l1 + l2 + 1) / 2 - midX;

            double maxLeftX = (midX == 0) ? INT_MIN : x[midX - 1];
            double minRightX = (midX == l1) ? INT_MAX : x[midX];

            double maxLeftY = (midY == 0) ? INT_MIN : y[midY - 1];
            double minRightY = (midY == l2) ? INT_MAX : y[midY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((l1 + l2) % 2 == 0) {
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }
                else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) {
                end = midX - 1;
            }
            else {
                start = midX + 1;
            }
        }
        return 0.0;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends