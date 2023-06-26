//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int minEle(vector<int> &arr) {
    int minM = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        minM = min(minM, arr[i]);
    }
    return minM;
}

int maxEle(vector<int> &arr) {
    int maxM = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxM = max(maxM, arr[i]);
    }
    return maxM;
}

bool possible(vector<int> &arr, int m, int k, int day) {
    int count = 0, noOfBloom = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day)
            count++;
        else {
            noOfBloom += count / k;
            count = 0;
        }
    }
    noOfBloom += count / k;
    return (noOfBloom >= m);
}

int solve(int M, int K, vector<int> &bloomDay) {
    long long val=M*1LL*K*1LL;
    if(val>bloomDay.size()) return -1;
   long long int low = minEle(bloomDay), high = maxEle(bloomDay), ans = -1;

    while (low <= high) {
        long long int mid = low + (high - low) / 2;
        if (possible(bloomDay, M, K, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends