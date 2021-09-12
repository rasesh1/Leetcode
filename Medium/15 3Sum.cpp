class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n <= 2) return ans;
        
        sort(nums.begin(), nums.end());        
        
        for(int i=0; i<n-1; i++)  {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j=i+1;
            int k=n-1;
            
            while(j < k && k < n)   {
                bool updateK = false;
                bool updateJ = false;
                
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0) updateK = true;
                
                else if(sum < 0)    updateJ = true;

                else    {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    updateK = true;
                    updateJ = true;
                }
                if(updateJ) {
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                
                if(updateK) {
                    k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
            }
        }
        
        return ans;
    }
};