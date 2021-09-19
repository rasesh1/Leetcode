class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int currSum = nums[0];
        
        for(int i=1; i<n; i++)  {
            currSum = max(nums[i], currSum+nums[i]);
            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};