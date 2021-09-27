typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    int uniquePathsIIIUtil(vvi& grid, vvi& visited, vi& start, int walkable, int currLength)  {
        if(grid[start[0]][start[1]] == -1) return 0;
        if(walkable == currLength && grid[start[0]][start[1]] == 2) return 1;
        
        vector<int> row = {0,1,0,-1};
        vector<int> col = {1,0,-1,0};
        
        visited[start[0]][start[1]] = 1;
        
        int ways = 0;
        for(int i=0; i<4; i++)  {
            int x = start[0]+row[i];
            int y = start[1]+col[i];
                        
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !visited[x][y]) {
                visited[x][y] = 1;
                vector<int> point = {x,y};
                ways = ways + uniquePathsIIIUtil(grid,visited,point, walkable, currLength+1);
                visited[x][y] = 0;
            }
        }
        return ways;
    }
    
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Find start and ending points
        int walkable = 1;
        vector<int> start = {0,0};
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) start = {i,j};
                else if(grid[i][j] != -1) walkable++;
            }
        }
        
        vvi visited(rows, vector<int>(cols,0));
        visited[start[0]][start[1]] = 1;
        int ans = uniquePathsIIIUtil(grid, visited, start, walkable, 1);
        return ans;
    }
};