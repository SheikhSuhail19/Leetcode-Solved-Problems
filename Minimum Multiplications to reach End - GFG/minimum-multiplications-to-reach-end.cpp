//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int mod = 100000;
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(mod,-1);
        dist[start] = 0;
        
        // {steps,result after multiplication}
        queue<pair<int,int>> q;
        q.push({0,start%mod});
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end)
                return steps;
            
            for(auto it : arr){
                int newNode = (it*node)%mod;
                if(dist[newNode] == -1){
                    q.push({steps+1,newNode});
                    dist[newNode] = steps+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends