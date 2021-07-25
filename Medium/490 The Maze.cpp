class Solution {
private:
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest, vector<vector<int>>& visited)  {
        int x = start[0];
        int y = start[1];
        
        visited[x][y] = 1;
        
        if(start[0] == dest[0] && start[1] == dest[1]) return true;
        
        // UP
        int i=x;
        while(i > 0 && maze[i-1][y] == 0)
            i--;
        if(visited[i][y] != 1)    {
            vector<int> temp = {i,y};
            bool b = dfs(maze, temp, dest, visited);
            if(b == true) return true;
        }
        
        // DOWN
        i=x;
        while(i < maze.size()-1 && maze[i+1][y] == 0)
            i++;
        if(visited[i][y] != 1)    {
            vector<int> temp = {i,y};
            bool b = dfs(maze, temp, dest, visited);
            if(b == true) return true;
        }
            
        
        // LEFT
        i=y;
        while(i > 0 && maze[x][i-1] == 0)
            i--;
        if(visited[x][i] != 1)    {
            vector<int> temp = {x,i};
            bool b = dfs(maze, temp, dest, visited);
            if(b == true) return true;
        }
        
        // RIGHT
        i=y;
        while(i < maze[0].size()-1 && maze[x][i+1] == 0)
            i++;
        if(visited[x][i] != 1)    {
            vector<int> temp = {x,i};
            bool b = dfs(maze, temp, dest, visited);
            if(b == true) return true;
        }
        return false;
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> visited = maze;
        
        return dfs(maze, start, destination, visited);
    }
};