class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(rows == 1 && cols == 1) return grid[0][0];
        if(cols == 1) return 0;
        
        int mini = -1, smallest = INT_MAX;
        int secondMini = -1, secondSmallest = INT_MAX;
        
        vector<int> prev(cols,0);
        vector<int> curr(cols,0);
        
        // Base Case
        for(int i=0; i<cols; i++)   {
            prev[i] = grid[0][i];
            if(prev[i] < smallest) {
                secondMini = mini;
                mini = i;
                secondSmallest = smallest;
                smallest = prev[i];
            }
            else if(prev[i] < secondSmallest)  {
                secondMini = i;
                secondSmallest = prev[i];
            }
        }
        
        for(int i=1; i<rows; i++)   {
            
            int mini_new = -1, smallest=INT_MAX;
            int secondMini_new = -1, secondSmallest = INT_MAX;
            
            for(int j=0; j<cols; j++)   {
                if(mini == j)   curr[j] = prev[secondMini] + grid[i][j];
                else curr[j] = prev[mini] + grid[i][j];
                                
                if(curr[j] < smallest)   {
                    secondMini_new = mini_new;
                    mini_new = j;
                    secondSmallest = smallest;
                    smallest = curr[j];
                }
                else if(curr[j] < secondSmallest) {
                    secondMini_new = j;
                    secondSmallest = curr[j];
                }
            }
            
            mini = mini_new;
            secondMini = secondMini_new;
            prev = curr;
        }
        return prev[mini];
    }
};