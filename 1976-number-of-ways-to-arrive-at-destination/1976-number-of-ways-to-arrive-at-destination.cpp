class Solution {
public:
    long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        vector<long long> ways(n,0);
        ways[0] = 1;
        
        // {cost,node}
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> > q;
        q.push({0,0});
        
        while(!q.empty()) {
            long long cost = q.top().first;
            long long node = q.top().second;
            q.pop();
            
            for(auto it : adj[node]) {
                long long adjNode = it.first;
                long long adjWt = it.second;
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