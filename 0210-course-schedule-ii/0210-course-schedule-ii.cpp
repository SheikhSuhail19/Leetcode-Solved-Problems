class Solution{
    public:

    vector<int> findOrder(int numCourses, vector<vector < int>> &prerequisites){
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        int V = numCourses;
        int indegree[V];
        memset(indegree,0,sizeof indegree);
        for (int i = 0; i < V; i++){
            for (auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> schedule;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            schedule.push_back(node);
            for (auto it: adj[node]){
                indegree[it]--;
                if (indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(schedule.size() != V)
            return {};
        return schedule;
    }
};