class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> positive(n,1);
        vector<int> negative(n,1);
        
        int maxLen = 1;
        
        // Base Case
        for(int i=1; i<n; i++)  {
            for(int j=i-1; j>=0; j--)   {
                if(nums[j] < nums[i])   {
                    positive[i] = max(positive[i],1 + negative[j]);
                    maxLen = max(maxLen, positive[i]);
                }
                else if(nums[j] > nums[i])  {
                    negative[i] = max(negative[i],1 + positive[j]);
                    maxLen = max(maxLen, negative[i]);
                }
            }
        }
        return maxLen;
    }
};