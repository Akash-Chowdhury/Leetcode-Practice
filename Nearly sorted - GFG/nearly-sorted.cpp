//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int a[], int n, int k){
        // Your code here
        priority_queue<int, vector<int>, greater<int>>q;
        vector<int>v;
        for(int i=0; i<n; i++){
            q.push(a[i]);
            if(q.size()>k){
                v.push_back(q.top());
                q.pop();
            }
        }
        while(q.size()!=0){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends