typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef unordered_map<int,int> umii;

class Solution {
private:
    vvi ans;
    unordered_map<int,int> mp;
    
    void subsetsWithDupUtil(vi& nums, vi& curr, unordered_map<int,int>::iterator iter)  {
        ans.push_back(curr);
        
        unordered_map<int,int>::iterator iter_;
        for(iter_ = iter; iter_ != mp.end(); ++iter_)  {
            if(iter_->second == 0) continue;
            int num = iter_->first;
            
            mp[num]--;
            curr.push_back(num);
            
            subsetsWithDupUtil(nums, curr, iter_);
            
            curr.pop_back();
            mp[num]++;
        }
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        for(auto i : nums)  {
            if(mp.find(i) == mp.end()) mp[i]=0;
            mp[i]++;
        }
        
        unordered_map<int,int>::iterator iter = mp.begin();
        vector<int> curr;
        subsetsWithDupUtil(nums, curr, iter);
        return ans;
    }
};