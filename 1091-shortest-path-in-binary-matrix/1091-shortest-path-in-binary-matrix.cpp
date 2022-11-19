class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        
        pair<int,int> source = {0,0};
        pair<int, int> destination = {n-1,n-1};
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,source});
        
        int di[8] = {-1,0,+1,0,-1,+1,-1,+1};
        int dj[8] = {0,-1,0,+1,-1,+1,+1,-1};
        
        while(!q.empty()) {
            if(q.front().second == destination) {
                return q.front().first+1;
            }
            
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int k = 0; k < 8; k++) {
                int nrow = row + di[k];
                int ncol = col + dj[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !grid[nrow][ncol]) {
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