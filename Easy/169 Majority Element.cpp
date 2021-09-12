class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int ind=1;
        int curr = nums[0];
        int count=1;
        
        while(ind < n)  {
            if(nums[ind] == curr) count++;
            else count--;
            
            ind++;
            
            if(count == 0)  {
                curr = nums[ind];
                count=1;
                ind++;
            }
        }
        
        return curr;
    }
};