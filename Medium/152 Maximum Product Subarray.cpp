class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int maxSoFar = nums[0], minSoFar = nums[0];
        int result = nums[0];
        for(int i=1; i<n; i++)  {
            int temp = max(max(maxSoFar*nums[i], minSoFar*nums[i]), nums[i]);
            minSoFar = min(min(maxSoFar*nums[i], minSoFar*nums[i]), nums[i]);
            maxSoFar = temp;
            result = max(result, max(maxSoFar, minSoFar));
        }
        
        return result;
    }
};