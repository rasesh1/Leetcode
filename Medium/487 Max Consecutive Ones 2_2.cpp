class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int left=0, right=0;
        int lastZero = -1;
        int maxi = 1;
        
        while(left<n && right < n)    {
            if(nums[right] == 1)    {
                maxi = max(maxi, right-left+1);
                right++;
            }
            else if(lastZero == -1) {
                lastZero = right;
                maxi = max(maxi, right-left+1);
                right++;
            }
            else    {
                left = lastZero+1;
                lastZero = -1;
            }
        }
        return maxi;
    }
};