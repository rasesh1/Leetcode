typedef vector<vector<int>> vvi;

class Solution {
private:
    int maxi = 0;
    
    void downToUp(vvi& grid, int soFar, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row < 0 || col < 0) return;
        if(grid[row][col] == -1) return;
        
        int temp = grid[row][col];
        if(grid[row][col] == 1) soFar++;
        grid[row][col]=0;
        
        if(row==0 && col==0)  {
            maxi = max(maxi, soFar);
            grid[row][col] = temp;
            if(grid[row][col] == 1) soFar--;
            return;
        }
        
        downToUp(grid, soFar, row-1, col);
        downToUp(grid, soFar, row, col-1);
        grid[row][col] = temp;
        if(grid[row][col] == 1) soFar--;
        return;
    }
    
    void upToDown(vvi& grid, int soFar, int row, int col)    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row > rows-1 || col > cols-1) return;
        if(grid[row][col] == -1) return;
        
        int temp = grid[row][col];
        if(grid[row][col] == 1) soFar++;
        grid[row][col]=0;
        
        if(row==rows-1 && col==cols-1)  {
            downToUp(grid, soFar, row, col);
            grid[row][col] = temp;
            if(grid[row][col] == 1) soFar--;
            return;
        }
        
        upToDown(grid, soFar, row+1, col);
        upToDown(grid, soFar, row, col+1);
        grid[row][col] = temp;
        if(grid[row][col] == 1) soFar--;
        return;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        upToDown(grid, 0, 0, 0);
        return maxi;
    }
};