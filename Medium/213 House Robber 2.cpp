class Solution {
private:
    int Rob(vector<int> & nums, int start, int end) {
        int n = nums.size()-1;
        int A[n+1];
        A[0] = 0; A[1] = nums[start];
        
        for(int i=2; i<=n; i++) {
            A[i] = max(A[i-1], A[i-2]+nums[i-1+start]);
        }
        return A[n];
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int num1 = Rob(nums, 0, n-2);
        int num2 = Rob(nums, 1, n-1);
        
        return max(num1, num2);
    }
};