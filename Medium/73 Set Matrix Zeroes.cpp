class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        unordered_set<int> r;
        unordered_set<int> c;
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(matrix[i][j] == 0)   {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        
        unordered_set<int>::iterator iter;
        for(iter = r.begin(); iter != r.end(); ++iter)  {
            int row = *iter;
            for(int j=0; j<cols; j++)
                matrix[row][j] = 0;
        }
        
        for(iter = c.begin(); iter != c.end(); ++iter)  {
            int col = *iter;
            for(int j=0; j<rows; j++)
                matrix[j][col] = 0;
        }
        
        return;
    }
};