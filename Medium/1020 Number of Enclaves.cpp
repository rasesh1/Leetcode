class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cells = 0;
        queue<pair<int,int>> q;
        
        for(int i=1; i<rows-1; i++)   {
            for(int j=1; j<cols-1; j++)   {
                
                bool closed = false;
                int count = 0;
                if(grid[i][j] == 1) {
                    q.push(make_pair(i,j));
                    grid[i][j] = 0;
                    closed = true;
                }
                
                while(!q.empty())   {
                    pair<int,int> top = q.front();
                    q.pop();
                    
                    int r = top.first;
                    int c = top.second;
                    
                    if(r == 0 || c == 0 || r == rows-1 || c == cols-1) closed = false;
                    
                    count++;
                    
                    if(r-1 >= 0 && grid[r-1][c] == 1) {
                        grid[r-1][c] = 0;
                        q.push(make_pair(r-1,c));
                    }
                    
                    if(r+1 < rows && grid[r+1][c] == 1) {
                        grid[r+1][c] = 0;
                        q.push(make_pair(r+1,c));
                    }
                    
                    if(c+1 < cols && grid[r][c+1] == 1) {
                        grid[r][c+1] = 0;
                        q.push(make_pair(r,c+1));
                    }
                    
                    if(c-1 >= 0 && grid[r][c-1] == 1) {
                        grid[r][c-1] = 0;
                        q.push(make_pair(r,c-1));
                    }
                }
                if(closed)
                    cells = cells + count;
            }
        }
        return cells;
    }
};