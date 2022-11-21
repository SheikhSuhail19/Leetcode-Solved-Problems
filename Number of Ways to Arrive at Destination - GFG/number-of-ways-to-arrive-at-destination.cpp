//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        vector<int> dist(n,1e9);
        dist[0] = 0;
        vector<int> ways(n,0);
        ways[0] = 1;
        
        // {cost,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,0});
        
        while(!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;
                if(cost + adjWt < dist[adjNode]) {
                    dist[adjNode] = cost + adjWt;
                    ways[adjNode] = ways[node];
                    q.push({dist[adjNode],adjNode});
                }
                else if(cost + adjWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends