//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>>& matrix, int R, int C) {
    vector<int> elements;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            elements.push_back(matrix[i][j]);
        }
    }
    
    sort(elements.begin(), elements.end());
    
    int size = elements.size();
    int mid = size / 2;
    return elements[mid];
}

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends