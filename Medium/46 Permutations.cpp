typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    vvi ans;
    void permuteUtil(vi& nums, vi& curr, int index, vi& used) {
        if(curr.size() == nums.size())  {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)    {
            if(!used[i])    {
                curr.push_back(nums[i]);
                used[i]=1;
                permuteUtil(nums, curr, index+1, used);
                used[i]=0;
                curr.pop_back();
            }
        }
        return;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<int> used(n,0);
        permuteUtil(nums, curr, 0, used);
        return ans;
    }
};