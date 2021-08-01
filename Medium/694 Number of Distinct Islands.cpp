typedef vector<vector<int>> vvi;

class Solution {
private:
    unordered_set<string> paths;
    string dfs(vvi& visited, vvi& grid, int x, int y)  {
        string ans = "";
        
        vector<int> xs = {-1,0,1,0};
        vector<int> ys = {0,1,0,-1};
        
        for(int k=0; k<4; k++)  {
            int i = x + xs[k];
            int j = y + ys[k];
            
            if(i >= 0 && j >= 0 && i < grid.size() && j<grid[0].size() && !visited[i][j] && grid[i][j] ==1 )   {
                visited[i][j] = 1;
                ans = ans + 'L' + dfs(visited, grid, i, j);
            }
            else ans = ans + '0';
        }
        
        return ans;
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int count = 0;
        
        vvi visited(rows, vector<int>(cols,0));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1 && !visited[i][j])   {
                    visited[i][j] = 1;
                    string path = dfs(visited, grid, i, j);
                    
                    if(paths.find(path) == paths.end()) {
                        paths.insert(path);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};