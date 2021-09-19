class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        res[0] = 1;
        for(int i=1; i<n; i++)
            res[i] = res[i-1]*nums[i-1];
        
        int runningProd = 1;
        for(int i=n-2; i>=0; i--)   {
            runningProd = runningProd*nums[i+1];
            res[i] = res[i]*runningProd;
        }
        return res;
    }
};