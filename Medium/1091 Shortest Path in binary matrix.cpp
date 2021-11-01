typedef pair<int,int> pi;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pi> q;
        int dist = 1;
        
        if(grid[0][0] == 1) return -1;
        if(n==1) return dist;
        
        q.push(make_pair(0,0));
        q.push(make_pair(-1,-1));
        
        grid[0][0] = 1;
        
        while(!q.empty())   {
            pi top = q.front(); q.pop();
            
            if(top.first == -1)    {
                if(q.front().first == -1 || q.empty()) return -1;
                
                dist++;
                q.push(make_pair(-1,-1));
                continue;
            }
            
            vector<int> xs = {0,1,1,1,0,-1,-1,-1};
            vector<int> ys = {1,1,0,-1,-1,-1,0,1};
            
            for(int k=0; k<8; k++)  {
                int r = top.first + xs[k];
                int c = top.second + ys[k];
                
                if(r >=0 && c>=0 &&r<n && c<n && grid[r][c] == 0)   {
                    q.push(make_pair(r,c));
                    grid[r][c] = 1;
                    if(r == n-1 && c==n-1) return dist+1;
                }
            }
        }
        return -1;
    }
};