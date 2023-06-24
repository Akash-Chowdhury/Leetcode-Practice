//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	long long int func(long long int n, long long int m, long long int mid) {
    long long int ans = 1;
    for (long long int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
public:
int NthRoot(long long int n, long long int m) {
    long long int start = 1, end = m;
    while (start <= end) {
        long long int mid = (end + start) / 2;
        long long int root = func(n, m, mid);
        if (root == 1)
            return mid;
        else if (root == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends