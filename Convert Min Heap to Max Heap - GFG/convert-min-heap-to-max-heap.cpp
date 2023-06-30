//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  void heapify(vector<int> &a, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[largest]){
        largest = l;
    }

    if(r < n && a[r] > a[largest]){
        largest = r;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void convertMinToMaxHeap(vector<int> &a, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
}

    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends