typedef vector<vector<int>> vvi;

class NumMatrix {
private:
    vvi sums;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        sums.resize(rows);
        for(int i=0; i<rows; i++)
            sums[i].resize(cols+1);
        
        for(int i=0; i<rows; i++)   {
            int currSum = 0;
            sums[i][0] = 0;
            for(int j=0; j<cols; j++)   {
                currSum = currSum + matrix[i][j];
                sums[i][j+1] = currSum;
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        for(int i=row1; i<=row2; i++)   {
            ans = ans + sums[i][col2+1] - sums[i][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */