class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int left=0, right=n-1;
        while(left <= right)    {
            if(left == right)   {
                return nums[left];
            }
            else if(right-left == 1)    {
                if(nums[left] != nums[max(0,left-1)] && nums[left] != nums[min(n-1,left+1)]) return left;
                return right;
            }
            
            int mid = left + (right-left)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            
            else if(nums[mid] == nums[mid+1])   {
                if( (mid-left)%2 == 1 ) right = mid-1;
                else left = mid+2;
            }
            
            else    {
                if( (mid-left)%2 == 1 ) left = mid+1;
                else right = mid-2;
            }
        }
        return left;
    }
};