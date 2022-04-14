typedef vector<vector<int>> vvi;

class Solution {
private:
    int rows,cols=0;
    
    void dfs(vvi& heights, vvi& visited, int row, int col)  {
        visited[row][col] = 1;
        
        vector<int> hor = {-1,0,1,0};
        vector<int> ver = {0,1,0,-1};
        for(int k=0; k<4; k++)  {
            int r = row + hor[k];
            int c = col + ver[k];
            
            if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c]==1 || heights[r][c] < heights[row][col]) continue;
            
            dfs(heights,visited,r,c);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        vvi pacific(rows, vector<int>(cols,0));
        vvi atlantic(rows, vector<int>(cols,0));
        
        for(int i=0; i<cols; i++)   {
            if(!pacific[0][i]) dfs(heights, pacific, 0, i);
            if(!atlantic[rows-1][i]) dfs(heights, atlantic, rows-1, i);
        }
        
        for(int i=0; i<rows; i++)   {
            if(!pacific[i][0]) dfs(heights, pacific, i, 0);
            if(!atlantic[i][cols-1]) dfs(heights, atlantic, i, cols-1);
        }
        
        vvi ans;
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
        }
        return ans;
    }
};