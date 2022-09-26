class Solution {
private:
    int recurse(int row, int c1, int c2, vector<vector<int>>& grid, map<vector<int>,int>& mp)  {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row >= rows || c1 >= cols || c1<0 || c2<0 || c2>=cols)   {
            return INT_MIN;
        }
        
        if(mp.find({row,c1,c2}) != mp.end())    {
            return mp[{row,c1,c2}];
        }
        
        int cc1 = grid[row][c1];
        int cc2 = grid[row][c2];
        
        int cherries = cc1+cc2;
        if(c1 == c2)    {
            cherries = cc1;
        }
        
        if(row == rows-1)   {
            mp[{rows-1,c1,c2}] = cherries;
            return mp[{rows-1,c1,c2}];
        }
        
        int f1 = recurse(row+1, c1-1, c2-1, grid, mp);
        int f2 = recurse(row+1, c1-1, c2, grid, mp);
        int f3 = recurse(row+1, c1-1, c2+1, grid, mp);
        int f4 = recurse(row+1, c1, c2-1, grid, mp);
        int f5 = recurse(row+1, c1, c2, grid, mp);
        int f6 = recurse(row+1, c1, c2+1, grid, mp);
        int f7 = recurse(row+1, c1+1, c2-1, grid, mp);
        int f8 = recurse(row+1, c1+1, c2, grid, mp);
        int f9 = recurse(row+1, c1+1, c2+1, grid, mp);
        
        mp[{row,c1,c2}] = cherries + max(f1, max(f2, max(f3, max(f4, max(f5, max(f6, max(f7, max(f8,f9))))))));
        return mp[{row,c1,c2}];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        return recurse(0,0,cols-1,grid,mp);
    }
};