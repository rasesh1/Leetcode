typedef vector<vector<int>> vvi;

class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        if(rows == 0) return mat;
        
        vvi dist(rows, vector<int>(cols,INT_MAX-1000));
        
        for(int i=0; i<rows; i++)  { 
            for(int j=0; j<cols; j++)   {
                if(mat[i][j] == 0)  {
                    dist[i][j] = 0;
                }
                else    {
                    if(i-1 >= 0)
                        dist[i][j] = min(dist[i-1][j]+1, dist[i][j]);
                    if(j-1 >= 0)
                        dist[i][j] = min(dist[i][j-1]+1, dist[i][j]);
                }
            }
        }
        
        for(int i=rows-1; i>=0; i--)   {
            for(int j=cols-1; j>=0; j--)   {
                
                if(i+1 < rows)
                    dist[i][j] = min(dist[i+1][j]+1, dist[i][j]);
                if(j+1 < cols)
                    dist[i][j] = min(dist[i][j+1]+1, dist[i][j]);
            }
        }
        return dist;
    }
};