class Solution {
private:
    bool isSame(vector<vector<int>>& grid, int row)   {
        int cols = grid[row].size();
        for(int i=0; i<cols; i++)   {
            if(grid[row][i] != grid[0][i]) return false;
        }
        return true;
    }
    
    bool isFlipped(vector<vector<int>>& grid, int row)   {
        int cols = grid[row].size();
        for(int i=0; i<cols; i++)   {
            if(grid[row][i] == grid[0][i]) return false;
        }
        return true;
    }
    
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i=1; i<rows; i++)   {
            if(!isSame(grid,i) && !isFlipped(grid,i))
                return false;
        }
        return true;
    }
};