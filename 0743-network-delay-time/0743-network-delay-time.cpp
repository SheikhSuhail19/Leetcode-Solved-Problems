class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times) {
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