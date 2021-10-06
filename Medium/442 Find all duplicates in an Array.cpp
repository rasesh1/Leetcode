class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        
        for(auto num : nums)  {
            int val = abs(num);
            nums[val-1] = abs(nums[val-1])*-1;
        }
        
        for(auto num : nums)  {
            int val = abs(num);
            if(nums[val-1] > 0) ans.push_back(val);
            nums[val-1] = -1*nums[val-1];
        }
        return ans;
    }
};