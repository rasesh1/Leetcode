class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int count = matrix[0][0];
        vector<vector<int>> A(rows, vector<int>(cols,0));
        
        A[0][0] = matrix[0][0];
        // First Row
        for(int i=1; i<cols; i++)   {
            A[0][i] = matrix[0][i];
            if(A[0][i]) count++;
        }
        
        // First Column
        for(int i=1; i<rows; i++)   {
            A[i][0] = matrix[i][0];
            if(A[i][0]) count++;
        }
        
        for(int i=1; i<rows; i++)   {
            for(int j=1; j<cols; j++)   {
                
                if(matrix[i][j] == 1)   {
                    A[i][j] = 1 + min(min(A[i-1][j-1], A[i-1][j]), A[i][j-1]);
                    count = count+A[i][j];
                }
                
            }
        }
        return count;
    }
};