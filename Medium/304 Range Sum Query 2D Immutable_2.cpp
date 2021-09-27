typedef vector<vector<int>> vvi;

class NumMatrix {
private:
    vvi sums;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        sums.resize(rows);
        
        for(int i=0; i<rows; i++)   {
            int currSum = 0;
            sums[i].push_back(0);
            for(int j=0; j<cols; j++)   {
                currSum = currSum + matrix[i][j];
                sums[i].push_back(currSum);
            }
        }
        
        for(int j=0; j<=cols; j++)   {
            for(int i=1; i<rows; i++)   {
                sums[i][j] = sums[i][j] + sums[i-1][j];
            }
        } 
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int num1 = sums[row2][col2+1];
        int num2 = row1-1>=0 ? sums[row1-1][col2+1] : 0;
        int num3 = sums[row2][col1];
        int num4 = ( row1-1>=0 ? sums[row1-1][col1] : 0);
        return num1-num2-num3+num4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */