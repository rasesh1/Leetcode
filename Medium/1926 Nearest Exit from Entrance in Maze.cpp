class Solution {
private:
    typedef vector<vector<char>> vvc;
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    
    bool isExit(vvc& maze, vi top)  {
        
        if(top[0] == 0 || top[0] == maze.size()-1 || top[1] == 0 || top[1] == maze[0].size()-1)
            return true;
        return false;
    }
    
    int bfs(vvc& maze, vi src, vvi& visited)   {
        int x = src[0];
        int y = src[1];
        
        queue<vi> q;
        int level = 0;
        q.push(src);
        visited[x][y] = level;
        q.push({-1,-1});
        level++;
        while(!q.empty())   {
            vi top = q.front();
            q.pop();
            
            x = top[0];
            y = top[1];
            
            if(top[0] == -1 && top[1] == -1)    {
                if(q.empty()) return -1;
                
                q.push({-1,-1});
                level++;
                continue;
            }
            
            //UP
            if(x-1>=0 && visited[x-1][y] == -1 && maze[x-1][y] == '.')  {
                if(isExit(maze, {x-1,y}))
                    return level;
                q.push({x-1,y});
                visited[x-1][y] = level;
            }
            
            //DOWN
            if(x+1<maze.size() && visited[x+1][y] == -1 && maze[x+1][y] == '.')  {
                if(isExit(maze, {x+1,y}))
                    return level;
                
                q.push({x+1,y});
                visited[x+1][y] = level;
            }
            
            //LEFT
            if(y-1>=0 && visited[x][y-1] == -1 && maze[x][y-1] == '.')  {
                if(isExit(maze, {x,y-1}))
                    return level;
                
                q.push({x,y-1});
                visited[x][y-1] = level;
            }
            
            //RIGHT
            if(y+1<maze[0].size() && visited[x][y+1] == -1)  {
                if(maze[x][y+1] == '.') {
                    if(isExit(maze, {x,y+1}))
                        return level;
                    
                    q.push({x,y+1});
                    visited[x][y+1] = level;
                }
            }
        }
        return -1;
    }
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vvi visited(maze.size(), vector<int>(maze[0].size(), -1));
        
        return bfs(maze, entrance, visited);
        
    }
};