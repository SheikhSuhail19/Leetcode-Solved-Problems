class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> adjRev[V];
        int indegree[V];
        memset(indegree,0,sizeof indegree);
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};