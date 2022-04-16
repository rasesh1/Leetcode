class Point {
public:
    int row;
    int col;
    int dist;
    
    Point(int r, int c, int d)  {
        row = r;
        col = c;
        dist = d;
        return;
    }
};

class Solution {
private:
    int rows, cols;
    
    pair<int,int> findAnyLand(vector<vector<int>>& grid)    {
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) return make_pair(i,j);
            }
        }
        return make_pair(-1,-1);
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        vector<int> hor = {-1,0,1,0};
        vector<int> ver = {0,1,0,-1};
        
        visited[row][col] = 1;
        
        for(int k=0; k<4; k++)  {
            int r = row + hor[k];
            int c = col + ver[k];
            
            if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c] || grid[r][c] == 0) continue;
            
            dfs(grid,visited,r,c);
        }
        return;
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        pair<int,int> pi = findAnyLand(grid);
        dfs(grid, visited, pi.first, pi.second);
        
        // BFS
        queue<Point*> q;
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(!visited[i][j] && grid[i][j] == 1)   {
                    q.push(new Point(i,j,0));
                    visited[i][j] = 2;
                }    
            }
        }
    
        while(!q.empty())   {
            Point* top = q.front(); q.pop();
            int row = top->row;
            int col = top->col;
            int dist = top->dist;
            
            vector<int> hor = {-1,0,1,0};
            vector<int> ver = {0,1,0,-1};
            
            for(int k=0; k<4; k++)  {
                int r = row + hor[k];
                int c = col + ver[k];
                
                if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c] == 2) continue;
                if(visited[r][c] == 1) return dist;
                
                q.push(new Point(r,c,dist+1));
            }
        }
        return 0;
    }
};