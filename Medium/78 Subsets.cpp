typedef vector<vector<int>> vvi;

class Solution {
private:
    vvi ans;
    
    void subsetsUtil(vector<int>& nums, vector<int>& curr, int index)   {
        if(index == nums.size())    {
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[index]);
        subsetsUtil(nums, curr, index+1);
        
        curr.pop_back();
        subsetsUtil(nums, curr, index+1);
        return;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        subsetsUtil(nums, curr, 0);
        return ans;
    }
};