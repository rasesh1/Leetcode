typedef vector<vector<int>> vvi;

class Solution {

private:
    int rows=0, cols=0;
    map<vector<int>, int> visited;
    
    int shortestPathUtil(vvi& grid, int k)  {
        queue<vector<int>> q;
        q.push({0,0,k});
        if(rows == 1 && cols == 1) return 0;
        
        visited[{0,0,k}] = 1;
        while(!q.empty())   {
            vector<int> row = {0,1,0,-1};
            vector<int> col = {1, 0, -1, 0};
            
            vector<int> top = q.front();
            q.pop();
            int r = top[0], c = top[1], remain_k=top[2];
            if(r == rows-1 && c == cols-1) return visited[{r,c,remain_k}];
            
            for(int i=0; i<4; i++)  {
                int x = r + row[i];
                int y = c + col[i];
                
                if(x == rows-1 && y == cols-1) return visited[{r,c,remain_k}];
                
                if(x>=0 && y>=0 && x<rows && y<cols)  {
                    if(grid[x][y] == 1 && remain_k-1>=0 && !visited[{x,y,remain_k-1}]) {
                        visited[{x,y,remain_k-1}] = 1+visited[{r,c,remain_k}];
                        q.push({x,y,remain_k-1});
                    }
                    else if(grid[x][y] == 0 && remain_k >= 0 && !visited[{x,y,remain_k}])   {
                        visited[{x,y,remain_k}] = 1+visited[{r,c,remain_k}];
                        q.push({x,y,remain_k});
                    }
                }
            }
        }
        return -1;
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        
        int ans = shortestPathUtil(grid, k);
        return ans;
    }
};