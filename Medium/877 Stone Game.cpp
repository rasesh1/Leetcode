class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        if(n <= 2) return true;
        
        vector<vector<int>> A(n, vector<int>(n,0));
        
        A[n-1][n-1] = piles[n-1];
        
        // Base Cases
        for(int i=0; i+1<n; i++)  {
            A[i][i] = piles[i];
            A[i][i+1] = max(piles[i], piles[i+1]);
        }
        
        // DP
        for(int delta=2; delta<n; delta++)  {
            for(int i=0; i+delta<n; i++)  {
                
                int x = i;
                int y = i+delta;
                
                int num1 = piles[x] + min(A[x+1][y-1], A[x+2][y]);
                int num2 = piles[y] + min(A[x+1][y-1], A[x][y-2]);
                
                A[x][y] = max(num1, num2);
            }
        }
        
        long long int sum=0;
        for(auto p : piles)
            sum = sum + p;
        
        return A[0][n-1] > sum/2 ? true : false;
    }
};