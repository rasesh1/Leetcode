class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]*nums[0];
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i=1; i<n; i++)
            left[i] = max(left[i-1],0)+nums[i-1];
        
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i+1],0) + nums[i+1];
        
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++)
            maxSum = max(maxSum, nums[i]*nums[i] + max(left[i],0) + max(right[i],0));
        return maxSum;
            
    }
};