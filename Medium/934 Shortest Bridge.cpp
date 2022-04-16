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
    queue<Point*> q;
    
    vector<int> findAnyLand(vector<vector<int>>& grid)  {
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) return {i,j};
            }
        }
        return {-1,-1};
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        vector<int> hor = {-1,0,1,0};
        vector<int> ver = {0,1,0,-1};
        
        visited[row][col] = 1;
        q.push(new Point(row,col,0));
        
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
        vector<int> pi = findAnyLand(grid);
        dfs(grid, visited, pi[0], pi[1]);
        
        // BFS
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
                
                if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c] == 1) continue;
                if(grid[r][c] == 1) return dist;
                visited[r][c] = 1;
                
                q.push(new Point(r,c,dist+1));
            }
        }
        return 0;
    }
};