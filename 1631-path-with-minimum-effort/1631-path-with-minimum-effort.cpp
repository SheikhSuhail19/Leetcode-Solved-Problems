class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        q.push({0,{0,0}});
        
        int di[4] = {-1,0,+1,0};
        int dj[4] = {0,+1,0,-1};
        
        while(!q.empty()) {
            int eff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            if(row == n-1 && col == m-1)
                return eff;
                
            for(int k = 0; k < 4; k++) {
                int nrow = row + di[k];
                int ncol = col + dj[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), eff);
                    if(newEffort < effort[nrow][ncol]) {
                        effort[nrow][ncol] = newEffort;
                        q.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0; 
    }
};