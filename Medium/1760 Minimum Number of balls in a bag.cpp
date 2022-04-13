class Solution {
private:
    int operationsRequired(vector<int>& nums, int penalty)  {
        int ops = 0;
        for(auto i : nums)  {
            if(i > penalty) {
                ops = ops + (i-1)/penalty;
            }
        }
        return ops;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minPenalty = INT_MAX;
        
        int left = 1, right = nums[n-1];
        while(left <= right)    {
            int penalty = left + (right-left)/2;
            int operations = operationsRequired(nums, penalty);
            
            if(operations <= maxOperations) {
                minPenalty = penalty;
                right = penalty-1;
            }
            else
                left = penalty+1;
        }
        return minPenalty;
    }
};