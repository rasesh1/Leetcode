typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    int rows, cols;
    int dfs(vvi& matrix, vvi& visited, int row, int col)   {
        
        vector<int> hor = {-1,0,1,0};
        vector<int> ver = {0,1,0,-1};
        int lengthSoFar = 1;
        
        for(int k=0; k<4; k++)  {
            int r = row + hor[k];
            int c = col + ver[k];
            
            if(r<0 || c<0 || r>=rows || c>=cols || matrix[r][c] <= matrix[row][col]) continue;
            if(!visited[r][c])   {
                visited[r][c] = dfs(matrix, visited, r, c);
            }
            lengthSoFar = max(1+visited[r][c], lengthSoFar);
        }
        return lengthSoFar;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        int maxPath = 0;
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(!visited[i][j])  {
                    visited[i][j] = dfs(matrix, visited, i, j);
                    maxPath = max(maxPath, visited[i][j]);
                }
            }
        }
        return maxPath;
    }
};