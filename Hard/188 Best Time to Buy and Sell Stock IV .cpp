class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if(days == 0) return 0;
        vector<vector<int>> A(k+1, vector<int>(days,0));
        
        for(int i=1; i<=k; i++) {
            int maxDiff = -prices[0];
            
            for(int j=1; j<days; j++)  {
                A[i][j] = max(A[i][j-1], maxDiff+prices[j]);
                maxDiff = max(maxDiff, A[i-1][j]-prices[j]);
            }
        }
        return A[k][days-1];
    }
};