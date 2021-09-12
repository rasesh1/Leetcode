class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int A[n+1];
        A[0]=0; A[1]=nums[0];
        
        for(int i=2; i<=n; i++)
            A[i] = max(A[i-2]+nums[i-1], A[i-1]);

        return A[n];
    }
};