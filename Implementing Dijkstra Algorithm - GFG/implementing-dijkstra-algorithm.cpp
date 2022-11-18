//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // WORKS FINE EVEN IF WE USE QUEUE INSTEAD OF PRIORITY QUEUE
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){ 
        vector<int> dist(V);
        for(int i = 0; i < V; i++)
            dist[i] = 1e9;
        dist[S] = 0;
        queue<pair<int,int>> pq;
        pq.push({S,0});
        
        while(!pq.empty()) {
            int node = pq.front().first;
            int weight = pq.front().second;
            pq.pop();
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int adjWeight = it[1];
                // Relaxation
                if(dist[node] + adjWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + adjWeight;
                    pq.push({adjNode,dist[adjNode]});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends