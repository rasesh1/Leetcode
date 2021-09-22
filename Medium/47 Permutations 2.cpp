typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    vvi ans;
    unordered_map<int,int> mp;
    
    void permuteUniqueUtil(vi& nums, vi& curr, int index) {
        if(index == nums.size())    {
            ans.push_back(curr);
            return;
        }
        
        unordered_map<int,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); ++iter)    {
            if(iter->second == 0) continue;
            
            int num = iter->first;
            curr.push_back(num);
            mp[num]--;
            
            permuteUniqueUtil(nums, curr, index+1);
            
            curr.pop_back();
            mp[num]++;
        }
        return;
    }
    
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        for(auto i : nums)  {
            if(mp.find(i) == mp.end()) mp[i]=0;
            mp[i]++;
        }
        
        vector<int> curr;
        permuteUniqueUtil(nums, curr, 0);
        return ans;
    }
};