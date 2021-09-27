typedef vector<vector<int>> vvi;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vvi A(rows, vector<int>(cols, 0));
        int maxi = 0;
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(matrix[i][j] == '0') {
                    A[i][j] = 0;
                    continue;
                }
                
                int num1 = (i>0 && j>0) ? A[i-1][j-1] : 0;
                int num2 = (i>0) ? A[i-1][j] : 0;
                int num3 = (j>0) ? A[i][j-1] : 0;
                
                A[i][j] = 1 + min(num1, min(num2,num3));
                maxi = max(maxi, A[i][j]);
            }
        }
        return maxi*maxi;
    }
};