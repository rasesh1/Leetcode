typedef vector<int> vi;
class Solution {
public:
    vector<int> xs = {-1,0,1,0};
    vector<int> ys = {0,1,0,-1};
    
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        int maxSoFar = grid[0][0];
        
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,0,0});
        visited[0][0] = 1;
        
        while(!pq.empty())  {
            vector<int> top = pq.top();
            pq.pop();
            
            int val = top[0];
            int x = top[1];
            int y = top[2];
            
            maxSoFar = max(maxSoFar, grid[x][y]);
            if(x == rows-1 && y == cols-1) return maxSoFar;
            
            for(int i=0; i<4; i++)  {
                int a = x + xs[i];
                int b = y + ys[i];
                
                if(a>=0 && b>=0 && a<rows && b<cols && visited[a][b] == 0) {
                    pq.push({grid[a][b], a, b});
                    visited[a][b] = 1;
                }
            }
        }
        return maxSoFar;
    }
};