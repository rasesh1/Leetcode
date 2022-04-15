class Solution {
private:
    int computeThreshold(vector<int>& nums, int val)    {
        int times = 0;
        for(auto i : nums)  {
            times = times + ceil(1.0*i/val);
        }
        
        return times;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int left = 1, right = nums[n-1];
        int minDivisor = nums[n-1];
        while(left <= right)    {
            if(left == right) return minDivisor;
            
            int mid = left + (right-left)/2;
            int times = computeThreshold(nums, mid);
            if(times > threshold) left = mid+1;
            else    {
                right = mid;
                minDivisor = min(minDivisor, right);
            }
        }
        return minDivisor;
    }
};