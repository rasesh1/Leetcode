class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        
        int i=0;
        int j=0;
        while(i < n && j < n)   {
            j = i+1;
            int currDiff = nums[j]-nums[i];
            int len = 1;
            
            while(j<n && nums[j]-nums[j-1] == currDiff)    {
                len++;
                ans = (len >= 3 ? ans + (len-3+1) : ans);
                j++;
            }
            
            i = j-1;
        }
        return ans;
    }
};