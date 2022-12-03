//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
    vector<int> parent, rank, size;
    
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)
            return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)
            return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    int di[4] = {-1,0,0,+1};
    int dj[4] = {0,-1,+1,0};
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        // Step 1: Separate Components
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    continue;
                for(int k = 0; k < 4; k++) {
                    int nr = i + di[k];
                    int nc = j + dj[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int nodeNum = i * n + j;
                        int adjNodeNum = nr * n + nc;
                        ds.unionBySize(nodeNum,adjNodeNum);
                    }
                }
            }
        }
        
        int ans = 0;
        
        
        // Step 2: Try to combine components
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    continue;
                unordered_set<int> components;
                for(int k = 0; k < 4; k++) {
                    int nr = i + di[k];
                    int nc = j + dj[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.findUPar(nr*n+nc));
                    }
                }
                int sum = 0;
                for(auto it : components) {
                    sum += ds.size[it];
                }
                ans = max(ans,sum+1);
            }
        }
        
        for(int cell = 0; cell < n*n; cell++) {
            ans = max(ans,ds.size[ds.findUPar(cell)]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends