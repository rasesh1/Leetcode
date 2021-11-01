class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int left=0, right=n-1;
        while(left <= right)    {
            if(left == right) return nums[left];
            
            if(right-left == 1) return nums[left] < nums[right] ? nums[left] : nums[right];
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) return nums[mid];
            
            else if(nums[mid] > nums[n-1]) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};