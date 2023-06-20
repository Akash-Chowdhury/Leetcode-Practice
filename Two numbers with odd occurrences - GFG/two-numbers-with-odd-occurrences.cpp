//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int nums[], long long int n)  
    {
        // code here
        vector<long long int>ans;
        int XOR=nums[0];
        for(int i=1; i<n; i++){
            XOR=XOR^nums[i];
        }
        int right_bit=XOR & ~(XOR-1);
        int x,y;
        x=y=0;
        for(int i=0; i<n; i++){
            if(nums[i] & right_bit){
                x=x^nums[i];
            }else{
                y=y^nums[i];
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends