//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int target )
{
    // code here
        int i, j, mid;
        i = 0;
        j = n - 1;
        int leftIndex = -1, rightIndex = -1;

        while(i <= j){
            mid = (i + j)/2;
            if(nums[mid] > target){
                j = mid - 1;
            } else if (nums[mid] < target){
                i = mid + 1;
            } else {
                leftIndex = mid;
                j = mid - 1;
            }
        }

        i = 0; j = n - 1;
        while(i <= j){
            mid = (i + j)/2;
            if(nums[mid] > target){
                j = mid - 1;
            } else if (nums[mid] < target){
                i = mid + 1;
            } else {
                rightIndex = mid;
                i = mid + 1;
            }
        }

        vector<int> ans;
        ans.push_back(leftIndex);
        ans.push_back(rightIndex);

        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends