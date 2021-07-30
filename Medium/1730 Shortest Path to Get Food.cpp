class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,-1));
        
        vector<int> src = {};
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == '*')
                    src = {i,j};
            }
        }
        
        if(grid[src[0]][src[1]] == '#') return 0;
        
        queue<vector<int>> q;
        q.push(src);
        q.push({-1,-1});
        
        visited[src[0]][src[1]] = 0;
        int dist = 1;
        
        while(!q.empty())   {
            vector<int> front = q.front();
            q.pop();
            
            if(front[0] == -1) {
                if(q.empty()) return -1;
                
                dist++;
                q.push({-1,-1});
                continue;
            }
            
            int i = front[0];
            int j = front[1];
            
            if(i-1 >= 0 && grid[i-1][j] != 'X' && visited[i-1][j] == -1)  {
                q.push({i-1,j});
                if(grid[i-1][j] == '#') return dist;
                visited[i-1][j] = dist;
            }
            
            if(j-1 >= 0 && grid[i][j-1] != 'X' && visited[i][j-1] == -1)  {
                q.push({i,j-1});
                if(grid[i][j-1] == '#') return dist;
                visited[i][j-1] = dist;
            }
            
            if(i+1 < rows && grid[i+1][j] != 'X' && visited[i+1][j] == -1)  {
                q.push({i+1,j});
                if(grid[i+1][j] == '#') return dist;
                visited[i+1][j] = dist;
            }
            
            if(j+1 < cols && grid[i][j+1] != 'X' && visited[i][j+1] == -1)  {
                q.push({i,j+1});
                if(grid[i][j+1] == '#') return dist;
                visited[i][j+1] = dist;
            }
            
        }
        return dist;
    }
};