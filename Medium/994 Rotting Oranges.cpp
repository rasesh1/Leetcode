typedef pair<int,int> pi;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        unordered_set<int> s;
        
        queue<pi> q;
        int minutes = 0;
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 2) q.push(make_pair(i,j));
                else if(grid[i][j] == 1) s.insert(i*cols+j);
            }
        }
        
        q.push(make_pair(-1,-1));
        
        while(!q.empty())   {
            pi top = q.front();
            q.pop();
            
            if(top.first == -1) {
                if(q.empty()) break;
                minutes++;
                q.push(make_pair(-1,-1));
                continue;
            }
            
            vector<int> xs = {0,1,0,-1};
            vector<int> ys = {1,0,-1,0};
            
            for(int k=0; k<4; k++)  {
                int r = top.first + xs[k];
                int c = top.second + ys[k];
                
                if(r >= 0 && c>=0 && r<rows && c<cols && grid[r][c] == 1)   {
                    grid[r][c] = 2;
                    s.erase(r*cols+c);
                    q.push(make_pair(r,c));
                }
            }
        }
        return s.empty() ? minutes : -1;
    }
};