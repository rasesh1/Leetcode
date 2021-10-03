class Solution {

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        vector<int> health(cols,0);
        
        // Base Cases
        health[cols-1] = min(0, dungeon[rows-1][cols-1]);
        for(int j=cols-2; j>=0; j--)   {
            health[j] = min(0, health[j+1]+dungeon[rows-1][j]);
        }
        
        for(int i=rows-2; i>=0; i--)   {
            health[cols-1] = min(0, health[cols-1]+dungeon[i][cols-1]);
            
            for(int j=cols-2; j>=0; j--)   {
                health[j] = max(health[j], health[j+1]) + dungeon[i][j];
                health[j] = min(0, health[j]);
            }
        }
        return health[0] > 0 ? 0 : health[0]*-1 + 1;
    }
};