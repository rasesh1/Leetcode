class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n <= 3) return 0;
        
        int mini = nums[n-4]-nums[0];
        for(int i=1; i<=3; i++) {
            mini = min(mini, nums[n-4+i]-nums[i]);
        }
        
        return mini;
    }
};