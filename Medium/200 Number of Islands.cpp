class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c)    {
        visited[r][c] = 1;
        
        vector<int> xs = {0,1,0,-1};
        vector<int> ys = {1,0,-1,0};
        
        for(int k=0; k<4; k++)  {
            int x = r + xs[k];
            int y = c + ys[k];
            
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == '1' && !visited[x][y]) {
                dfs(grid,visited,x,y);
            }
        }
        return;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        int islands = 0;
        
        for(int i=0; i<m; i++)  {
            for(int j=0; j<n; j++)  {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return islands;
    }
};