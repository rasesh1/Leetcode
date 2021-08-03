class Solution {
private:
    map<vector<int>,int> present;
    vector<vector<int>> ans;
    
    void combinationUtil(vector<int>& curr, vector<int>& nums, int start)    {
        
        if(start == nums.size())    {
            return;
        }
        
        for(int i=start; i<nums.size(); i++)    {
            
            curr.push_back(nums[i]);
            if(present.find(curr) == present.end())  {
                ans.push_back(curr);
                present[curr] = 1;
            }
            combinationUtil(curr, nums, i+1);
            curr.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> curr;
        ans.push_back({});
        combinationUtil(curr, nums, 0);
        return ans;
    }
};