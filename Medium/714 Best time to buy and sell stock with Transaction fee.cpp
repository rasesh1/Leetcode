class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int sell=0;
        int buy = -prices[0];
        
        for(int i=1; i<n; i++)  {
            int preSell = sell;
            
            sell = max(sell, buy+prices[i]-fee);
            buy = max(buy, preSell-prices[i]);
        }
        return sell;
    }
};