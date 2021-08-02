class Solution {
private:
    int MOD = 1000000007;
    long long int nck(int n, int k)    {
        if(k > n) return 0;
        if(k == 0 || k == n) return 1;
        
        long long int C[n + 1][k + 1];
        int i, j;

        // Calculate value of Binomial Coefficient
        // in bottom up manner
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= min(i, k); j++) {
                // Base Cases
                if (j == 0 || j == i)
                    C[i][j] = 1;

                // Calculate value using previously stored values
                else
                    C[i][j] = (C[i - 1][j - 1]%MOD + C[i - 1][j]%MOD)%MOD;
            }
        }
        return C[n][k];
    }
    
    long long int numOfWaysUil(vector<int>& nums)    {
        int n = nums.size();
        long long int ways=0;
        if(n <= 2)  {
            return 1;
        }
        
        vector<int> larger;
        vector<int> smaller;
            
        for(int j=1; j<nums.size(); j++)  {
            if(nums[j] > nums[0]) larger.push_back(nums[j]);
            else smaller.push_back(nums[j]);
        }
            
        long long int l = numOfWaysUil(larger);
        long long int s = numOfWaysUil(smaller);
        
        long long int choose = nck(larger.size()+smaller.size(),larger.size())%MOD;
        long long int mult = ((l%MOD)*(s%MOD))%MOD;
            
        ways = (mult*choose)%MOD;
        return ways;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;
         
        return numOfWaysUil(nums)-1;
    }
};