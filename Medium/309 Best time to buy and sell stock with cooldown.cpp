class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> sell(n, 0);
        vector<int> buy(n, 0);
        buy[0] = -prices[0];
        
        int cooldown=0;
                
        for(int i=1; i<n; i++)  {
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
            buy[i] = max(cooldown-prices[i], buy[i-1]);
            cooldown = sell[i-1];
        }
        
        return max(sell[n-1], buy[n-1]);
    }
};