//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> minheap;
        int i = 0;
        for(; i < k-1; i++) {
            minheap.push(arr[i]);
            ans.push_back(-1);
        }
        minheap.push(arr[i++]);
        ans.push_back(minheap.top());
        for(; i < n; i++) {
            if(arr[i] > minheap.top()) {
                minheap.pop();
                minheap.push(arr[i]);
            }
            ans.push_back(minheap.top());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends