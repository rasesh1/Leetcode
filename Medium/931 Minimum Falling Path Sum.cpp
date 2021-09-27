class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> curr(cols,0);
        vector<int> prev(cols,0);
        
        // First Row
        
        for(int i=0; i<cols; i++) prev[i] = matrix[0][i];
        
        int mini = matrix[0][0];
        for(int i=1; i<rows; i++)   {
            
            mini = INT_MAX;
            for(int j=0; j<cols; j++)   {
                curr[j] = matrix[i][j] + min({prev[j], prev[max(0,j-1)], prev[min(j+1,cols-1)]});
                mini = min(mini, curr[j]);
            }
            prev = curr;
            
        }
        return mini;
    }
};