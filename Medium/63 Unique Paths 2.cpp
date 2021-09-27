class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(grid[0][0] == 1) return 0;
        
        int A[rows][cols];
        A[0][0] = 1;
        for(int i=1; i<rows; i++)   {
            if(grid[i][0] == 1) A[i][0]=0;
            else A[i][0] = A[i-1][0];
        }
        
        for(int i=1; i<cols; i++)   {
            if(grid[0][i] == 1) A[0][i]=0;
            else A[0][i] = A[0][i-1];
        }
        
        for(int i=1; i<rows; i++)   {
            for(int j=1; j<cols; j++)   {
                if(grid[i][j] == 1) A[i][j] = 0;
                else A[i][j] = A[i-1][j] + A[i][j-1];
            }
        }
        
        return A[rows-1][cols-1];
    }
};