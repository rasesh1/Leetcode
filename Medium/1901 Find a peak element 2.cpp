class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int i=0, j=0;
        
        while(i < rows && j < cols) {
            int curr = mat[i][j];
            
            int up = -1;
            if(i-1 >= 0) up = mat[i-1][j];
            if(up > curr)   {
                i--;
                continue;
            }
            
            int right = -1;
            if(j+1 < cols) right = mat[i][j+1];
            if(right > curr)   {
                j++;
                continue;
            }
            
            int left = -1;
            if(j-1 >= 0) left = mat[i][j-1];
            if(left > curr)   {
                j--;
                continue;
            }
            
            int down = -1;
            if(i+1 < rows) down = mat[i+1][j];
            if(down > curr)   {
                i++;
                continue;
            }
            
            return {i,j};
        }
        
        return {-1,-1};
    }
};