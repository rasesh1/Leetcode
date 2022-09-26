class Solution {
private:
    vector<vector<int>> ans;
    unordered_map<int,int> freq;
    
    void backtrack(int sumSoFar, int target, vector<int>& nums, unordered_map<int,int>::iterator& iter_start)  {
        if(sumSoFar == target)  {
            ans.push_back(nums);
            return;
        }
        else if(sumSoFar > target) return;
        
        unordered_map<int,int>::iterator iter = iter_start;
        
        for(iter = iter_start; iter != freq.end(); ++iter)    {
            if(iter->second == 0) continue;
            
            int key = iter->first;
            int val = iter->second;
            
            freq[key]--;
            nums.push_back(key);
            backtrack(sumSoFar+key, target, nums, iter);
            freq[key]++;
            nums.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        for(auto c : candidates)    {
            if(freq.find(c) == freq.end()) freq[c] = 0;
            freq[c]++;
        }
        unordered_map<int,int>::iterator iter = freq.begin();
        int sumSoFar = 0;
        vector<int> nums;
        backtrack(sumSoFar, target, nums, iter);
        return ans;
    }
};