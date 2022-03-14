class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> A(n,1);
        int curr = nums[0];
        int maxi = 1;
        
        for(int i=1; i<n; i++)  {
            if(nums[i] == 1)    {
                curr++;
                A[i] = curr;
            }
            else if(curr > 0)    {
                A[i] = 1 + A[i-1];
                curr = 0;
            }
            maxi = max(maxi, A[i]);
        }
        
        curr = nums[n-1];
        for(int i=n-2; i>=0; i--)   {
            if(nums[i] == 1)    {
                curr++;
                A[i] = curr;
            }
            else if(curr > 0)    {
                A[i] = A[i] + A[i+1];
                maxi = max(maxi, A[i]);
                curr = 0;
            }
        }
        return maxi;
    }
};