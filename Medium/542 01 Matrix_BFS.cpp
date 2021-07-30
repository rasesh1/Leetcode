typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;

class Solution {
private:
    queue<pi> q;
    
    void bfs(vvi& visited, vvi& mat)    {
        
        while(!q.empty())   {
            pi top = q.front();
            q.pop();
            
            int i = top.first;
            int j = top.second;
            
            if(i-1 >= 0 && visited[i-1][j] == -1 && mat[i-1][j] == 1)    {
                visited[i-1][j] = 1 + visited[i][j];
                q.push(make_pair(i-1,j));
            }
            
            if(i+1 < mat.size() && visited[i+1][j] == -1 && mat[i+1][j] == 1)    {
                visited[i+1][j] = 1 + visited[i][j];
                q.push(make_pair(i+1,j));
            }
            
            if(j+1 < mat[0].size() && visited[i][j+1] == -1 && mat[i][j+1] == 1)    {
                visited[i][j+1] = 1 + visited[i][j];
                q.push(make_pair(i,j+1));
            }
            
            if(j-1 >= 0 && visited[i][j-1] == -1 && mat[i][j-1] == 1)    {
                visited[i][j-1] = 1 + visited[i][j];
                q.push(make_pair(i,j-1));
            }
        }
        return;
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vvi visited(rows, vector<int>(cols,-1));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(mat[i][j] == 0)  {
                    visited[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        bfs(visited,mat);
        
        return visited;
    }
};