class Solution {
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col)  {
                
        grid2[row][col] = 0;
        
        bool isSub = true;
        vector<int> xs = {-1,0,1,0};
        vector<int> ys = {0,1,0,-1};
        for(int k=0; k<4; k++)  {
            int r = row + xs[k];
            int c = col + ys[k];
            
            if(r >= 0 && c >= 0 && r < grid1.size() && c < grid1[0].size() && grid2[r][c] == 1) {
                grid2[r][c] = 0;
                bool ans = dfs(grid1, grid2, r, c);
                isSub = ans && isSub && grid1[r][c] == 1;
            }
        }
        return isSub;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        
        int subIslands = 0;
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                
                if(grid2[i][j] == 0) continue;
                
                grid2[i][j] = 0;
                bool isSub = dfs(grid1, grid2, i, j) && grid1[i][j] == 1;
                if(isSub) subIslands++;
            }
        }
        return subIslands;
    }
};