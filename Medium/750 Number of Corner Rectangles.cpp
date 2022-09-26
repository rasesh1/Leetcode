class Solution {
private:
    int findNumberOfCommonCols(vector<int>& v1, vector<int>& v2)    {
        int n1 = v1.size();
        int n2 = v2.size();
        
        int i=0, j=0;
        int ans = 0;
        while(i < n1 && j < n2)   {
            if(v1[i] == v2[j])  {
                ans++;
                i++;
                j++;
            }
            else if(v1[i] < v2[j]) i++;
            else j++;
        }
        return ans;
    }
    
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> row_ones(rows, vector<int>({}));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) {
                    row_ones[i].push_back(j);
                }
            }
        }
        
        // FInd Common Ones Between Rows
        int ans = 0;
        for(int i=0; i<rows; i++)   {
            for(int j=i+1; j<rows; j++)   {
                int commonCols = findNumberOfCommonCols(row_ones[i], row_ones[j]);
                ans = ans + commonCols*(commonCols-1)/2;
            }
        }
        return ans;
    }
};