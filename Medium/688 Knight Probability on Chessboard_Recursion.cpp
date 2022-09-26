class Solution {
private:
    vector<int> inside;
    vector<int> total;
    
    void backtrack(int n, int row, int col, int movesRemaining)  {
        total[movesRemaining]++;
        if(row < 0 || row >= n || col < 0 || col >= n) return;
        inside[movesRemaining]++;
        
        if(movesRemaining == 0) {
            return;
        }
        
        vector<int> hor_dir = {-2,-1,1,2,2,1,-1,-2};
        vector<int> ver_dir = {1,2,2,1,-1,-2,-2,-1};
        
        for(int k=0; k<8; k++)  {
            int r = row + hor_dir[k];
            int c = col + ver_dir[k];
            
            backtrack(n, r, c, movesRemaining-1);
        }
        return;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        inside.resize(k+1,0);
        total.resize(k+1,0);
        
        backtrack(n, row, column, k);
        
        double ans = 1;
        for(int i=0; i<k; i++)  {
            if(inside[i] == 0) ans = 0;
            ans = ans*inside[i]/total[i];
        }
        
        return ans;
    }
};