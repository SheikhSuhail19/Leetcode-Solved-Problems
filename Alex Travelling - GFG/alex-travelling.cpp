//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flight, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : flight) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n+1,1e9);
        dist[0] = 0;
        dist[k] = 0;
        
        // {time,node}
        queue<pair<int,int>> q;
        q.push({0,k});
        
        while(!q.empty()) {
            int node = q.front().second;
            int cost = q.front().first;
            q.pop();
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjCost = it.second;
                
                if(cost + adjCost < dist[adjNode]) {
                    dist[adjNode] = cost + adjCost;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = *max_element(dist.begin(),dist.end());
        if(ans == 1e9)
            return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> flight;
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int i = 0; i < 3; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flight.push_back(temp);
        }

        Solution ob;
        cout << ob.minimumCost(flight, N, K) << "\n";
    }
}

// } Driver Code Ends