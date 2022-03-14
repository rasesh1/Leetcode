typedef vector<vector<int>> vvi;

class Solution {
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        int islands = 0;
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                
                queue<pair<int,int>> q;
                bool isSub = false;
                if(grid2[i][j] == 1)    {
                    grid2[i][j] = 0;
                    q.push(make_pair(i,j));
                    if(grid1[i][j] == 1) isSub = true;
                }
                
                while(!q.empty())  {
                    pair<int,int> top = q.front();
                    q.pop();
                    
                    int r = top.first;
                    int c = top.second;
                    
                    if(r-1 >= 0 && grid2[r-1][c] == 1)    {
                        grid2[r-1][c] = 0;
                        q.push(make_pair(r-1,c));
                        if(grid1[r-1][c] != 1) isSub = false;
                    }
                    
                    if(r+1 < rows && grid2[r+1][c] == 1)    {
                        grid2[r+1][c] = 0;
                        q.push(make_pair(r+1,c));
                        if(grid1[r+1][c] != 1) isSub = false;
                    }
                    
                    if(c+1 < cols && grid2[r][c+1] == 1)    {
                        grid2[r][c+1] = 0;
                        q.push(make_pair(r,c+1));
                        if(grid1[r][c+1] != 1) isSub = false;
                    }
                    
                    if(c-1 >= 0 && grid2[r][c-1] == 1)    {
                        grid2[r][c-1] = 0;
                        q.push(make_pair(r,c-1));
                        if(grid1[r][c-1] != 1) isSub = false;
                    }
                }
                if(isSub) islands++;
            }
        }
        return islands;
    }
};