//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfsForFinishTime(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfsForFinishTime(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    
    void dfsToFindSCC(int node, vector<int>& vis, vector<int> adjT[]) {
        vis[node] = 1;
        for(auto it : adjT[node]) {
            if(!vis[it]) {
                dfsToFindSCC(it,vis,adjT);
            }
        }
    }
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]) {
        
        // STEP 1: DFS & put the nodes in stack (Sorting all the edges according to finish time)
        
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfsForFinishTime(i,vis,adj,st);
            }
        }
        
        // STEP 2: Reverse all the edges of the graph
        
        vector<int> adjT[V];
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        
        // STEP 3: Do a DFS to find the SCC
        
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfsToFindSCC(node,vis,adjT);
            }
        }
        
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends