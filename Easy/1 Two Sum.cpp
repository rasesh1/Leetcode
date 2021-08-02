class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++)    {
            int remain = target-nums[i];
            if(mp.find(nums[i]) != mp.end()) {
                return {mp[nums[i]], i};
            }
            mp[remain] = i;
        }
        return {-1,-1};
    }
};