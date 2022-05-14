typedef vector<int> vi;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        int maxDiff = 0;
        while(!pq.empty())  {
            vi top = pq.top(); pq.pop();
            int diff = top[0];
            int row = top[1];
            int col = top[2];
            
            if(visited[row][col] == 1) continue;
            
            visited[row][col] = 1;
            maxDiff = max(maxDiff, diff);
            
            if(row == rows-1 && col == cols-1) return maxDiff;
            
            vector<int> row_dir = {-1,0,1,0};
            vector<int> col_dir = {0,1,0,-1};
            
            for(int k=0; k<4; k++)  {
                int r = row + row_dir[k];
                int c = col + col_dir[k];
                
                if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c]) continue;
                
                pq.push({abs(heights[row][col] - heights[r][c]), r, c});
            }
        }
        return maxDiff;
    }
};