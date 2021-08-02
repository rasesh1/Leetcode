typedef vector<vector<int>> vvi;

class Solution {
private:
    vector<int> xs = {-1,0,1,0};
    vector<int> ys = {0,1,0,-1};
    
    bool dfs(vvi& visited, vvi& grid, int a, int b)   {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(a == 0 || a == rows-1 || b == 0 || b == cols-1) return false;
        visited[a][b] = 1;
        
        bool isValid = true;
        for(int i=0; i<4; i++)  {
            int x = a + xs[i];
            int y = b + ys[i];
            
            if(x>=0 && x<rows && y>=0 && y<cols && !visited[x][y] && grid[x][y] == 0)  {
                isValid = dfs(visited, grid, x, y) && isValid;
            }
        }
        
        return isValid;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        for(int i=1; i<rows-1; i++)   {
            for(int j=1; j<=cols-1; j++)   {
                
                if(!visited[i][j] && grid[i][j] == 0)  {
                    if(dfs(visited,grid, i, j))
                        count++;
                }
                
            }
        }
        return count;
    }
};