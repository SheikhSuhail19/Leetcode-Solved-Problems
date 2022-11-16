class Solution {
public:
    
    bool dfs(int node, int vis[], int pathVis[], int check[], vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode,vis,pathVis,check,adj)==true) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[adjNode]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        int vis[V];
		int pathVis[V];
		int check[V];
        memset(vis,0,sizeof vis);
        memset(pathVis,0,sizeof pathVis);
        memset(check,0,sizeof check);
		vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i,vis,pathVis,check,adj);
            }
        }
        for (int i = 0; i < V; i++) {
			if (check[i] == 1)
			    safeNodes.push_back(i);
		}
		return safeNodes;
    }
};