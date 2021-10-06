class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> xs = {-1,0,1,0};
        vector<int> ys = {0,1,0,-1};
        
        int peri = 0;
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                
                if(grid[i][j] == 1) {
                    peri = peri + 4;
                    for(int k=0; k<4; k++)  {
                        int x = i + xs[k];
                        int y = j + ys[k];
                        
                        if(x >= 0 && y >= 0 && x<rows && y<cols && grid[x][y] == 1) peri--;
                    }
                }
                
            }
        }
        return peri;
    }
};