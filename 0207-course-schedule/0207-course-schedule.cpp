class Solution {
public:
    
bool dfs(int node, int vis[], vector<int> adj[]) {
        vis[node]++; // Visited
        vis[node]++; // Path Visited
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode,vis,adj)==true)
                    return true;
            }
            else if(vis[adjNode] == 2)
                return true;
        }
        vis[node]--; // Path Visited Finished
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        memset(vis,0,sizeof vis);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i,vis,adj)==true)
                    return true;
            }
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
            for(int i = 0; i < prerequisites.size(); i++) {
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];
                adj[u].push_back(v);
            }
        return !(isCyclic(numCourses,adj));
    }
};