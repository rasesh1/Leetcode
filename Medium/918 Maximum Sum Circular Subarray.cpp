class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int curr_max = nums[0];
        int max_so_far = nums[0];
        
        int curr_min = nums[0];
        int min_so_far = nums[0];
        
        int cumulativeSum = nums[0];
        
        for(int i=1; i<n; i++)  {
            curr_max = max(nums[i], curr_max+nums[i]);
            max_so_far = max(max_so_far, curr_max);
            
            curr_min = min(nums[i], curr_min+nums[i]);
            min_so_far = min(min_so_far, curr_min);
            
            cumulativeSum = cumulativeSum + nums[i];
        }
        
        if(min_so_far == cumulativeSum) return max_so_far;
        
        return max(max_so_far, cumulativeSum-min_so_far);
    }
};