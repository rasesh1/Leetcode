class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        int minSoFar = prices[0];
        int maxProfit = 0;
        
        for(auto i : prices)    {
            minSoFar = min(minSoFar, i);
            maxProfit = max(maxProfit, i-minSoFar);
        }
        return maxProfit;
    }
};