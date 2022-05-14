class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int MOD = 1000000007;
        int n = nums.size();
        int even = 0;
        int odd = 0;

        if(nums[0]%2 == 1) odd++;
        else even++;

        int count = odd;

        for(int i=1; i<n; i++)	{
            if(nums[i]%2 == 0)	{
                odd = odd;
                even = 1 + even;
            }
            else	{
                int temp = odd;
                odd = 1 + even;
                even = temp;
                
            }
            odd = odd%MOD;
            even = even%MOD;
            count = (count + odd)%MOD;
        }
        return count;
    }
};