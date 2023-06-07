//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
   long long toh(int n, int f, int d, int h) { // f = starting disk, d = destination disk, h = helper disk
    long long c = 0;
    if (n == 1) {
        c++;
        cout << "move disk 1 from rod " << f << " to rod " << d << endl;
        return c;
    }
    
    c += toh(n - 1, f, h, d);
    cout << "move disk " << n << " from rod " << f << " to rod " << d << endl;
    c++;
    c += toh(n - 1, h, d, f);
    
    return c;
}

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends