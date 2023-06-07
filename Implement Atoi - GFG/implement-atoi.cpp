//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
   int atoi(string s) {
    //Your code here
    int n = s.length();
    int i = 0;
    int num = 0;
    int sign=1;
    if(s[0]=='-'){
        sign=-1;
        i++;
    }
    
    while (i < n) {  // Fix: Use i as the loop condition, not n
        int a = s[i] - '0';
        
        if (a < 0 || a > 9)  // Fix: Use logical OR (||) instead of logical AND (&&)
            return -1;
        
        num = (num * 10) + a;
        i++;  // Fix: Increment i to avoid an infinite loop
    }
    
    return num*sign;
}

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends