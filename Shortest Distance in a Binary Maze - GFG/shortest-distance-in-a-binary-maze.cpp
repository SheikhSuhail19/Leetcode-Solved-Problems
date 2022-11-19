//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,source});
        
        int di[4] = {-1,0,+1,0};
        int dj[4] = {0,-1,0,+1};
        
        while(!q.empty()) {
            if(q.front().second == destination) {
                return q.front().first;
            }
            
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nrow = row + di[k];
                int ncol = col + dj[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]) {
                    if(distance + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = distance + 1;
                        q.push({dist[nrow][ncol], {nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends