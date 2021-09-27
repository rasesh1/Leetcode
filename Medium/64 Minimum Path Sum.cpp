class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int A[rows][cols];
        
        // Base Cases
        A[0][0] = grid[0][0];
        for(int i=1; i<rows; i++) A[i][0] = A[i-1][0] + grid[i][0];
        for(int i=1; i<cols; i++) A[0][i] = A[0][i-1] + grid[0][i];
        
        for(int i=1; i<rows; i++)   {
            for(int j=1; j<cols; j++)   {
                A[i][j] = grid[i][j] + min(A[i-1][j], A[i][j-1]);
            }
        }
        return A[rows-1][cols-1];
    }
};