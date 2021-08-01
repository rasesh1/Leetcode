class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> rowMap;
        unordered_map<int,int> colMap;
        
        int count=0;
        int row = grid.size();
        int cols = grid[0].size();
        
        for(int i=0; i<row; i++)    {
            for(int j=0; j<cols; j++)    {
                if(grid[i][j] == 1) {
                    
                    if(rowMap.find(i) == rowMap.end())
                        rowMap[i]=0;
                    rowMap[i]++;
                    
                    if(colMap.find(j) == colMap.end())
                        colMap[j]=0;
                    colMap[j]++;
                    
                }
            }
        }
        
        for(int i=0; i<row; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) {
                    if(rowMap[i] > 1 || colMap[j] > 1) count++;
                }
            }
        }
        
        return count;
    }
};