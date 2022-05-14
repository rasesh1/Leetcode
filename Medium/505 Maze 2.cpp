typedef vector<int> vi;

class Solution {
private:
    vector<vector<int>> left, right, topW, down;
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        left.resize(rows, vector<int>(cols,-1));
        right.resize(rows, vector<int>(cols, cols));
        topW.resize(rows, vector<int>(cols,-1));
        down.resize(rows, vector<int>(cols,rows));
        
        // Wall on left side
        for(int i=0; i<rows; i++)   {
            int prevWall = -1;
            for(int j=0; j<cols; j++)   {
                if(maze[i][j] == 1) prevWall = j;
                else left[i][j] = prevWall;
            }
        }
        
        // Wall on right side
        for(int i=0; i<rows; i++)   {
            int prevWall = cols;
            for(int j=cols-1; j>=0; j--)   {
                if(maze[i][j] == 1) prevWall = j;
                else right[i][j] = prevWall;
            }
        }
        
        // Wall on top
        for(int j=0; j<cols; j++)   {
            int prevWall = -1;
            for(int i=0; i<rows; i++)   {
                if(maze[i][j] == 1) prevWall = i;
                else topW[i][j] = prevWall;
            }
        }
        
        // Wall on bottom
        for(int j=0; j<cols; j++)   {
            int prevWall = rows;
            for(int i=rows-1; i>=0; i--)   {
                if(maze[i][j] == 1) prevWall = i;
                else down[i][j] = prevWall;
            }
        }
        
        priority_queue<vi, vector<vi>, greater<vi>> q;
        q.push({0, start[0], start[1]});
        
        while(!q.empty())   {
            vector<int> top = q.top(); q.pop();
            int row = top[1];
            int col = top[2];
            int moves = top[0];
            
            if(row == destination[0] && col == destination[1]) return moves;
            
            if(visited[row][col] == 1) continue;
            visited[row][col] = 1;
            
            // Left side
            int leftSide = left[row][col]+1;
            if(!visited[row][leftSide]) {
                q.push({moves+col-leftSide, row, leftSide});
            }
            
            // Right side
            int rightSide = right[row][col]-1;
            if(!visited[row][rightSide]) {
                q.push({moves+rightSide-col, row, rightSide});
            }
            
            // Top
            int topSide = topW[row][col]+1;
            if(!visited[topSide][col]) {
                q.push({moves+row-topSide, topSide, col});
            }
            
            // Bottom
            int bottomSide = down[row][col]-1;
            if(!visited[bottomSide][col]) {
                q.push({moves+bottomSide-row, bottomSide, col});
            }
        }
        return -1;
    }
};